#include "QtLocalImageLoader.hpp"

namespace sstd {

    QImage QtLocalImageLoader::loadImage(const QUrl & arg) {
        QImage varImage{ arg.toLocalFile() };
        return std::move(varImage);
    }

}/*namespace sstd*/
