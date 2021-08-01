import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3
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


    Column{
        anchors.centerIn: parent
        spacing: 10


        Button{
            id: start
            width: 230
            height: 70
            text: "شروع بازی"
            focusPolicy: Qt.NoFocus
            font.pixelSize: 20
            font.family: fontfarsi.name
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

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
