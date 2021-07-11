import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Chess")
        background: BorderImage
        {
            id: name
            source: "backchess.jpg"
            width: 640; height: 480
            border.left: 5; border.top: 5
            border.right: 5; border.bottom: 5
        }



    Text {
        id: element
        x: 240
        y: 54
        width: 160
        height: 52
        color: "#ffffff"
        text: qsTr("Chess")
        styleColor: "#ffffff"
        font.family: "Times New Roman"
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 27
    }

    TextField {
        id: textField
        x: 220
        y: 384
        text: qsTr("")
        opacity: 0.37
        clip: false
        visible: true
        placeholderText: "Game Name"
    }
}
