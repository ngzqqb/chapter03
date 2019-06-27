#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd{

    enum SimpleRectanglesWorldDataRole{
        WidthRole,
        HeightRole,
        XRole,
        YRole,
        Size,
    };

    class SimpleRectanglesWorldData{
        int thisWidth{0};
        int thisHeight{0};
        int thisX{0};
        int thisY{0};
    public:

        inline auto getWidth() const{
            return thisWidth ;
        }

        inline auto getHeight() const{
            return thisHeight;
        }

        inline auto getX() const{
            return thisX;
        }

        inline auto getY() const{
            return thisY;
        }

    private:
        sstd_class (SimpleRectanglesWorldData);
    };

}/*namespace sstd*/











