#include "QtImageNode.hpp"

//#define THE_DEBUG

namespace sstd {

    namespace this_private {

        class ImageShader;
        class ImageMaterial final : public QSGMaterial {
        public:
            /*比较两个Material*/
            inline int compare(const QSGMaterial *other) const override;
        protected:
            /* 用于分类 */
            inline QSGMaterialType *type() const override {
                static QSGMaterialType globalAns;
                return &globalAns;
            }
            /* 创建Shader */
            inline QSGMaterialShader *createShader() const override;
        public:
            GLuint * getTextureQImage() {
                return &thisQImageTexture;
            }
            const GLuint * getTextureQImage() const {
                return &thisQImageTexture;
            }
            void updateToQImage(const QImage & arg) {
                thisMarkImageForceToUpdate = true;
                thisImage = arg;
            }
            inline ImageMaterial() {
#if defined(_DEBUG)
                thisImage = QImage{ 1,1,QImage::Format_RGB888 };
                thisImage.fill(QColor(1, 255, 1, 255));
#endif
            }
        private:
            GLuint thisQImageTexture{ 0 };
            QImage thisImage;
            bool thisMarkImageForceToUpdate{ true };
            friend class ImageShader;
        private:
            sstd_class(ImageMaterial);
        };

        class ImageShader final : public QSGMaterialShader {
        public:

            /* 片段着色器 */
            inline const char * fragmentShader() const override {
                return u8R"--------(
#version 460

in vec2 qt_TexCoord;

layout(location = 0) uniform sampler2D qt_Texture;
layout(location = 2) uniform float qt_Opacity    ;
out vec4 fragColor                               ;

void main() {
    fragColor = texture2D(qt_Texture, qt_TexCoord) * qt_Opacity;
}

/* Src/qtdeclarative/src/quick/scenegraph/shaders/opaquetexture.frag */
)--------";

            }

            /* 顶点着色器 */
            inline const char * vertexShader() const override {
                return  u8R"--------(
#version 460

layout(location = 1) uniform mat4 qt_Matrix   ;
layout(location = 0) in vec4 qt_VertexPosition;
layout(location = 1) in vec2 qt_VertexTexCoord;

out vec2 qt_TexCoord;

void main() {
    qt_TexCoord = qt_VertexTexCoord;
    gl_Position = qt_Matrix * qt_VertexPosition;
}
/* Src/qtdeclarative/src/quick/scenegraph/shaders/opaquetexture.vert */
)--------";
            }

            /* 顶点着色器输入 */
            inline char const *const *attributeNames() const override {
                static const char *const globalAns[]{
                    "qt_VertexPosition"/*顶点*/,
                    "qt_VertexTexCoord"/*纹理坐标*/,
                    nullptr
                };
                return globalAns;
            }

            /* 每次绘制之前更新状态 */
            inline void updateState(
                const RenderState &state,
                QSGMaterial *,
                QSGMaterial *) override {
                constructThisGL();
                /* this->program ()->bind () ;  */
                this->program()->setUniformValue(1, state.combinedMatrix());
                this->program ()->setUniformValue(2,state.opacity());
                USING_SSTD_GLEW;
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, thisImageMaterial->thisQImageTexture);
            }

            /* 初始化资源 */
            inline void activate() override {
                constructThisGL();
            }

            /* 释放资源 */
            inline void deactivate() override {
            }

            inline ImageShader(ImageMaterial * arg) :
                thisImageMaterial{ arg } {
            }

            inline ~ImageShader() {
                this->destoryThisGL();
            }

        private:
            inline void constructThisGL() {
                if ((thisImageMaterial->thisMarkImageForceToUpdate) ||
                    (thisImageMaterial->thisQImageTexture == 0)) {
#if defined(THE_DEBUG)
                    qDebug()
                        << "image update : "
                        << thisImageMaterial->thisImage.width()
                        << thisImageMaterial->thisImage.height();
#endif
                    thisImageMaterial->thisMarkImageForceToUpdate = false;
                    sstd::opengl_utility::updateTexture(&(thisImageMaterial->thisQImageTexture),
                        thisImageMaterial->thisImage);
                }

            }

            inline void destoryThisGL() {
#if defined(THE_DEBUG)
                qDebug() << "destory the texture ... ";
#endif
                glDeleteTextures(1, &(thisImageMaterial->thisQImageTexture));
                thisImageMaterial->thisQImageTexture = 0;
            }

        private:
            ImageMaterial * const thisImageMaterial;
        private:
            sstd_class(ImageShader);
        };

        inline QSGMaterialShader *ImageMaterial::createShader() const {
            return sstd_new< ImageShader >(const_cast<ImageMaterial *>(this));
        }

        inline int ImageMaterial::compare(const QSGMaterial *other) const {
            auto varOther = static_cast<const ImageMaterial *>(other);
            return static_cast<GLint>(this->thisQImageTexture) -
                static_cast<GLint>(varOther->thisQImageTexture);
        }

        class ImageGeometry : public QSGGeometry {
            using Super = QSGGeometry;
        public:

            inline ImageGeometry() :Super{ QSGGeometry::defaultAttributes_TexturedPoint2D() , 4 } {
                updateSize(QSizeF{ 1,1 });
                {/*固定值*/
                    using Point2D = QSGGeometry::TexturedPoint2D;
                    auto varData = static_cast<Point2D *>(this->vertexData());
                    auto & varData0 = varData[0];
                    auto & varData1 = varData[1];
                    auto & varData2 = varData[2];
                    auto & varData3 = varData[3];
                    varData0.tx = 0; varData0.ty = 0;
                    varData1.tx = 0; varData1.ty = 1;
                    varData2.tx = 1; varData2.ty = 0;
                    varData3.tx = 1; varData3.ty = 1;
                }
                this->setDrawingMode(QSGGeometry::DrawTriangleStrip);
            }

            inline void updateSize(const QSizeF & arg) {
                using Point2D = QSGGeometry::TexturedPoint2D;
                auto varData = static_cast<Point2D *>(this->vertexData());
                auto & varData0 = varData[0];
                auto & varData1 = varData[1];
                auto & varData2 = varData[2];
                auto & varData3 = varData[3];
                varData0.x = 0; varData0.y = 0;
                varData1.x = 0; varData1.y = arg.height();
                varData2.x = arg.width(); varData2.y = 0;
                varData3.x = arg.width(); varData3.y = arg.height();
            }

        private:
            sstd_class(ImageGeometry);
        };

    }/*namespace this_private*/

    QtImageNodeWrap::QtImageNodeWrap() {

        /* 设置顶点着色器和片段着色器 */
        auto varMaterial = sstd_new<this_private::ImageMaterial>();
        this->setMaterial(varMaterial);
        this->setFlag(QSGNode::OwnsMaterial, true);

        /* 设置顶点数据 */
        auto *varGeometry = sstd_new<this_private::ImageGeometry>();
        this->setGeometry(varGeometry);
        this->setFlag(QSGNode::OwnsGeometry);

    }

    QtImageNode::QtImageNode(std::shared_ptr<QtImageNodeData> arg) :thisData{ std::move(arg) } {
        thisDrawImage = sstd_new<QtImageNodeWrap>();
        {
            this->appendChildNode(thisDrawImage);
            thisDrawImage->setFlag(OwnedByParent);
        }
        this->setFlag(OwnedByParent);
    }

    void QtImageNodeWrap::updateImage(const QImage & arg) {
        auto varMaterial = static_cast<this_private::ImageMaterial *>(this->material());
        varMaterial->updateToQImage(arg);
        this->markDirty(DirtyMaterial);
    }

    void QtImageNodeWrap::updateImageSize(const QSizeF & arg) {
        auto varGeometry = static_cast<this_private::ImageGeometry *>(this->geometry());
        varGeometry->updateSize(arg);
        this->markDirty(DirtyGeometry);
    }

    bool QtImageNodeData::setMatrix(const QMatrix4x4 & arg) {
        if (arg == thisMatrix) {
            return false;
        }
        thisMatrix = arg;
        thisFlags.set<ImageNodeDataState::ImageMatrixChanged>();
        return true;
    }

    bool QtImageNodeData::setImage(QImage arg) {
        thisImage = std::move(arg);
        thisImage.convertTo(sstd::opengl_utility::defaultQImageFormat());
        thisFlags.set<ImageNodeDataState::ImageChanged>();
        return true;
    }

    bool QtImageNodeData::setImageSize(const QSizeF & arg) {
        if (arg == thisImageSize) {
            return false;
        }
        thisImageSize = arg;
        thisFlags.set<ImageNodeDataState::ImageSizeChanged>();
        return true;
    }

    void QtImageNodeData::clearAllChange() {
        thisFlags.clearAll();
    }

    void QtImageNode::updateTheNode() {

        if (thisData->testChanged<ImageNodeDataState::ImageChanged>()) {
            thisDrawImage->updateImage(thisData->getImage());
        }

        if (thisData->testChanged<ImageNodeDataState::ImageSizeChanged>()) {
            thisDrawImage->updateImageSize(thisData->getImageSize());
        }

        if (thisData->testChanged<ImageNodeDataState::ImageMatrixChanged>()) {
            this->setMatrix(thisData->getImageMatrix());
            this->markDirty(DirtyMatrix);
        }

        thisData->clearAllChange();
    }

}/*namespace sstd*/


// 参考：
//https://github.com/nanguazhude/QQmlQuickBook/tree/master/chapter02/qsgdrawtexturepoint
// 5.13.0/Src/qtdeclarative/src/quick/scenegraph/util

