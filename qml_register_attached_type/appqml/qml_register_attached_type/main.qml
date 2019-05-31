/* appqml/qml_register_attached_type/main.qml */
import QtQuick 2.9
import QtQuick.Controls 2.5
import sstd.attached.test 1.0

/*begin:import*/
import theqml_the_debug.sstd.styled.app 1.0
/*end:import*/

StyledApplicationWindow {

    id : idRoot
    width: 128 ;
    height: 128 ;

    Rectangle{
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.8
        color: idRoot.TestAttached.valueAttached
        Text {
            id: idTestText
            text: String(Qt.rgba(0.5,0.5,0.5,1))
            anchors.centerIn: parent
            color: GlobalAppData.foreground
        }
    }

    property alias testText : idTestText.text

    Timer{
        interval: 998;
        running: true;
        repeat: true
        onTriggered: {
            idRoot.TestAttached.valueAttached = Qt.rgba(Math.random()*0.7+0.2,
                                                        Math.random()*0.8+0.1,
                                                        Math.random(),1);
        }
    }

    TestAttached.onValueAttachedChanged: {
        testText = String( TestAttached.valueAttached )
    }

}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
