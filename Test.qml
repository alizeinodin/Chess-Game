import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3

Item {
    id: mainitem
    anchors.fill: parent


    ParallelAnimation{
        id: moveAnimation
        running: false

        property var origin: row2
        property var dest: row3

        property var orgid: a2

        property var destid: a5

        NumberAnimation {
            target: moveAnimation.orgid
            property: "x"
            to: (a5.index - a2.index) * (a2.width + row2.spacing)
            duration: 1200
            easing.type: Easing.OutCubic
        }

        NumberAnimation {
            target: a2
            property: "y"
            to: (moveAnimation.dest.index - moveAnimation.origin.index) * -(row3.anchors.bottomMargin + a2.height)
            duration: 1200
            easing.type: Easing.OutCubic
        }

        onRunningChanged: {
//            if(running === false)
//            {
//                // update destination piece
//                board.destimg.source = board.orgimg.source;

//                // update origin piece
//                board.orgid.piece = "";
//                board.orgimg.source = "";

//                // return org cell to orginal place
//                board.orgid.x = board.orgx;
//                board.orgid.y = board.orgy;
//            }
        }
    }


    Row{
        id : row2
        anchors.verticalCenter: mainitem.verticalCenter
        spacing: 20
        property int index: 0

        MouseArea{
        id:a2
        cursorShape: Qt.ArrowCursor
        width: 100
        height: 100
        property string id: "a2"
        property string piece: "P"
        property int index: 0
            Rectangle{
                anchors.fill: parent
                color: "#000"
            }
        onClicked: {
            console.log(parent.spacing);
            moveAnimation.running = true;
        }
        }

        MouseArea{
        id:a3
        cursorShape: Qt.ArrowCursor
        width: 100
        height: 100
        property string id: "a2"
        property string piece: "P"
        property int index: 1
        Rectangle{
            anchors.fill: parent
            color: "#d2d2d2"
        }
        onClicked: {
        }

        }
    }
    Row{
        id : row3
        anchors.bottom: row2.top
        anchors.bottomMargin: 9.3
        spacing: 10
        property int index: 1

        MouseArea{
        id:a4
        cursorShape: Qt.ArrowCursor
        width: 100
        height: 100
        property string id: "a2"
        property string piece: "P"
        property int index: 0
            Rectangle{
                anchors.fill: parent
                color: "#000d2f"
            }
        onClicked: {
            console.log(parent.spacing)
            moveAnimation.running = true;
        }
        }

        MouseArea{
        id:a5
        cursorShape: Qt.ArrowCursor
        width: 100
        height: 100
        property string id: "a2"
        property string piece: "P"
        property int index: 1
        Rectangle{
            anchors.fill: parent
            color: "#e343ef"
        }
        onClicked: {
        }

        }
    }
}
