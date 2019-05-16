# qml_register_type/qml_register_type.pro

TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = qml_register_type_debug
}else{
    TARGET = qml_register_type
}

SOURCES += $$PWD/main.cpp \
    TestObject.cpp

include($$PWD/../../sstd_library/sstd_library.pri)
include($$PWD/../../sstd_qt_qml_quick_library/sstd_qt_qml_quick_library.pri)
include($$PWD/../../sstd_library/add_vc_debug_console.pri)

isEmpty(QMAKE_POST_LINK){
    QMAKE_POST_LINK += $${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD} $${PWD} skip
}else{
    QMAKE_POST_LINK += $$escape_expand(\\n\\t)$${SSTD_LIBRARY_OUTPUT_PATH}/sstd_copy_qml $${PWD} $${PWD} skip
}

DESTDIR = $${SSTD_LIBRARY_OUTPUT_PATH}

CONFIG(debug,debug|release){
    DEFINES += CURRENT_DEBUG_PATH=\\\"$$PWD\\\"
}else{
    QMAKE_POST_LINK += $$escape_expand(\n\t)$${DESTDIR}/sstd_copy_qml $${PWD}/appqml $${DESTDIR}/appqml release
    export(QMAKE_POST_LINK)
}

QMLSOURCES += $$PWD/appqml/qml_register_type/main.qml
QMLSOURCES += $$PWD/appqml/qml_register_type/Revision0.qml
QMLSOURCES += $$PWD/appqml/qml_register_type/Revision1.qml
QMLSOURCES += $$PWD/appqml/qml_register_type/Revision2.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES
QML_IMPORT_PATH += $${SSTD_LIBRARY_OUTPUT_PATH}
#/*endl_input_of_latex_for_clanguage_lick*/"

HEADERS += \
    TestObject.hpp
