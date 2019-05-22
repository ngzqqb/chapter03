/* appqml/qml_register_attached_type/main.qml */
import QtQuick 2.9
import QtQuick.Controls 2.5
import sstd.styled.app 1.0
import sstd.metaobject.test 1.0

StyledApplicationWindow {

    id : idRoot
    width: 128 ;
    height: 128 ;

    Component.onCompleted: {
        GlobalAppData.isDark = defaultIsDark;
        idRoot.visible = true
    }

    TestObject{
        id : idTestObject
    }

    Text {
        anchors.centerIn: parent
        text: String( "Key2 : " + MyNamespace.Key2 ) + "\n" +
              String( "Key3 : " + MyGadgetNamespace.Key3 ) + "\n" +
              String( "Key4 : " + TestObject.Key4 ) + "\n" +
              String( "gadgetValue : " + idTestObject.gadgetValue.getX() )
        color: GlobalAppData.foreground
    }

}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
