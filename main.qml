import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3
import QtMultimedia 5.9
import connect 1.0

ApplicationWindow {
    id: root
    visible: true
    minimumWidth: 700
    minimumHeight: 500
    width: Screen.width
    height: Screen.height
    title: qsTr("BuAli Chess")
    font.family: fontfarsi.name
    Material.theme: Material.Light
    Material.accent: Material.Purple
    Material.background: "#EEEEEE"

    property var viewID: view

    StackView{
        id: view
        initialItem: welcomePage
        width: root.width
        height: root.height

    }
    FontLoader{
        id: fontfarsi
        source: "media/Font/IRANSansWeb_Bold.ttf"
    }

    Audio{
        id:mainAudio
        source: "media/Sound/main music.mp3"
        autoPlay: true
        loops: -1
    }


    Connect{
        id: connection

    }
    Welcome{
        visible: false
        id:welcomePage
    }

    ChessBoard{
        visible: false
        id: chessBoardPage
    }
    Player1{
        visible: false
        id: player1Page
    }
    Player2{
        visible: false
        id: player2page
    }
    Gamename{
        visible: false
        id: nameGamePage
    }
    Review{
        visible: false
        id: reviewPage
    }
}
