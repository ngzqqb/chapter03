﻿/* appqml/qtimage_node/main.qml */
import QtQuick 2.13
import QtQuick.Controls 2.13

/*begin:import*/
import theqml_the_debug.sstd.styled.app 1.0
import theqml_the_debug.qtimage_node_module 1.0
/*end:import*/

StyledApplicationWindow {

    width: 512 ;
    height: 360 ;
    id : idRoot ; 

    QtImageItem{
        id : idQtImageItem
        anchors.fill: parent
        Component.onCompleted: {
            idQtImageItem.setImage(QtLocalImageLoader.loadImage(
                                                       Qt.resolvedUrl("figure.jpg")));
        }
        //Timer{
        //    interval: 1000 ;
        //    running: true;
        //    repeat: false
        //    triggeredOnStart:true
        //    onTriggered: {
        //        idQtImageItem.setImage(QtLocalImageLoader.loadImage(
        //                                   Qt.resolvedUrl("figure.jpg")));
        //    }
        //}
    }

    Component.onCompleted: {
    }

}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
