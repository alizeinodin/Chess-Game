import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3
import connect 1.0
//Page {
//    id: pageWelcome
//    anchors.fill: parent

    Item {
    id: welcome
    anchors.fill: parent

   Image {
        id: background
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "media/welcomeBG.jpg"
        }

    FontLoader{
        id: fontfarsi
        source: "media/Font/IRANSansWeb_Bold.ttf"
    }
    /*
    property int widthVar: welcome.width / 2 - 30
    property int heightVar: welcome.height / 2 - 100

    Rectangle{
        id: firistcircle
        x: widthVar
        y: heightVar
        width: 80
        height: 80
        color: "#EEEEEE"
        radius:40
    }
    Rectangle{
        id: secondcircle
        x: widthVar
        y: heightVar
        width: 80
        height: 80
        color: "#2e2e2e"
        radius:40
    }

    SequentialAnimation{
        id: rotationcircle
        running: false
        loops: 2

        PathAnimation{
            duration: 4000
            easing.type: Easing.InQuad
            path: Path{
                startX: 1
            }
        }
    }
    */

    Image {
        id: logo
        source: "media/chess logo.png"
        anchors.bottom: buttons.top
        anchors.bottomMargin: welcome.height / 20
        anchors.horizontalCenter: welcome.horizontalCenter
    }

    Connect{
        id: connect
    }

    Column{
        id: buttons
        anchors.horizontalCenter: welcome.horizontalCenter
        anchors.top: welcome.top
        anchors.topMargin: 500
        spacing: 10


        Button{
            id: start
            width: 230
            height: 70
            text: "شروع بازی"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
            onClicked: {
                view.replace(chessBoardPage);

//                viewID.replace(playerPageID);
//                playerPageID.visible = true;
//                viewID.push(playerPageID);
            }
        }
        Button{
            id: continueGame
            width: 230
            height: 70
            text: "ادامه بازی"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
        }
        Button{
            id: settings
            width: 230
            height: 70
            text: "تنظیمات"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
        }
        Button{
            id: exit
            width: 230
            height: 70
            text: "خروج"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
        }
    }
//    }

}



















/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
