import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3

Item {
    id: welcome
    width: 800
    height: 800
    anchors.centerIn: parent

    Rectangle
    {
        color: "red"
        anchors.fill: parent
    }

    FontLoader{
        id: fontfarsi
        source: "media/Font/IRANSansWeb_Bold.ttf"
    }


    Column{
        anchors.fill: parent
        anchors.horizontalCenter: welcome.horizontalCenter

        Button{
            id: start
            width: 160
            height: 70
            text: "شروع بازی"
            font.pixelSize: 20
            font.family: fontfarsi.name
        }
    }

}
