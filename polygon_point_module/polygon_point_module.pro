# polygon_point_module/polygon_point_module.pro

TEMPLATE = lib
CONFIG += plugin
TARGET = $$qtLibraryTarget(polygon_point_module)

SOURCES += $$PWD/the_moudle.cpp
HEADERS += $$PWD/the_moudle.hpp

SOURCES += $$PWD/Empty.cpp
HEADERS += $$PWD/Empty.hpp

include($$PWD/../../sstd_library/sstd_library.pri)
include($$PWD/../../sstd_qt_qml_quick_library/sstd_qt_qml_quick_library.pri)

mkpath($${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug/polygon_point_module)
CONFIG(debug,debug|release) {
    DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug/polygon_point_module
    QMAKE_POST_LINK += $$escape_expand(\n\t)$${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD}/theqml_the_debug $${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug debug
}else{
    DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}/theqml/polygon_point_module
    QMAKE_POST_LINK += $$escape_expand(\n\t)$${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD}/theqml_the_debug $${SSTD_LIBRARY_OUTPUT_PATH}/theqml release
    QMAKE_POST_LINK += $$escape_expand(\n\t)$$[QT_INSTALL_BINS]/qmlplugindump -notrelocatable theqml.polygon_point_module 1.0 $${SSTD_LIBRARY_OUTPUT_PATH} > $${SSTD_LIBRARY_OUTPUT_PATH}/theqml_the_debug/polygon_point_module/plugins.qmltypes
}
export(QMAKE_POST_LINK)

DISTFILES += $$PWD/theqml_the_debug/polygon_point_module/qmldir

#/*endl_input_of_latex_for_clanguage_lick*/