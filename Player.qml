import QtQuick 2.0
import QtQuick.Controls 2.13

Item {
    id:playerItem
    anchors.fill: parent

    Text {
        id: playertxt
        text: qsTr("بازیکن شماره ۱ نام خود را وارد کنید:")
        font.family: fontID.name
        anchors.horizontalCenter: playerItem.horizontalCenter
        font.pixelSize: 20
    }

    TextField {
        id: textField
        anchors.top: playerItem.top
        anchors.topMargin: playerItem.height / 1.5
        anchors.horizontalCenter: playerItem.horizontalCenter
        width: playerItem.width / 3
        height: playerItem.height / 10
        text: qsTr("Player 1")
        anchors.horizontalCenterOffset: 0
    }
}









/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
