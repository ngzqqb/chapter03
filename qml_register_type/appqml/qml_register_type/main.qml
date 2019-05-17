/* appqml/polygon_point/main.qml */
import QtQuick 2.9
import QtQuick.Controls 2.5
import sstd.register.type 2.0
import sstd.styled.app 1.0

StyledApplicationWindow {

    width: 360 ;
    height: 94 ;

    Component.onCompleted: {
        GlobalAppData.isDark = false;
    }

    Revision0{
        id : id0
    }

    Revision1{
        id : id1
    }

    Revision2{
        id : id2
    }

    Revision3{
        id : id3
    }

    RegisterObject{
        id : id4

        function getString(){
            return "2.0 : " +
                    id4.test() +
                    " " +
                    id4.test1() +
                    " " +
                    id4.test2();
        }

    }

    TextArea{
        anchors.fill: parent
        Component.onCompleted: {

            append(id0.getString())
            append(id1.getString())
            append(id2.getString())
            append(id3.getString())
            append(id4.getString())

        }
    }


}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
