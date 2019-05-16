/* appqml/polygon_point/main.qml */
import QtQuick 2.9
import QtQuick.Controls 2.5

ApplicationWindow {

    width: 360 ;
    height: 64 ;
    visible: true ;

   Revision0{
       id : id0
   }

   Revision1{
       id : id1
   }

   Revision2{
       id : id2
   }

   TextArea{
   anchors.fill: parent
   Component.onCompleted: {

       append(id0.getString())
       append(id1.getString())
       append(id2.getString())

   }
   }


}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
