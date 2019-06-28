#include "QtImageNode.hpp"

namespace sstd {

    namespace this_private {

        class ImageShader;
        class ImageMaterial final : public QSGMaterial  {
        public:
            /*比较两个Material*/
            inline int compare(const QSGMaterial *other) const override;
        protected:
            /* 用于分类 */
            inline QSGMaterialType *type() const override{
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
            inline void updateToQImage(const QImage & arg){
                thisImage = arg;
            }
        private:
            GLuint thisQImageTexture{ 0 };
            QImage thisImage;
            friend class ImageShader;
        private:
            sstd_class (ImageMaterial);
        };

        class ImageShader final : public QSGMaterialShader {
        public:

            /* 片段着色器 */
            inline const char * fragmentShader() const override{
return u8R"--------(
       )---------";

            }

            /* 顶点着色器 */
            inline const char * vertexShader() const override {
                return  u8R"--------(
                        )--------";
            }

            /* 顶点着色器输入 */
            inline char const *const *attributeNames() const override{
                static const char *const globalAns [] {
                    "vertexCoord"/*顶点*/,
                    "vertexColor"/*顶点颜色*/,
                    nullptr
                };
                return globalAns;
            }

            /* 每次绘制之前更新状态 */
           inline void updateState(
                     const RenderState &state,
                     QSGMaterial * varNew,
                     QSGMaterial * varOld) override {
                constructThisGL();
            }

           /* 初始化资源 */
           inline void activate() override {
                constructThisGL();
           }

           /* 释放资源 */
           inline void deactivate() override{
                destoryThisGL();
           }

           inline ImageShader(ImageMaterial * arg):
               thisImageMaterial{arg}{
           }

           inline ~ImageShader(){
                destoryThisGL();
           }

        private:
           inline void constructThisGL(){
                  sstd::opengl_utility::updateTexture ( &(thisImageMaterial->thisQImageTexture),
                                                        thisImageMaterial->thisImage);
           }

           inline void destoryThisGL(){
                glDeleteTextures (1,&(thisImageMaterial->thisQImageTexture));
           }

        private:
           ImageMaterial * const thisImageMaterial;
        private:
            sstd_class(ImageShader);
        };

        inline QSGMaterialShader *ImageMaterial::createShader() const  {
            return sstd_new< ImageShader >( this );
        }

        inline int ImageMaterial::compare(const QSGMaterial *other) const {
            auto varOther = static_cast<const ImageMaterial *>(other);
            return static_cast<GLint>(this->thisQImageTexture) -
                    static_cast<GLint>(varOther->thisQImageTexture);
        }

    }/*namespace this_private*/

    void QtImageNodeData::setImage(QImage arg){
        thisImage = std::move( arg );
        thisFlags.set<ImageNodeDataState::ImageChanged>();
    }

       void QtImageNodeData::clearAllChange(){
           thisFlags.clearAll ();
       }

    QtImageNode::QtImageNode(std::shared_ptr<QtImageNodeData> arg) :thisData{std::move(arg)} {

    }

    void QtImageNode::updateTheNode() {

        if(thisData->testChanged<ImageNodeDataState::ImageChanged>()){

        }

        thisData->clearAllChange ();
    }


}/*namespace sstd*/


// 参考：
//https://github.com/nanguazhude/QQmlQuickBook/tree/master/chapter02/qsgdrawtexturepoint
// 5.13.0/Src/qtdeclarative/src/quick/scenegraph/util

