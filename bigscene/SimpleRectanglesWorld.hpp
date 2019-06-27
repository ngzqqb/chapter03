#pragma once

#include "SimpleRectanglesWorldData.hpp"

namespace sstd {

    class SimpleRectanglesWorld : public QQuickItem {
        Q_OBJECT
    public:
        SimpleRectanglesWorld();
        void updateViewWidth(int);
        void updateViewHeight(int);
        void updateViewX(int);
        void updateViewY(int);
    private:
        std::shared_ptr<SimpleRectanglesWorldData> thisRectanglesData;
    private:
        sstd_class (SimpleRectanglesWorld);
    };

}/*namespace sstd*/

