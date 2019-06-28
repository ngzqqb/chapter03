#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    enum class ImageNodeDataState {
        ImageChanged,
        ImageSizeChanged,
        ImageMatrixChanged,
        Size
    };

    class QtImageNodeData {
    public:
        inline QImage getImage() const;
        inline QSizeF getImageSize() const;
        inline QMatrix4x4 getImageMatrix() const;
        bool setImage(QImage);
        bool setImageSize(const QSizeF &);
        bool setMatrix(const QMatrix4x4 &);
    private:
        QImage thisImage;
        QSizeF thisImageSize;
        QMatrix4x4 thisMatrix;
        sstd::QuickFlags< ImageNodeDataState::Size > thisFlags;
    public:
        void clearAllChange();
    public:
        template<ImageNodeDataState>
        inline bool testChanged() const;
    private:
        sstd_class(QtImageNodeData);
    };

    class QtImageNodeWrap : public QSGGeometryNode {
        using Super = QSGGeometryNode;
    public:
        QtImageNodeWrap();
        void updateImage(const QImage &);
        void updateImageSize(const QSizeF &);
    private:
        sstd_class(QtImageNodeWrap);
    };

    class QtImageNode : public QSGTransformNode {
    public:
        QtImageNode(std::shared_ptr<QtImageNodeData>);
    public:
        void updateTheNode();
    private:
        QtImageNodeWrap * thisDrawImage{ nullptr };
        std::shared_ptr<QtImageNodeData> thisData;
    private:
        sstd_class(QtImageNode);
    };

    inline QImage QtImageNodeData::getImage() const {
        return thisImage;
    }

    inline QSizeF QtImageNodeData::getImageSize() const {
        return thisImageSize;
    }

    template<ImageNodeDataState I>
    inline bool QtImageNodeData::testChanged() const {
        return thisFlags.test<I>();
    }

    inline QMatrix4x4 QtImageNodeData::getImageMatrix() const{
        return thisMatrix;
    }

}/*namespace sstd*/

