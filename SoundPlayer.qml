import QtQuick 2.15

// Tiny audio helper: Qt5 uses Audio, Qt6 uses SoundEffect / MediaPlayer.
Item {
    id: root
    property url source
    property real volume: 1.0
    property bool looping: false
    property bool autoPlay: false
    property var _backend: null

    function play() {
        if (_backend)
            _backend.play()
    }
    function stop() {
        if (_backend)
            _backend.stop()
    }

    Component.onCompleted: {
        var major = (typeof buAliQtMajor !== "undefined") ? buAliQtMajor : 5
        var src = "" + root.source
        var qml
        if (major >= 6) {
            if (root.looping) {
                qml = 'import QtMultimedia\n'
                    + 'MediaPlayer {\n'
                    + '  source: "' + src + '"\n'
                    + '  audioOutput: AudioOutput { volume: ' + root.volume + ' }\n'
                    + '  loops: MediaPlayer.Infinite\n'
                    + '}'
            } else {
                qml = 'import QtMultimedia\n'
                    + 'SoundEffect {\n'
                    + '  source: "' + src + '"\n'
                    + '  volume: ' + root.volume + '\n'
                    + '}'
            }
        } else {
            qml = 'import QtMultimedia 5.15\n'
                + 'Audio {\n'
                + '  source: "' + src + '"\n'
                + '  volume: ' + root.volume + '\n'
                + '  loops: ' + (root.looping ? 'Audio.Infinite' : '0') + '\n'
                + '  autoPlay: ' + (root.autoPlay ? 'true' : 'false') + '\n'
                + '}'
        }
        try {
            _backend = Qt.createQmlObject(qml, root, "BuAliSound")
            if (root.autoPlay && major >= 6)
                _backend.play()
        } catch (e) {
            console.warn("SoundPlayer failed:", e)
        }
    }
}
