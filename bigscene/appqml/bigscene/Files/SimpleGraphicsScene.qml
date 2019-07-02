import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Shapes 1.13

import sstd.simple.scene 1.0

PrivateBasic{

    Flickable{
        ScrollBar.vertical: ScrollBar { }
        ScrollBar.horizontal: ScrollBar { }
        anchors.fill: parent
        id : idFlickAble

        contentWidth: idSceneView.width
        contentHeight: idSceneView.height

        SimpleQGraphicsSceneView{
            id : idSceneView
            width: 1024
            height: 1024
            viewport{
                width: idFlickAble.width;
                height: idFlickAble.height;
                x:idFlickAble.contentX;
                y:idFlickAble.contentY;
            }
        }

    }

}



