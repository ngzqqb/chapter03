#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    class QtLocalImageLoader : public QObject {
        Q_OBJECT
    public:
        Q_INVOKABLE QImage loadImage(const QUrl &);
    private:
        sstd_class(QtLocalImageLoader);
    };

}/*namespace sstd*/




