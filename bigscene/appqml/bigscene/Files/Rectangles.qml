import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Shapes 1.13

import sstd.simple.scene 1.0

PrivateBasic{

        onWidthChanged: {
            idSimpleRectangleWorld.updateViewWidth(width);
        }
        onHeightChanged: {
            idSimpleRectangleWorld.updateViewHeight(height);
        }

        ScrollBar.vertical: ScrollBar { }
        ScrollBar.horizontal: ScrollBar { }

        SimpleRectanglesWorld{
            anchors.fill: parent ;
            implicitHeight: 1024
            implicitWidth: 1024
            id : idSimpleRectangleWorld
        }

}
