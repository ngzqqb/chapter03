/* appqml/polygon_point/main.qml */
import QtQuick 2.9
import QtQuick.Controls 2.5
import sstd.register.type 2.0
import sstd.styled.app 1.0

StyledApplicationWindow {

    id : idRoot
    width: 360 ;
    height: 128 ;

    Component.onCompleted: {
        GlobalAppData.isDark = false;
    }

    function getTestString(arg){
    return  "import sstd.register.type " + arg +
    "\n"+ '
RegisterObject{

    id : idThe

    property var hasTest:    try{ return test ; } catch( varError ){ return "u" }
    property var hasTest1:   try{ return test1 ; } catch( varError ){ return "u" }
    property var hasTest2:   try{ return test2 ; } catch( varError ){ return "u" }
    property var hasTest3:   try{ return test3 ; } catch( varError ){ return "u" }
    property var hasBasicV0: try{ return basicV0 ; } catch( varError ){ return "u" }
    property var hasBasicV1: try{ return basicV1 ; } catch( varError ){ return "u" }

    function getString(){
        return "' + arg + ' : " +
                String(idThe.test)[0] +
                " " +
                String(idThe.test1)[0] +
                " " +
                String(idThe.test2)[0] +
                " " +
                String(idThe.test3)[0] +
                " " +
                String(idThe.basicV0)[0] +
                " " +
                String(idThe.basicV1)[0] +
                " | " +
                String(hasTest)[0] +
                " " +
                String(hasTest1)[0] +
                " " +
                String(hasTest2)[0] +
                " " +
                String(hasTest3)[0] +
                " " +
                String(hasBasicV0)[0] +
                " " +
                String(hasBasicV1)[0] ;
    }
}
'
    }

    property var v1_0: Qt.createQmlObject( getTestString("1.0"),idRoot )
    property var v1_1: Qt.createQmlObject( getTestString("1.1"),idRoot )
    property var v1_2: Qt.createQmlObject( getTestString("1.2"),idRoot )
    property var v1_3: Qt.createQmlObject( getTestString("1.3"),idRoot )
    property var v2_0: Qt.createQmlObject( getTestString("2.0"),idRoot )

    TextArea{
        anchors.fill: parent
        Component.onCompleted: {

            append(v1_0.getString())
            append(v1_1.getString())
            append(v1_2.getString())
            append(v1_3.getString())
            append(v2_0.getString())

        }
    }


}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
