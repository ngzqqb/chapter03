# qtimage_node_module/qtimage_node_module.pro

TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(qtimage_node_module)

SOURCES += $$PWD/the_moudle.cpp
HEADERS += $$PWD/the_moudle.hpp

SOURCES += $$PWD/Empty.cpp
HEADERS += $$PWD/Empty.hpp

SOURCES += $$PWD/../shared/QtImageNode.cpp
HEADERS += $$PWD/../shared/QtImageNode.hpp

SOURCES += $$PWD/../shared/QtImageItem.cpp
HEADERS += $$PWD/../shared/QtImageItem.hpp

SOURCES += $$PWD/QtLocalImageLoader.cpp
HEADERS += $$PWD/QtLocalImageLoader.hpp

include($$PWD/../../sstd_library/sstd_library.pri)
include($$PWD/../../sstd_qt_qml_quick_library/sstd_qt_qml_quick_library.pri)


isEmpty(QMAKE_POST_LINK){
    QMAKE_POST_LINK += $${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD} $${PWD} skip
}else{
    QMAKE_POST_LINK += $$escape_expand(\\n\\t)$${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD} $${PWD} skip
}
mkpath($${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug/qtimage_node_module)
CONFIG(debug,debug|release) {
    DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug/qtimage_node_module
    QMAKE_POST_LINK += $$escape_expand(\\n\\t)$${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD}/theqml_the_debug $${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug debug
}else{
    DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}/theqml/qtimage_node_module
    QMAKE_POST_LINK += $$escape_expand(\\n\\t)$${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD}/theqml_the_debug $${SSTD_LIBRARY_OUTPUT_PATH}/theqml release
    QMAKE_POST_LINK += $$escape_expand(\\n\\t)$$[QT_INSTALL_BINS]/qmlplugindump -notrelocatable theqml.qtimage_node_module 1.0 $${SSTD_LIBRARY_OUTPUT_PATH} > $${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug/qtimage_node_module/plugins.qmltypes
}
export(QMAKE_POST_LINK)

DISTFILES += $$PWD/theqml_the_debug/qtimage_node_module/qmldir

#/*endl_input_of_latex_for_clanguage_lick*/
