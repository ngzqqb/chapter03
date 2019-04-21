/* appqml/polygon_point/main.qml */
import QtQuick 2.9
import QtQuick.Controls 2.5

/*begin:import*/
import theqml_the_debug.polygon_point_module 1.0
/*end:import*/

ApplicationWindow {

    width: 360 ;
    height: 360 ;
    visible: true ;

    PolygonPoint{
        anchors.centerIn: parent
        width: parent.width
        height: parent.height

        polygonSize: 4
        polygonColor: Qt.rgba(0.8,0.3,0.4,1)
        polygonCenter: Qt.point(0.0,0.0)

    }

    PolygonPoint{
        anchors.centerIn: parent
        width: parent.width*0.8
        height: parent.height*0.8

        polygonSize: 4
        polygonColor: Qt.rgba(0.4,0.3,0.8,1)
        polygonCenter: Qt.point(0.0,0.0)

    }

    PolygonPoint{

        width: 32
        height: 32
        x : 100
        y : 100

        polygonSize: 3
        polygonColor: Qt.rgba(0.3,0.8,0.4,1)
        polygonCenter: Qt.point(0.0,0.0)

    }

}
/*endl_input_of_latex_for_clanguage_lick*/
/*begin:debug*/
/*end:debug*/
