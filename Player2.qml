import QtQuick 2.0
import QtQuick.Controls 2.13
Page {
    id:page2Player
    anchors.fill: parent

    Item {
        id: playerItem
        anchors.fill: parent

        Image {
                id: background
                source: "media/background_player.jpg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
       }

        Image {
            id: player2Img
            source: "media/knight2.png"
            anchors.horizontalCenter: playerItem.horizontalCenter
            anchors.top: playerItem.top
            anchors.topMargin: playerItem.height / 4
        }


        Text {
            id: player2txt
            text: qsTr("بازیکن شماره 2 نام خود را وارد کنید:")
            font.family: fontfarsi.name
            anchors.horizontalCenter: player2Img.horizontalCenter
            font.pixelSize: 20
            font.letterSpacing: 1.2
            anchors.top: player2Img.bottom
            anchors.topMargin: playerItem.height / 30
            color: "#2e2e2e"
        }

        TextField {
            id: textField
            anchors.top: player2txt.top
            anchors.topMargin: playerItem.height / 35
            anchors.horizontalCenter: player2txt.horizontalCenter
            width: player2txt.width
            height: playerItem.height / 10
            placeholderText: qsTr("لطفا نام خود را وارد کنید...")
            font.family: fontfarsi.name
            font.pixelSize: 18
            anchors.horizontalCenterOffset: 0
            color: "#2e2e2e"
        }

        Button{
            id: nextButton
            width: player2txt.width
            height: playerItem.height / 18
            anchors.top: textField.bottom
            anchors.topMargin: playerItem.height / 30
            anchors.bottomMargin: playerItem.height / 35
            anchors.horizontalCenter: player2txt.horizontalCenter
            text: qsTr("بعدی")
            font.pixelSize: 18
            font.family: fontfarsi.name
            onClicked: {
                connection.setPlayer2Name(qsTr(textField.text));
                view.push(nameGamePage);
            }
        }

        MouseArea{
            anchors.top: playerItem.top
            anchors.topMargin: playerItem.height / 50
            anchors.left: playerItem.left
            anchors.leftMargin: playerItem.width / 50
            width: 60
            height: 60
            Image {
                id: backbtn
                source: "media/backbtn.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }
            onClicked: {
                view.pop();
            }
        }
    }
}
