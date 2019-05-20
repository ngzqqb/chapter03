/* appqml/qml_register_attached_type/main.qml */
import QtQuick 2.9
import QtQuick.Controls 2.5
import sstd.styled.app 1.0
import sstd.attached.test 1.0

StyledApplicationWindow {

    id : idRoot
    width: 360 ;
    height: 128 ;

    Component.onCompleted: {
        GlobalAppData.isDark = false;
    }

    Rectangle{
        anchors.fill: parent
        color: idRoot.TestAttached.valueAttached
    }

}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
