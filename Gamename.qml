import QtQuick 2.0
import QtQuick.Controls 2.13
import connect 1.0
Page {
    id:gamename
    anchors.fill: parent

    Item {
        id: gamenameItem
        anchors.fill: parent

         Image {
                 id: background
                 source: "media/bgGameName.jpg"
                 anchors.fill: parent
                 fillMode: Image.PreserveAspectCrop
        }


//        Connect{
//            id:connect
//        }


        Text {
            id: namegametxt
            text: qsTr("نام بازی را وارد کنید:")
            font.family: fontID.name
            anchors.horizontalCenter: textField.horizontalCenter
            font.pixelSize: 20
            font.letterSpacing: 1.2
            anchors.top: gamenameItem.top
            anchors.topMargin: gamenameItem.height / 2.5
            color: "#2e2e2e"
        }

        TextField {
            id: textField
            anchors.top: namegametxt.top
            anchors.topMargin: gamenameItem.height / 35
            anchors.left: gamenameItem.left
            anchors.leftMargin: gamenameItem.width / 4
            width: namegametxt.width
            height: gamenameItem.height / 10
            placeholderText: qsTr("لطفا نام بازی را وارد کنید...")
            font.family: fontfarsi.name
            font.pixelSize: 18
            anchors.horizontalCenterOffset: 0
            color: "#2e2e2e"
        }

        Button{
            id: nextButton
            width: namegametxt.width
            height: gamenameItem.height / 18
            anchors.top: textField.bottom
            anchors.topMargin: gamenameItem.height / 30
            anchors.horizontalCenter: textField.horizontalCenter
            text: qsTr("بعدی")
            font.pixelSize: 18
            font.family: fontfarsi.name
            onClicked: {
                connection.startGame(qsTr(textField.text));
                mainAudio.stop();
                view.push(chessBoardPage);
            }
        }

        MouseArea{
            anchors.top: gamenameItem.top
            anchors.topMargin: gamenameItem.height / 50
            anchors.left: gamenameItem.left
            anchors.leftMargin: gamenameItem.width / 50
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
