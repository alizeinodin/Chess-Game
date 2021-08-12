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

    Dialog{
        id: settingsDialog
        parent: welcome
        anchors.centerIn: welcome
        title: "تنظیمات"
        font.family: fontfarsi.name
        modal: true
        CheckBox{
            checked: true
            text: qsTr("موسقی متن")
            font.family: fontfarsi.name
            onCheckStateChanged: {
                if(checked === false)
                {
                    mainAudio.stop();
                }
                if(checked === true)
                {
                    mainAudio.play();
                }
            }
        }

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
                view.push(player1Page);
            }
        }
        Button{
            id: continueGame
            width: 230
            height: 70
            text: "بازی های قبلی"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
            onClicked: {
                view.push(reviewPage);
            }
        }
        Button{
            id: settings
            width: 230
            height: 70
            text: "تنظیمات"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
            onClicked: settingsDialog.open()
        }
        Button{
            id: exit
            width: 230
            height: 70
            text: "خروج"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
            onClicked: connect.exitGame()
        }
    }
//    }

}



















/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
