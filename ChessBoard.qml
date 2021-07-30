import QtQuick 2.0
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3
import connect 1.0
import QtMultimedia 5.9
import "functions.js" as Func

Item {
    id: mainBoard
    anchors.fill: parent

    FontLoader{
        id: fontfarsi
        source: "media/Font/IRANSansWeb_Bold.ttf"
    }

    BorderImage{
        id: bg
        source: ""
        anchors.fill: parent
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: 5
    }
    Connect{
        id: connection
        onSuccessMove: {
            // set animation destination
            moveAnimation.tox = board.destid.x;
            moveAnimation.toy = board.destid.y;

            moveAnimation.running = true; // Animation for move
            movePieceSound.play(); // sound of move piece2

            board.destid.piece = board.orgid.piece;
            board.move = "";
        }
    }

        Button{
            id: btn
            text: "کلیک کنید"
            font.family: fontfarsi.name
            onClicked: {
                connection.setPlayer1Name("علی");
                connection.setPlayer2Name("رضا");
            }

        }
    Item {
        id: settings
        width: 300
        height: mainBoard.height

        ToolSeparator{
            width: 1.2
            height: settings.height / 1.1
            anchors.verticalCenter: settings.verticalCenter
            anchors.right: settings.right

            Rectangle{
                anchors.fill: parent
                color: "#B0BEC5"
            }
        }

        Column{
            id:nameSection
            anchors.horizontalCenter: settings.horizontalCenter
            anchors.top: settings.top
            anchors.topMargin: 50
            spacing: 15

            Text {
                id: namesec1
                text: qsTr("اسم بازی:")
                font.bold: true
                anchors.horizontalCenter: nameSection.horizontalCenter
                font.pixelSize: 30
                font.family: fontfarsi.name
            }

            Text {
                id: namesec2
                text: qsTr("رو کم کنی")
                font.bold: true
                anchors.horizontalCenter: nameSection.horizontalCenter
                font.pixelSize: 30
                font.family: fontfarsi.name
            }
        }

        ToolSeparator{
            height: 1
            width: settings.width / 1.5
            anchors.horizontalCenter: settings.horizontalCenter
            anchors.top: nameSection.bottom
            anchors.topMargin: 50
            Rectangle{
                anchors.fill: parent
                color: "#B0BEC5"
            }
        }

        MouseArea {
            id:undobtn
            width: 50
            height: 55
            anchors.horizontalCenter: settings.horizontalCenter
            anchors.bottom: btns.top
            anchors.bottomMargin: 90

            Rectangle{
                anchors.fill: parent
                radius: 15
                color: "#B0BEC5"
                Material.elevation: 6

                Image {
                    id: undoimg
                    source: "media/Left Arrow 1.png"
                    anchors.centerIn: parent
                }
            }
        }

        Text {
            id: undotxt
            text: qsTr("UNDO")
            font.pixelSize: 20
            anchors.horizontalCenter: settings.horizontalCenter
            anchors.top: undobtn.bottom
            anchors.topMargin: 10
            font.family: fontfarsi.name
        }

        ToolSeparator{
            height: 1
            width: settings.width / 2.5
            anchors.horizontalCenter: settings.horizontalCenter
            anchors.top: undotxt.bottom
            anchors.topMargin: 10
            Rectangle{
                anchors.fill: parent
                color: "#B0BEC5"
            }
        }



        Column {
            id: btns
            anchors.horizontalCenter: settings.horizontalCenter
            anchors.bottom: settings.bottom
            anchors.bottomMargin: 50

            Button{
                id: stratbtn
                text: "شروع مجدد"
                anchors.horizontalCenter: btns.horizontalCenter
                width: 140
                height: 70
                font.family: fontfarsi.name
                font.pixelSize: 20
            }
            Button{
                id: leftbtn
                text: "انصراف"
                anchors.horizontalCenter: btns.horizontalCenter
                width: 140
                height: 70
                font.family: fontfarsi.name
                font.pixelSize: 20
            }
            Button{
                id: settingbtn
                text: "تنظیمات"
                anchors.horizontalCenter: btns.horizontalCenter
                width: 140
                height: 70
                font.family: fontfarsi.name
                font.pixelSize: 20
            }
            Button{
                id: exit
                text: "خروج"
                anchors.horizontalCenter: btns.horizontalCenter
                width: 140
                height: 70
                font.family: fontfarsi.name
                font.pixelSize: 20
            }
        }
    }

    property string colorBoard: "#795548" // color's of A/8 and 1/8 of board of chess

    Row{
        id: alphas
        anchors.top: mainBoard.top
        anchors.topMargin: 40
        anchors.horizontalCenter: mainBoard.horizontalCenter
        anchors.left: board.left
        anchors.leftMargin: 5
        spacing: 10

        Item {
            id: a
            width: 85
            height: 85
            Text{
                text: "A"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: a.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: b
            width: 85
            height: 85
            Text{
                text: "B"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: b.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: c
            width: 85
            height: 85
            Text{
                text: "C"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: c.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: d
            width: 85
            height: 85
            Text{
                text: "D"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: d.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: e
            width: 85
            height: 85
            Text{
                text: "E"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: e.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: f
            width: 85
            height: 85
            Text{
                text: "F"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: f.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: g
            width: 85
            height: 85
            Text{
                text: "G"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: g.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: h
            width: 85
            height: 85
            Text{
                text: "H"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: h.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }


    }

    Column{
        id: numbers
        anchors.top: mainBoard.top
        anchors.topMargin: 130
        anchors.horizontalCenter: mainBoard.horizontalCenter
        anchors.left: board.right
        anchors.leftMargin: 0
        spacing: 10


        Item {
            id: eight
            width: 20
            height: 80
            Text{
                text: "8"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: eight.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: seven
            width: 20
            height: 80
            Text{
                text: "7"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: seven.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: six
            width: 20
            height: 80
            Text{
                text: "6"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: six.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: five
            width: 20
            height: 80
            Text{
                text: "5"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: five.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: four
            width: 20
            height: 80
            Text{
                text: "4"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: four.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: three
            width: 20
            height: 80
            Text{
                text: "3"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: three.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: two
            width: 20
            height: 80
            Text{
                text: "2"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: two.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

        Item {
            id: one
            width: 20
            height: 80
            Text{
                text: "1"
                font.pixelSize: 40
                font.bold: true
                anchors.horizontalCenter: one.horizontalCenter
                font.family: fontfarsi.name
                color: colorBoard
                font.underline: true
            }
        }

    }

    Item {
        id: board
        width: 813
        height: 720
        anchors.verticalCenter: mainBoard.verticalCenter
        anchors.left: mainBoard.left
        anchors.leftMargin: 560
        property string move: ""

        // access to id's with var
        property var orgid: null
        property var orgimg: null
        property var destid: null
        property var destimg: null
        property int orgx: 0
        property int orgy: 0


        // function for save org and dest id cell's
        function saveId(myid, imgid)
        {
            if(move === "")
            {
                orgid = myid;
                orgimg = imgid;
                board.orgx = myid.x;
                board.orgy = myid.y;
            } else
            {
                destid = myid;
                destimg = imgid;
            }
        }

        // animation for move pieces in board
        ParallelAnimation{
            id: moveAnimation
            running: false

            property int tox: 0
            property int toy: 0

            NumberAnimation {
                target: board.orgid
                properties: "x"
                to: moveAnimation.tox
                duration: 1200
                easing.type: Easing.OutCubic
            }

            NumberAnimation {
                target: board.orgid
                property: "y"
                to: moveAnimation.toy
                duration: 1200
                easing.type: Easing.OutCubic
            }

            onRunningChanged: {
                if(running === false)
                {
                    // update destination piece
                    board.destimg.source = board.orgimg.source;

                    // update origin piece
                    board.orgid.piece = "";
                    board.orgimg.source = "";

                    // return org cell to orginal place
                    board.orgid.x = board.orgx;
                    board.orgid.y = board.orgy;
                }
            }
        }

        // sound of move piece

        Audio{
            id: movePieceSound
            source: "media/Sound/movePiece.WAV"
            volume: 1.0
        }




        BorderImage
        {
            id: chessboard
            source: "media/Group 35.jpg"
            anchors.fill: parent
            anchors.rightMargin: 58
            border.left: 5; border.top: 5
            border.right: 5; border.bottom: 5
        }

        MouseArea{
            id:a1
            cursorShape: Qt.ArrowCursor
            property string id: "a1"
            property string piece: "R"
            x: 8
            y: 635
            width: 85
            height: 85

            Image {
                id: a1Img
                source: "media/White/R.png"
                anchors.fill: parent
            }

            onClicked: {
                board.saveId(this, a1Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
            }

        MouseArea{
            id:h1
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 631
            width: 85
            height: 85
            property string id: "h1"
            property string piece: "R"
            Image {
                id: h1Img
                source: "media/White/R.png"
                anchors.fill: parent
                }
            onClicked: {
                board.saveId(this, h1Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:d1
            cursorShape: Qt.ArrowCursor
            x: 287
            y: 631
            width: 85
            height: 85
            property string id: "d1"
            property string piece: "Q"

            Image {
                id: d1Img
                anchors.fill: parent
                source: "media/White/Q.png"
            }

            onClicked: {
                board.saveId(this, d1Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:e1
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 631
            width: 85
            height: 85
            property string id: "e1"
            property string piece: "K"
            Image {
                id: e1Img
                anchors.fill: parent
                source: "media/White/K.png"
            }
            onClicked: {
                board.saveId(this, e1Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:f1
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 631
            width: 85
            height: 85
            property string id: "f1"
            property string piece: "B"

            Image {
                id: f1Img
                anchors.fill: parent
                source: "media/White/B.png"
                }
            onClicked: {
                board.saveId(this, f1Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:c1
            cursorShape: Qt.ArrowCursor
            x: 198
            y: 631
            width: 85
            height: 85
            property string id: "c1"
            property string piece: "B"
            Image {
                id:c1Img
                anchors.fill: parent
                source: "media/White/B.png"
            }
            onClicked: {
                board.saveId(this, c1Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:b1
            cursorShape: Qt.ArrowCursor
            x: 98
            y: 631
            width: 85
            height: 85
            property string id: "b1"
            property string piece: "H"


        Image {
            id: b1Img
            anchors.fill: parent
            source: "media/White/H.png"
            }
        onClicked: {
            board.saveId(this, b1Img);
                    board.move = Func.checkMove(board.move, id, piece);
                    if(Func.validation(board.move))
                    {
                        connection.setOrder(board.move);
                    }
                }
        }

        MouseArea{
            id:g1
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 631
            width: 85
            height: 85
            property string id: "g1"
            property string piece: "H"

            Image {
                id: g1Img
                anchors.fill: parent
                source: "media/White/H.png"
                }
            onClicked: {
                board.saveId(this, g1Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:a2
            cursorShape: Qt.ArrowCursor
            x: 7
            y: 538
            width: 85
            height: 85
            property string id: "a2"
            property string piece: "P"
            Image {
                id: a2Img
                anchors.fill: parent
                source: "media/White/P.png"
                }
            onClicked: {
                board.saveId(this, a2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:b2
            cursorShape: Qt.ArrowCursor
            x: 98
            y: 538
            width: 85
            height: 85
            property string id: "b2"
            property string piece: "P"

            Image {
                id: b2Img
                anchors.fill: parent
                source: "media/White/P.png"
                }
            onClicked: {
                board.saveId(this, b2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }

        }

        MouseArea{
            id:c2
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 539
            width: 85
            height: 85
            property string id: "c2"
            property string piece: "P"

            Image {
                id: c2Img
                anchors.fill: parent
                source: "media/White/P.png"
                }
            onClicked: {
                board.saveId(this, c2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:d2
            cursorShape: Qt.ArrowCursor
            x: 284
            y: 538
            width: 85
            height: 85
            property string id: "d2"
            property string piece: "P"

            Image {
                id: d2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
            onClicked: {
                board.saveId(this, d2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }


        MouseArea{
            id:e2
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 539
            width: 85
            height: 85
            property string id: "e2"
            property string piece: "P"

            Image {
                id: e2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
            onClicked: {
                board.saveId(this, e2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:f2
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 538
            width: 85
            height: 85
            property string id: "f2"
            property string piece: "P"

            Image {
                id: f2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
            onClicked: {
                board.saveId(this, f2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:g2
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 538
            width: 85
            height: 85
            property string id: "g2"
            property string piece: "P"
            Image {
                id: g2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
            onClicked: {
                board.saveId(this, g2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:h2
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 540
            width: 85
            height: 85
            property string id: "h2"
            property string piece: "P"

            Image {
                id: h2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
            onClicked: {
                board.saveId(this, h2Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // black piece start

        MouseArea{
            id:a8
            cursorShape: Qt.ArrowCursor
            x: 5
            y: 0
            width: 85
            height: 85
            property string id: "a8"
            property string piece: "R"

            Image {
                id: a8Img
                anchors.fill: parent
                source: "media/Black/R.png"
            }
            onClicked: {
                board.saveId(this, a8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:h8
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 3
            width: 85
            height: 85
            property string id: "h8"
            property string piece: "R"

            Image {
                id: h8Img
                anchors.fill: parent
                source: "media/Black/R.png"
            }
            onClicked: {
                board.saveId(this, h8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:d8
            cursorShape: Qt.ArrowCursor
            x: 284
            y: 2
            width: 85
            height: 85
            property string id: "d8"
            property string piece: "Q"

            Image {
                id: d8Img
                anchors.rightMargin: -4
                anchors.bottomMargin: 0
                anchors.leftMargin: 4
                anchors.topMargin: 0
                anchors.fill: parent
                source: "media/Black/Q.png"
            }
            onClicked: {
                board.saveId(this, d8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:e8
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 0
            width: 85
            height: 85
            property string id: "e8"
            property string piece: "K"

            Image {
                id: e8Img
                anchors.fill: parent
                source: "media/Black/K.png"
            }
            onClicked: {
                board.saveId(this, e8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:f8
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 1
            width: 85
            height: 85
            property string id: "f8"
            property string piece: "B"

            Image {
                id: f8Img
                anchors.fill: parent
                source: "media/Black/B.png"
            }
            onClicked: {
                board.saveId(this, f8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:c8
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 2
            width: 85
            height: 85
            property string id: "c8"
            property string piece: "B"

            Image {
                id: c8Img
                anchors.rightMargin: -1
                anchors.bottomMargin: 0
                anchors.leftMargin: 1
                anchors.topMargin: 0
                anchors.fill: parent
                source: "media/Black/B.png"
            }
            onClicked: {
                board.saveId(this, c8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:g8
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 0
            width: 85
            height: 85
            property string id: "g8"
            property string piece: "H"

            Image {
                id: g8Img
                anchors.fill: parent
                source: "media/Black/H.png"
            }
            onClicked: {
                board.saveId(this, g8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:b8
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 2
            width: 85
            height: 85
            property string id: "b8"
            property string piece: "H"

            Image {
                id: b8Img
                anchors.fill: parent
                source: "media/Black/H.png"
            }
            onClicked: {
                board.saveId(this, b8Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:a7
            cursorShape: Qt.ArrowCursor
            x: 5
            y: 90
            width: 85
            height: 85
            property string id: "a7"
            property string piece: "P"

            Image {
                id: a7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }
            onClicked: {
                board.saveId(this, a7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:b7
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 90
            width: 85
            height: 85
            property string id: "b7"
            property string piece: "P"

            Image {
                id: b7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }
            onClicked: {
                board.saveId(this, b7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:c7
            cursorShape: Qt.ArrowCursor
            x: 195
            y: 90
            width: 85
            height: 85
            property string id: "c7"
            property string piece: "P"

            Image {
                id: c7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }
            onClicked: {
                board.saveId(this, c7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:d7
            cursorShape: Qt.ArrowCursor
            x: 289
            y: 90
            width: 85
            height: 85
            property string id: "d7"
            property string piece: "P"

            Image {
                id: d7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }

            onClicked: {
                board.saveId(this, d7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:e7
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 90
            width: 85
            height: 85
            property string id: "e7"
            property string piece: "P"

            Image {
                id: e7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }

            onClicked: {
                board.saveId(this, e7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:f7
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 90
            width: 85
            height: 85
            property string id: "f7"
            property string piece: "P"

            Image {
                id: f7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }
            onClicked: {
                board.saveId(this, f7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:g7
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 90
            width: 85
            height: 85
            property string id: "g7"
            property string piece: "P"

            Image {
                id: g7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }
            onClicked: {
                board.saveId(this, g7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:h7
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 90
            width: 85
            height: 85
            property string id: "h7"
            property string piece: "P"

            Image {
                id: h7Img
                anchors.fill: parent
                source: "media/Black/P.png"
            }

            onClicked: {
                board.saveId(this, h7Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // another cell's

        // h Column

        MouseArea{
            id:h6
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 185
            width: 85
            height: 85
            property string id: "h6"
            property string piece: ""

            Image {
                id: h6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, h6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:h5
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 272
            width: 85
            height: 85
            property string id: "h5"
            property string piece: ""

            Image {
                id: h5Img
                anchors.fill: parent
                source: ""
            }

            onClicked: {
                board.saveId(this, h5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:h4
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 360
            width: 85
            height: 85
            property string id: "h4"
            property string piece: ""
//            Rectangle{
//                anchors.fill: parent
//                color: "#000"
//            }

            Image {
                id: h4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, h4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:h3
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 447
            width: 85
            height: 85
            property string id: "h3"
            property string piece: ""

            Image {
                id: h3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, h3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

        // g's Column

        MouseArea{
            id:g6
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 185
            width: 85
            height: 85
            property string id: "g6"
            property string piece: ""

            Image {
                id: g6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, g6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:g5
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 272
            width: 85
            height: 85
            property string id: "g5"
            property string piece: ""

            Image {
                id: g5Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, g5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:g4
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 360
            width: 85
            height: 85
            property string id: "g4"
            property string piece: ""

            Image {
                id: g4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, g4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:g3
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 447
            width: 85
            height: 85
            property string id: "g3"
            property string piece: ""

            Image {
                id: g3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, g3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

        // f's Column

        MouseArea{
            id:f6
            cursorShape: Qt.ArrowCursor
            x: 476
            y: 185
            width: 85
            height: 85
            property string id: "f6"
            property string piece: ""

            Image {
                id: f6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, f6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:f5
            cursorShape: Qt.ArrowCursor
            x: 476
            y: 272
            width: 85
            height: 85
            property string id: "f5"
            property string piece: ""

            Image {
                id: f5Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, f5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:f4
            cursorShape: Qt.ArrowCursor
            x: 476
            y: 360
            width: 85
            height: 85
            property string id: "f4"
            property string piece: ""

            Image {
                id: f4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, f4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:f3
            cursorShape: Qt.ArrowCursor
            x: 476
            y: 447
            width: 85
            height: 85
            property string id: "f3"
            property string piece: ""

            Image {
                id: f3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, f3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

        // e's Column

        MouseArea{
            id:e6
            cursorShape: Qt.ArrowCursor
            x: 380
            y: 180
            width: 85
            height: 85
            property string id: "e6"
            property string piece: ""

            Image {
                id: e6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, e6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:e5
            cursorShape: Qt.ArrowCursor
            x: 381
            y: 267
            width: 85
            height: 85
            property string id: "e5"
            property string piece: ""

            Image {
                id: e5Img
                anchors.rightMargin: 0
                anchors.bottomMargin: -3
                anchors.leftMargin: 0
                anchors.topMargin: 3
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, e5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:e4
            cursorShape: Qt.ArrowCursor
            x: 381
            y: 360
            width: 85
            height: 85
            property string id: "e4"
            property string piece: ""

            Image {
                id: e4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, e4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:e3
            cursorShape: Qt.ArrowCursor
            x: 381
            y: 450
            width: 85
            height: 85
            property string id: "e3"
            property string piece: ""

            Image {
                id: e3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, e3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

        // d's Column

        MouseArea{
            id:d6
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 185
            width: 85
            height: 85
            property string id: "d6"
            property string piece: ""

            Image {
                id: d6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, d6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:d5
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 267
            width: 85
            height: 85
            property string id: "d5"
            property string piece: ""

            Image {
                id: d5Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, d5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:d4
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 360
            width: 85
            height: 85
            property string id: "d4"
            property string piece: ""

            Image {
                id: d4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, d4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:d3
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 450
            width: 85
            height: 85
            property string id: "d3"
            property string piece: ""


            Image {
                id: d3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, d3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

        // c's Column


        MouseArea{
            id:c6
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 185
            width: 85
            height: 85
            property string id: "c6"
            property string piece: ""

            Image {
                id: c6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, c6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:c5
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 267
            width: 85
            height: 85
            property string id: "c5"
            property string piece: ""

            Image {
                id: c5Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, c5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:c4
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 360
            width: 85
            height: 85
            property string id: "c4"
            property string piece: ""

            Image {
                id: c4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, c4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:c3
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 450
            width: 85
            height: 85
            property string id: "c3"
            property string piece: ""

            Image {
                id: c3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, c3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

        // b's Column

        MouseArea{
            id:b6
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 185
            width: 85
            height: 85
            property string id: "b6"
            property string piece: ""

            Image {
                id: b6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, b6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:b5
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 267
            width: 85
            height: 85
            property string id: "b5"
            property string piece: ""

            Image {
                id: b5Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, b5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:b4
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 360
            width: 85
            height: 85
            property string id: "b4"
            property string piece: ""

            Image {
                id: b4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, b4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:b3
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 450
            width: 85
            height: 85
            property string id: "b3"
            property string piece: ""

            Image {
                id: b3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, b3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

        // a's Column

        MouseArea{
            id:a6
            cursorShape: Qt.ArrowCursor
            x: 5
            y: 185
            width: 85
            height: 85
            property string id: "a6"
            property string piece: ""

            Image {
                id: a6Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, a6Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:a5
            cursorShape: Qt.ArrowCursor
            x: 5
            y: 267
            width: 85
            height: 85
            property string id: "a5"
            property string piece: ""

            Image {
                id: a5Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, a5Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:a4
            cursorShape: Qt.ArrowCursor
            x: 5
            y: 360
            width: 85
            height: 85
            property string id: "a4"
            property string piece: ""

            Image {
                id: a4Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, a4Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        MouseArea{
            id:a3
            cursorShape: Qt.ArrowCursor
            x: 5
            y: 450
            width: 85
            height: 85
            property string id: "a3"
            property string piece: ""

            Image {
                id: a3Img
                anchors.fill: parent
                source: ""
            }
            onClicked: {
                board.saveId(this, a3Img);
                        board.move = Func.checkMove(board.move, id, piece);
                        if(Func.validation(board.move))
                        {
                            connection.setOrder(board.move);
                        }
                    }
        }

        // end

    }

    Item {
        id: player1Piece
        anchors.left: mainBoard.left
        anchors.leftMargin: 350
        anchors.verticalCenter: settings.verticalCenter
        width: 200
        height: 700

        ToolSeparator{
            width: 1
            height: settings.height / 1.2
            anchors.horizontalCenter: player1Piece.horizontalCenter
            anchors.verticalCenter: player1Piece.verticalCenter

            Rectangle{
                anchors.fill: parent
                color: "#B0BEC5"
            }
        }
        Column{
            width: player1Piece.width / 2
            anchors.left: player1Piece.left

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }

            Image {
                source: "media/White/K.png"
                width: 70
                height: 70
            }
        }

    }

    Item {
        id: player2Piece
        anchors.right: mainBoard.right
        anchors.rightMargin: 340
        anchors.verticalCenter: settings.verticalCenter
        width: 200
        height: 700

        ToolSeparator{
            width: 1
            height: settings.height / 1.2
            anchors.horizontalCenter: player2Piece.horizontalCenter
            anchors.verticalCenter: player2Piece.verticalCenter

            Rectangle{
                anchors.fill: parent
                color: "#B0BEC5"
            }
        }
    }

    Item {
        id: scores
        width: 300
        height: mainBoard.height
        anchors.right: mainBoard.right

        ToolSeparator
        {
            width: 1.2
            height: scores.height / 1.1
            anchors.verticalCenter: scores.verticalCenter
            anchors.left: scores.left
            Rectangle{
                anchors.fill: parent
                color: "#B0BEC5"
            }
        }

        Column
        {
            id: scoreTitle
            anchors.horizontalCenter: scores.horizontalCenter
            anchors.top: scores.top
            anchors.topMargin: 50

            Text {
                id: scoreName
                text: qsTr("امتیاز ها")
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: fontfarsi.name
                font.pixelSize: 30
            }
        }

        ToolSeparator{
            width: scores.width / 1.7
            height: 1
            anchors.horizontalCenter: scores.horizontalCenter
            anchors.top: scoreTitle.bottom
            anchors.topMargin: 50

            Rectangle{
                anchors.fill: parent
                color: "#B0BEC5"
            }
        }


        Column{
            id: player1scores
            spacing: 10
            anchors.top: scoreTitle.bottom
            width: scores.width
            anchors.topMargin: 120

            Image {
                id: player1pic
                anchors.horizontalCenter: player1scores.horizontalCenter
                source: "media/whiteking.png"
                width: 130
                height: 120
            }

            Text {
                id: element
                anchors.horizontalCenter: player1scores.horizontalCenter
                text: qsTr("امتیاز ") + qsTr(connection.player1Name) + qsTr(":")
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: fontfarsi.name
            }

            Text {
                id: pscoreplayer1
                anchors.horizontalCenter: player1scores.horizontalCenter
                text: connection.player1PScore
                font.pixelSize: 20
                font.family: fontfarsi.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: element1
                anchors.horizontalCenter: player1scores.horizontalCenter
                text: qsTr("امتیاز منفی ") + qsTr(connection.player1Name) + qsTr(":")
                font.pixelSize: 20
                font.family: fontfarsi.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: element3
                anchors.horizontalCenter: player1scores.horizontalCenter
                text: connection.player1NScore
                font.pixelSize: 20
                font.family: fontfarsi.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

    ToolSeparator{
        width: scores.width / 1.7
        height: 1
        anchors.horizontalCenter: scores.horizontalCenter
        anchors.top: player1scores.bottom
        anchors.topMargin: 50

        Rectangle{
            anchors.fill: parent
            color: "#B0BEC5"
        }
    }

    Column{
        id: player2scores
        spacing: 10
        anchors.top: player1scores.bottom
        width: scores.width
        anchors.topMargin: 120

        Image {
            id: player2pic
            anchors.horizontalCenter: player2scores.horizontalCenter
            source: "media/blackking.png"
            width: 130
            height: 120
        }

        Text {
            id: element4
            anchors.horizontalCenter: player2scores.horizontalCenter
            text: qsTr("امتیاز ") + qsTr(connection.player2Name) + qsTr(":")
            font.family: fontfarsi.name
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: element5
            anchors.horizontalCenter: player2scores.horizontalCenter
            text: connection.player2PScore
            font.pixelSize: 20
            font.family: fontfarsi.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: element6
            anchors.horizontalCenter: player2scores.horizontalCenter
            text: qsTr("امتیاز منفی ") + qsTr(connection.player2Name) + qsTr(":")
            font.pixelSize: 20
            font.family: fontfarsi.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: element7
            anchors.horizontalCenter: player2scores.horizontalCenter
            text: connection.player2NScore
            font.pixelSize: 20
            font.family: fontfarsi.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    ToolSeparator{
        width: scores.width / 1.7
        height: 1
        anchors.horizontalCenter: scores.horizontalCenter
        anchors.top: player2scores.bottom
        anchors.topMargin: 50
    }
}
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
