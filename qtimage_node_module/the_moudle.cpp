/* qtimage_node_module/the_moudle.cpp */

#include "the_moudle.hpp"
#include "Empty.hpp"
#include "QtImageItem.hpp"
#include "QtLocalImageLoader.hpp"

void sstd::TheMoudle::registerTypes(const char * argURI) {
    qmlRegisterType<Empty>(argURI, 1, 0, "Empty");
    qmlRegisterType<QtImageItem>(argURI, 1, 0, "QtImageItem");
    qmlRegisterSingletonType<QtLocalImageLoader>(argURI, 1, 0,
        "QtLocalImageLoader",
        [](QQmlEngine *, QJSEngine *)->QObject * {
        static auto globalAns = sstd_new<QtLocalImageLoader>();
        return globalAns;
    });
    qmlProtectModule(argURI, 1);
}

/*endl_input_of_latex_for_clanguage_lick*/
