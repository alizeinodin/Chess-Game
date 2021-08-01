import QtQuick 2.0
import QtQuick.Controls 2.13

Page {
    width: 640
    height: 480
    title: qsTr("player name")

    TextField {
        id: textField
        x: 64
        y: 293
        width: 150
        height: 40
        text: qsTr("Player 1")
    }

    TextField {
        id: textField1
        x: 490
        y: 293
        width: 150
        height: 40
        text: qsTr("Player 2")
    }

}
