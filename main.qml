import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
ApplicationWindow {
    id: root
    visible: true
    width: 1500
    height: 950
    title: qsTr("Chess")

    ChessBoard{

    }

//        background: BorderImage
//        {
//            id: name
//            source: "backchess.jpg"
//            width: 640; height: 480
//            border.left: 5; border.top: 5
//            border.right: 5; border.bottom: 5
//        }

//        Button {
//            id: button
//            x: 510
//            y: 388
//            width: 100
//            height: 33
//            text: qsTr("Next")
//            opacity: 0.57
//        }

//    Text {
//        id: element
//        x: 240
//        y: 54
//        width: 160
//        height: 52
//        color: "#ffffff"
//        text: qsTr("Chess")
//        styleColor: "#ffffff"
//        font.family: "Times New Roman"
//        font.bold: true
//        horizontalAlignment: Text.AlignHCenter
//        font.pixelSize: 33
//    }

//    TextField {
//        id: textField
//        x: 220
//        y: 384
//        text: qsTr("")
//        opacity: 0.57
//        clip: false
//        visible: true
//        placeholderText: "Game Name"
//    }

//    StackView
//    {
//            id: stackView
//            anchors.fill: parent
//    }
}
