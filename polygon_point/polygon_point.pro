# polygon_point/polygon_point.pro

TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = polygon_point_debug
}else{
    TARGET = polygon_point
}

SOURCES += $$PWD/main.cpp

include($$PWD/../../sstd_library/sstd_library.pri)
include($$PWD/../../sstd_qt_qml_quick_library/sstd_qt_qml_quick_library.pri)
include($$PWD/../../sstd_library/add_vc_debug_console.pri)

DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}

CONFIG(debug,debug|release){
    DEFINES += CURRENT_DEBUG_PATH=\"$$PWD\"
}else{
    QMAKE_POST_LINK += $$escape_expand(\n\t)$${DESTDIR}/sstd_copy_qml $${PWD}/appqml $${DESTDIR}/appqml release
    export(QMAKE_POST_LINK)
}

QMLSOURCES += $$PWD/appqml/polygon_point/main.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES

#/*endl_input_of_latex_for_clanguage_lick*/"
