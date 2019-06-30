#include <sstd_qt_qml_quick_library.hpp>
#include "../shared/QtImageItem.hpp"

namespace sstd{

    class SimpleQGraphicsSceneView;

    class SimpleQGraphicsScene : public QGraphicsScene {
        Q_OBJECT
    public:
        SimpleQGraphicsScene();
    private:
        sstd_class (SimpleQGraphicsScene);
    };

    class SimpleQGraphicsSceneViewPort : public QObject {
        Q_OBJECT
    private:
        Q_PROPERTY(qreal x READ getX WRITE setX NOTIFY xChanged)
    private:
        Q_PROPERTY(qreal y READ getY WRITE setY NOTIFY yChanged)
    private:
        Q_PROPERTY(qreal width READ getWidth WRITE setWidth NOTIFY widthChanged)
    private:
        Q_PROPERTY(qreal height READ getHeight WRITE setHeight NOTIFY heightChanged)
    public:
        SimpleQGraphicsSceneViewPort(SimpleQGraphicsSceneView *);
    public:
        inline qreal getX() const;
        inline qreal getY() const;
        inline qreal getWidth() const;
        inline qreal getHeight() const;
    public:
        void setX(const qreal &);
        void setY(const qreal &);
        void setWidth(const qreal &);
        void setHeight(const qreal &);
    public:
        Q_SIGNAL void xChanged();
        Q_SIGNAL void yChanged();
        Q_SIGNAL void widthChanged();
        Q_SIGNAL void heightChanged();
    public:
        QRectF getViewPortRect() const;
    private:
        SimpleQGraphicsSceneView * const thisView ;
    private:
        qreal thisX{0};
        qreal thisY{0};
        qreal thisWidth{0};
        qreal thisHeight{0};
    private:
        sstd_class(SimpleQGraphicsSceneViewPort);
    };

    class VisibleSimpleQGraphicsSceneViewPort : public QtImageItem {
        Q_OBJECT
    public:
        VisibleSimpleQGraphicsSceneViewPort(SimpleQGraphicsSceneView *);
    private:
        using Super = QtImageItem;
        SimpleQGraphicsSceneView * const thisView;
    private:
        sstd_class(VisibleSimpleQGraphicsSceneViewPort);
    };

    class SimpleQGraphicsSceneView : public QQuickItem {
        Q_OBJECT
    private:
        Q_PROPERTY(SimpleQGraphicsSceneViewPort * viewport READ getViewport CONSTANT )
    public:
        SimpleQGraphicsSceneView();
    public:
        inline SimpleQGraphicsSceneViewPort * getViewport() const;
    private:
        QImage thisLastPainted;
        SimpleQGraphicsScene thisScene;
        SimpleQGraphicsSceneViewPort * thisSceneViewPort{nullptr};
        VisibleSimpleQGraphicsSceneViewPort * thisVisibleView{nullptr};
        void updateViewPortSize();
        void updateViewPort( QList<QRectF> );
        friend class SimpleQGraphicsSceneViewPort;
    private:
        sstd_class(SimpleQGraphicsSceneView);
    };

    inline SimpleQGraphicsSceneViewPort * SimpleQGraphicsSceneView::getViewport() const{
        return thisSceneViewPort ;
    }

    inline qreal SimpleQGraphicsSceneViewPort::getX() const{
        return thisX;
    }

    inline qreal SimpleQGraphicsSceneViewPort::getY() const{
        return thisY;
    }

    inline qreal SimpleQGraphicsSceneViewPort::getWidth() const{
        return thisWidth;
    }

    inline qreal SimpleQGraphicsSceneViewPort::getHeight() const{
        return thisHeight;
    }

}/*namespace sstd*/
