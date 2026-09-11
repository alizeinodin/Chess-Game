import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls.Material
import QtMultimedia
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

    // Qt 6: Audio → MediaPlayer + AudioOutput
    MediaPlayer {
        id: mainAudio
        source: "qrc:/media/Sound/main music.mp3"
        audioOutput: AudioOutput { volume: 1.0 }
        loops: MediaPlayer.Infinite
        Component.onCompleted: play()
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
