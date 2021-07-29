import QtQuick 2.0
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.3
import connect 1.0
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
            property string id: "Ra1"
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
                        board.move += id;
                console.log(board.move);
                    }
        }

        MouseArea{
            id:h1
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 631
            width: 85
            height: 85
            property string id: "Rh1"
            Image {
                id: h1Img
                source: "media/White/R.png"
                anchors.fill: parent
                }
        }

        MouseArea{
            id:d1
            cursorShape: Qt.ArrowCursor
            x: 287
            y: 631
            width: 85
            height: 85
            property string id: "Qd1"

            Image {
                id: d1Img
                anchors.fill: parent
                source: "media/White/Q.png"
            }
        }

        MouseArea{
            id:e1
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 631
            width: 85
            height: 85
            property string id: "Ke1"
            Image {
                id: e1Img
                anchors.fill: parent
                source: "media/White/K.png"
            }
        }

        MouseArea{
            id:f1
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 631
            width: 85
            height: 85
            property string id: "Bf1"

            Image {
                id: f1Img
                anchors.fill: parent
                source: "media/White/B.png"
                }
        }

        MouseArea{
            id:c1
            cursorShape: Qt.ArrowCursor
            x: 198
            y: 631
            width: 85
            height: 85
            property string id: "Bc1"
            Image {
                id:c1Immg
                anchors.fill: parent
                source: "media/White/B.png"
            }
        }

        MouseArea{
            id:b1
            cursorShape: Qt.ArrowCursor
            x: 98
            y: 631
            width: 85
            height: 85
            property string id: "Hb1"


        Image {
            id: b1Img
            anchors.fill: parent
            source: "media/White/H.png"
            }
        }

        MouseArea{
            id:g1
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 631
            width: 85
            height: 85
            property string id: "Hg1"

            Image {
                id: g1Img
                anchors.fill: parent
                source: "media/White/H.png"
                }
        }

        MouseArea{
            id:a2
            cursorShape: Qt.ArrowCursor
            x: 7
            y: 538
            width: 85
            height: 85
            property string id: "Pa2"
            Image {
                id: a2Img
                anchors.fill: parent
                source: "media/White/P.png"
                }
        }

        MouseArea{
            id:b2
            cursorShape: Qt.ArrowCursor
            x: 98
            y: 538
            width: 85
            height: 85
            property string id: "Pb2"

            Image {
                id: b2Img
                anchors.fill: parent
                source: "media/White/P.png"
                }

        }

        MouseArea{
            id:c2
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 539
            width: 85
            height: 85
            property string id: "Pc2"

            Image {
                id: c2Img
                anchors.fill: parent
                source: "media/White/P.png"
                }
        }

        MouseArea{
            id:d2
            cursorShape: Qt.ArrowCursor
            x: 284
            y: 538
            width: 85
            height: 85
            property string id: "Pd2"

            Image {
                id: d2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
        }


        MouseArea{
            id:e2
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 539
            width: 85
            height: 85
            property string id: "Pe2"

            Image {
                id: e2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
        }

        MouseArea{
            id:f2
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 538
            width: 85
            height: 85
            property string id: "Pf2"

            Image {
                id: f2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
        }

        MouseArea{
            id:g2
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 538
            width: 85
            height: 85
            property string id: "Pg2"

            Image {
                id: g2Img
                anchors.fill: parent
                source: "media/White/P.png"
            }
        }

        MouseArea{
            id:h2
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 540
            width: 85
            height: 85
            property string id: "Ph2"

            Image {
                id: h2Img
                anchors.fill: parent
                source: "media/White/P.png"
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
            property string id: "Ra8"

            Image {
                id: brook1
                anchors.fill: parent
                source: "media/Black/R.png"
            }
        }

        MouseArea{
            id:h8
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 3
            width: 85
            height: 85
            property string id: "Rh8"

            Image {
                id: brook2
                anchors.fill: parent
                source: "media/Black/R.png"
            }
        }

        MouseArea{
            id:d8
            cursorShape: Qt.ArrowCursor
            x: 284
            y: 2
            width: 85
            height: 85
            property string id: "Qd8"

            Image {
                id: bqueen
                anchors.rightMargin: -4
                anchors.bottomMargin: 0
                anchors.leftMargin: 4
                anchors.topMargin: 0
                anchors.fill: parent
                source: "media/Black/Q.png"
            }
        }

        MouseArea{
            id:e8
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 0
            width: 85
            height: 85
            property string id: "Ke8"

            Image {
                id: bking
                anchors.fill: parent
                source: "media/Black/K.png"
            }
        }

        MouseArea{
            id:f8
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 1
            width: 85
            height: 85
            property string id: "Bf8"

            Image {
                id: bbishop1
                anchors.fill: parent
                source: "media/Black/B.png"
            }
        }

        MouseArea{
            id:c8
            cursorShape: Qt.ArrowCursor
            x: 193
            y: 2
            width: 85
            height: 85
            property string id: "Bc8"

            Image {
                id: bbishop2
                anchors.rightMargin: -1
                anchors.bottomMargin: 0
                anchors.leftMargin: 1
                anchors.topMargin: 0
                anchors.fill: parent
                source: "media/Black/B.png"
            }
        }

        MouseArea{
            id:g8
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 0
            width: 85
            height: 85
            property string id: "Hg8"

            Image {
                id: bknight1
                anchors.fill: parent
                source: "media/Black/H.png"
            }
        }

        MouseArea{
            id:b8
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 2
            width: 85
            height: 85
            property string id: "Hb8"

            Image {
                id: bknight2
                anchors.fill: parent
                source: "media/Black/H.png"
            }
        }

        MouseArea{
            id:a7
            cursorShape: Qt.ArrowCursor
            x: 5
            y: 90
            width: 85
            height: 85
            property string id: "Pa7"

            Image {
                id: bpawn1
                anchors.fill: parent
                source: "media/Black/P.png"
            }
        }

        MouseArea{
            id:b7
            cursorShape: Qt.ArrowCursor
            x: 100
            y: 90
            width: 85
            height: 85
            property string id: "Pb7"

            Image {
                id: bpawn2
                anchors.fill: parent
                source: "media/Black/P.png"
            }
        }

        MouseArea{
            id:c7
            cursorShape: Qt.ArrowCursor
            x: 195
            y: 90
            width: 85
            height: 85
            property string id: "Pc7"

            Image {
                id: bpawn3
                anchors.fill: parent
                source: "media/Black/P.png"
            }
        }

        MouseArea{
            id:d7
            cursorShape: Qt.ArrowCursor
            x: 289
            y: 90
            width: 85
            height: 85
            property string id: "Pd7"

            Image {
                id: bpawn4
                anchors.fill: parent
                source: "media/Black/P.png"
            }
        }

        MouseArea{
            id:e7
            cursorShape: Qt.ArrowCursor
            x: 382
            y: 90
            width: 85
            height: 85
            property string id: "Pe7"

            Image {
                id: bpawn5
                anchors.fill: parent
                source: "media/Black/P.png"
            }
        }

        MouseArea{
            id:f7
            cursorShape: Qt.ArrowCursor
            x: 473
            y: 90
            width: 85
            height: 85
            property string id: "Pf7"

            Image {
                id: bpawn6
                anchors.fill: parent
                source: "media/Black/P.png"
            }
        }

        MouseArea{
            id:g7
            cursorShape: Qt.ArrowCursor
            x: 570
            y: 90
            width: 85
            height: 85
            property string id: "Pg7"

            Image {
                id: bpawn7
                anchors.fill: parent
                source: "media/Black/P.png"
            }
        }

        MouseArea{
            id:h7
            cursorShape: Qt.ArrowCursor
            x: 665
            y: 90
            width: 85
            height: 85
            property string id: "Ph7"

            Image {
                id: bpawn8
                anchors.fill: parent
                source: "media/Black/P.png"
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

            Image {
                id: h6img
                anchors.fill: parent
                source: ""
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

            Image {
                id: h5img
                anchors.fill: parent
                source: ""
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

            Image {
                id: h4img
                anchors.fill: parent
                source: ""
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

            Image {
                id: h3img
                anchors.fill: parent
                source: ""
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

            Image {
                id: g6img
                anchors.fill: parent
                source: ""
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

            Image {
                id: g5img
                anchors.fill: parent
                source: ""
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

            Image {
                id: g4img
                anchors.fill: parent
                source: ""
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

            Image {
                id: g3img
                anchors.fill: parent
                source: ""
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

            Image {
                id: f6img
                anchors.fill: parent
                source: ""
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

            Image {
                id: f5img
                anchors.fill: parent
                source: ""
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

            Image {
                id: f4img
                anchors.fill: parent
                source: ""
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

            Image {
                id: f3img
                anchors.fill: parent
                source: ""
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

            Image {
                id: e6img
                anchors.fill: parent
                source: ""
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

            Image {
                id: e5img
                anchors.rightMargin: 0
                anchors.bottomMargin: -3
                anchors.leftMargin: 0
                anchors.topMargin: 3
                anchors.fill: parent
                source: ""
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

            Image {
                id: e4img
                anchors.fill: parent
                source: ""
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

            Image {
                id: e3img
                anchors.fill: parent
                source: ""
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

            Image {
                id: d6img
                anchors.fill: parent
                source: ""
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

            Image {
                id: d5img
                anchors.fill: parent
                source: ""
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

            Image {
                id: d4img
                anchors.fill: parent
                source: ""
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

            Image {
                id: d3img
                anchors.fill: parent
                source: ""
            }
        }

        // end

        // c's Column


        MouseArea{
            id:c6
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 185
            width: 85
            height: 85
            property string id: "c6"

            Image {
                id: c6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:c5
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 267
            width: 85
            height: 85
            property string id: "c5"

            Image {
                id: c5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:c4
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 360
            width: 85
            height: 85
            property string id: "c4"

            Image {
                id: c4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:c3
            cursorShape: Qt.ArrowCursor
            x: 288
            y: 450
            width: 85
            height: 85
            property string id: "c3"

            Image {
                id: c3img
                anchors.fill: parent
                source: ""
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

            Image {
                id: b6img
                anchors.fill: parent
                source: ""
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

            Image {
                id: b5img
                anchors.fill: parent
                source: ""
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

            Image {
                id: b4img
                anchors.fill: parent
                source: ""
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

            Image {
                id: b3img
                anchors.fill: parent
                source: ""
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

            Image {
                id: a6img
                anchors.fill: parent
                source: ""
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

            Image {
                id: a5img
                anchors.fill: parent
                source: ""
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

            Image {
                id: a4img
                anchors.fill: parent
                source: ""
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

            Image {
                id: a3img
                anchors.fill: parent
                source: ""
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
                text: qsTr("امتیاز علی:")
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: fontfarsi.name
            }

            Text {
                id: element2
                anchors.horizontalCenter: player1scores.horizontalCenter
                text: qsTr("2982")
                font.pixelSize: 20
                font.family: fontfarsi.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: element1
                anchors.horizontalCenter: player1scores.horizontalCenter
                text: qsTr("امتیاز منفی علی:")
                font.pixelSize: 20
                font.family: fontfarsi.name
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: element3
                anchors.horizontalCenter: player1scores.horizontalCenter
                text: qsTr("12")
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
            text: qsTr("امتیاز رضا:")
            font.family: fontfarsi.name
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: element5
            anchors.horizontalCenter: player2scores.horizontalCenter
            text: qsTr("2982")
            font.pixelSize: 20
            font.family: fontfarsi.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: element6
            anchors.horizontalCenter: player2scores.horizontalCenter
            text: qsTr("امتیاز منفی رضا:")
            font.pixelSize: 20
            font.family: fontfarsi.name
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: element7
            anchors.horizontalCenter: player2scores.horizontalCenter
            text: qsTr("12")
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
