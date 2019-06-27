import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Shapes 1.13

import sstd.simple.scene 1.0

PrivateBasic{

    Flickable{
        anchors.fill: parent ;
        onWidthChanged: {
            idSimpleRectangleWorld.updateViewWidth(width);
        }
        onHeightChanged: {
            idSimpleRectangleWorld.updateViewHeight(height);
        }
        onContentYChanged: {
            idSimpleRectangleWorld.updateViewX(contentX)
        }
        onContentXChanged: {
            idSimpleRectangleWorld.updateViewY(contentY)
        }
        ScrollBar.vertical: ScrollBar { }
        ScrollBar.horizontal: ScrollBar { }
        contentWidth: idSimpleRectangleWorld.width;
        contentHeight: idSimpleRectangleWorld.height
        SimpleRectanglesWorld{
            width: 1024  ;
            height: 1024 ;
            implicitHeight: 1024
            implicitWidth: 1024
            id : idSimpleRectangleWorld
        }
    }

}
















