#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    enum class ImageNodeDataState{
        ImageChanged,
        Size
    };

    class QtImageNodeData  {
    public:
        inline QImage getImage() const;
        void setImage(QImage );
    private:
        QImage thisImage ;
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
    public:
    private:

    private:
        sstd_class(QtImageNodeWrap);
    };

    class QtImageNode : public QSGTransformNode {
    public:
        QtImageNode(std::shared_ptr<QtImageNodeData>);
    public:
        void updateTheNode();
    private:
        QtImageNodeWrap * thisDrawImage{nullptr};
        std::shared_ptr<QtImageNodeData> thisData ;
    private:
        sstd_class(QtImageNode);
    };

    inline QImage QtImageNodeData::getImage() const{
        return thisImage ;
    }

    template<ImageNodeDataState I>
    inline bool QtImageNodeData::testChanged() const{
        return thisFlags.test<I>();
    }

}/*namespace sstd*/

