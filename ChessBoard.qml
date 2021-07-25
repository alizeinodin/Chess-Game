import QtQuick 2.0
import "media"
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls.Styles 1.4

Item {
    id: mainBoard
//    anchors.fill: parent
    width: 1500
    height: 950

    BorderImage{
        id: bg
        source: ""
        anchors.fill: parent
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: 5
    }

    Item {
        id: settings
        width: 150
        height: 950
        Rectangle{
            anchors.fill: parent
        }
    }

    Item {
        id: board
        width: 850
        height: 850
        anchors.verticalCenter: mainBoard.verticalCenter
        anchors.right: mainBoard.right
        anchors.rightMargin: 350


        BorderImage
        {
            id: chessboard
            source: "media/chessboard.png"
            anchors.fill: parent
            border.left: 5; border.top: 5
            border.right: 5; border.bottom: 5
        }

        MouseArea{
            id:a1
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 749
            width: 100
            height: 100

            Image {
                id: rook1
                source: "media/White/Frame 16.png"
                anchors.fill: parent
            }
        }

        MouseArea{
            id:h1
            cursorShape: Qt.OpenHandCursor
            x: 692
            y: 749
            width: 100
            height: 100

            Image {
                id: rook2
                source: "media/White/Frame 16.png"
                anchors.fill: parent
                }
        }

        MouseArea{
            id:d1
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 750
            width: 100
            height: 100

            Image {
                id: queen
                anchors.fill: parent
                source: "media/White/Frame 17.png"
            }
        }

        MouseArea{
            id:e1
            cursorShape: Qt.OpenHandCursor
            x: 395
            y: 749
            width: 100
            height: 100
            Image {
                id: king
                anchors.fill: parent
                source: "media/White/Frame 18.png"
            }
        }

        MouseArea{
            id:f1
            cursorShape: Qt.OpenHandCursor
            x: 493
            y: 749
            width: 100
            height: 100

            Image {
                id: bishop2
                anchors.fill: parent
                source: "media/White/Frame 19.png"
                }
        }

        MouseArea{
            id:c1
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 749
            width: 100
            height: 100
            Image {
                id: bishop1
                anchors.fill: parent
                source: "media/White/Frame 19.png"
            }
        }

        MouseArea{
            id:b1
            cursorShape: Qt.OpenHandCursor
            x: 100
            y: 750
            width: 100
            height: 100

        Image {
            id: knight1
            anchors.fill: parent
            source: "media/White/Frame 20.png"
            }
        }

        MouseArea{
            id:g1
            cursorShape: Qt.OpenHandCursor
            x: 591
            y: 750
            width: 100
            height: 100

            Image {
                id: knight2
                anchors.fill: parent
                source: "media/White/Frame 20.png"
                }
        }

        MouseArea{
            id:a2
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 650
            width: 100
            height: 100
            Image {
                id: pawn1
                anchors.fill: parent
                source: "media/White/Frame 21.png"
                }
        }

        MouseArea{
            id:b2
            cursorShape: Qt.OpenHandCursor
            x: 100
            y: 650
            width: 100
            height: 100

            Image {
                id: pawn2
                anchors.fill: parent
                source: "media/White/Frame 21.png"
                }

        }

        MouseArea{
            id:c2
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 650
            width: 100
            height: 100

            Image {
                id: pawn3
                anchors.fill: parent
                source: "media/White/Frame 21.png"
                }
        }

        MouseArea{
            id:d2
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 650
            width: 100
            height: 100

            Image {
                id: pawn4
                anchors.fill: parent
                source: "media/White/Frame 21.png"
            }
        }


        MouseArea{
            id:e2
            cursorShape: Qt.OpenHandCursor
            x: 395
            y: 650
            width: 100
            height: 100

            Image {
                id: pawn5
                anchors.fill: parent
                source: "media/White/Frame 21.png"
            }
        }

        MouseArea{
            id:f2
            cursorShape: Qt.OpenHandCursor
            x: 493
            y: 650
            width: 100
            height: 100

            Image {
                id: pawn6
                anchors.fill: parent
                source: "media/White/Frame 21.png"
            }
        }

        MouseArea{
            id:g2
            cursorShape: Qt.OpenHandCursor
            x: 591
            y: 650
            width: 100
            height: 100

            Image {
                id: pawn7
                anchors.fill: parent
                source: "media/White/Frame 21.png"
            }
        }

        MouseArea{
            id:h2
            cursorShape: Qt.OpenHandCursor
            x: 692
            y: 650
            width: 100
            height: 100

            Image {
                id: pawn8
                anchors.fill: parent
                source: "media/White/Frame 21.png"
            }
        }

        // black piece start

        MouseArea{
            id:a8
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 54
            width: 100
            height: 100

            Image {
                id: brook1
                anchors.fill: parent
                source: "media/Black/Frame 10.png"
            }
        }

        MouseArea{
            id:h8
            cursorShape: Qt.OpenHandCursor
            x: 692
            y: 54
            width: 100
            height: 100

            Image {
                id: brook2
                anchors.fill: parent
                source: "media/Black/Frame 10.png"
            }
        }

        MouseArea{
            id:d8
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 54
            width: 100
            height: 100

            Image {
                id: bqueen
                anchors.fill: parent
                source: "media/Black/Frame 11.png"
            }
        }

        MouseArea{
            id:e8
            cursorShape: Qt.OpenHandCursor
            x: 395
            y: 54
            width: 100
            height: 100

            Image {
                id: bking
                anchors.fill: parent
                source: "media/Black/Frame 12.png"
            }
        }

        MouseArea{
            id:f8
            cursorShape: Qt.OpenHandCursor
            x: 493
            y: 54
            width: 100
            height: 100

            Image {
                id: bbishop1
                anchors.fill: parent
                source: "media/Black/Frame 13.png"
            }
        }

        MouseArea{
            id:c8
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 54
            width: 100
            height: 100

            Image {
                id: bbishop2
                anchors.fill: parent
                source: "media/Black/Frame 13.png"
            }
        }

        MouseArea{
            id:g8
            cursorShape: Qt.OpenHandCursor
            x: 591
            y: 54
            width: 100
            height: 100

            Image {
                id: bknight1
                anchors.fill: parent
                source: "media/Black/Frame 14.png"
            }
        }

        MouseArea{
            id:b8
            cursorShape: Qt.OpenHandCursor
            x: 100
            y: 54
            width: 100
            height: 100

            Image {
                id: bknight2
                anchors.fill: parent
                source: "media/Black/Frame 14.png"
            }
        }

        MouseArea{
            id:a7
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn1
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        MouseArea{
            id:b7
            cursorShape: Qt.OpenHandCursor
            x: 100
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn2
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        MouseArea{
            id:c7
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn3
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        MouseArea{
            id:d7
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn4
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        MouseArea{
            id:e7
            cursorShape: Qt.OpenHandCursor
            x: 395
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn5
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        MouseArea{
            id:f7
            cursorShape: Qt.OpenHandCursor
            x: 493
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn6
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        MouseArea{
            id:g7
            cursorShape: Qt.OpenHandCursor
            x: 591
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn7
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        MouseArea{
            id:h7
            cursorShape: Qt.OpenHandCursor
            x: 692
            y: 154
            width: 100
            height: 100

            Image {
                id: bpawn8
                anchors.fill: parent
                source: "media/Black/Frame 15.png"
            }
        }

        // another cell's

        // h Column

        MouseArea{
            id:h6
            cursorShape: Qt.OpenHandCursor
            x: 690
            y: 254
            width: 100
            height: 100

            Image {
                id: h6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:h5
            cursorShape: Qt.OpenHandCursor
            x: 690
            y: 354
            width: 100
            height: 100

            Image {
                id: h5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:h4
            cursorShape: Qt.OpenHandCursor
            x: 690
            y: 454
            width: 100
            height: 100

            Image {
                id: h4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:h3
            cursorShape: Qt.OpenHandCursor
            x: 690
            y: 554
            width: 100
            height: 100

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
            cursorShape: Qt.OpenHandCursor
            x: 592
            y: 254
            width: 100
            height: 100

            Image {
                id: g6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:g5
            cursorShape: Qt.OpenHandCursor
            x: 592
            y: 354
            width: 100
            height: 100

            Image {
                id: g5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:g4
            cursorShape: Qt.OpenHandCursor
            x: 592
            y: 454
            width: 100
            height: 100

            Image {
                id: g4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:g3
            cursorShape: Qt.OpenHandCursor
            x: 592
            y: 554
            width: 100
            height: 100

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
            cursorShape: Qt.OpenHandCursor
            x: 492
            y: 254
            width: 100
            height: 100

            Image {
                id: f6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:f5
            cursorShape: Qt.OpenHandCursor
            x: 492
            y: 354
            width: 100
            height: 100

            Image {
                id: f5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:f4
            cursorShape: Qt.OpenHandCursor
            x: 492
            y: 454
            width: 100
            height: 100

            Image {
                id: f4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:f3
            cursorShape: Qt.OpenHandCursor
            x: 492
            y: 554
            width: 100
            height: 100

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
            cursorShape: Qt.OpenHandCursor
            x: 394
            y: 254
            width: 100
            height: 100

            Image {
                id: e6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:e5
            cursorShape: Qt.OpenHandCursor
            x: 394
            y: 354
            width: 100
            height: 100

            Image {
                id: e5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:e4
            cursorShape: Qt.OpenHandCursor
            x: 394
            y: 454
            width: 100
            height: 100

            Image {
                id: e4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:e3
            cursorShape: Qt.OpenHandCursor
            x: 394
            y: 554
            width: 100
            height: 100

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
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 254
            width: 100
            height: 100

            Image {
                id: d6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:d5
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 354
            width: 100
            height: 100

            Image {
                id: d5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:d4
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 454
            width: 100
            height: 100

            Image {
                id: d4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:d3
            cursorShape: Qt.OpenHandCursor
            x: 296
            y: 554
            width: 100
            height: 100

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
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 254
            width: 100
            height: 100

            Image {
                id: c6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:c5
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 354
            width: 100
            height: 100

            Image {
                id: c5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:c4
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 454
            width: 100
            height: 100

            Image {
                id: c4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:c3
            cursorShape: Qt.OpenHandCursor
            x: 198
            y: 554
            width: 100
            height: 100

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
            cursorShape: Qt.OpenHandCursor
            x: 98
            y: 254
            width: 100
            height: 100

            Image {
                id: b6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:b5
            cursorShape: Qt.OpenHandCursor
            x: 98
            y: 354
            width: 100
            height: 100

            Image {
                id: b5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:b4
            cursorShape: Qt.OpenHandCursor
            x: 98
            y: 454
            width: 100
            height: 100

            Image {
                id: b4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:b3
            cursorShape: Qt.OpenHandCursor
            x: 98
            y: 554
            width: 100
            height: 100

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
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 254
            width: 100
            height: 100

            Image {
                id: a6img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:a5
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 354
            width: 100
            height: 100

            Image {
                id: a5img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:a4
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 454
            width: 100
            height: 100

            Image {
                id: a4img
                anchors.fill: parent
                source: ""
            }
        }

        MouseArea{
            id:a3
            cursorShape: Qt.OpenHandCursor
            x: 0
            y: 554
            width: 100
            height: 100

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
        x: 175
        y: 95
        width: 15
        height: 705

        ToolSeparator {
            id: toolSeparator
            anchors.rightMargin: 0
            anchors.bottomMargin: -92
            anchors.leftMargin: 0
            anchors.topMargin: 92
            anchors.fill: parent
        }

        Image {
            id: player2
            x: -42
            y: -52
            source: "media/Black/Frame 12.png"
            width: 100
            height: 100
        }
        Text {
            id: namePlayer2
            x:-27
            y:43
            width: 69
            height: 24
            text: "رضا"
            fontSizeMode: Text.VerticalFit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
        }

    }

    Item {
        id: player2Piece
        x: 1235
        y: 96
        width: 100
        height: 705

        ToolSeparator {
            id: toolSeparator1
            x: 8
            y: -43
            anchors.rightMargin: -8
            anchors.bottomMargin: 40
            anchors.leftMargin: 8
            anchors.topMargin: -40
            height: 705
            width: 15
        }

        Image {
            id: player1
            x: -34
            y: 668
            source: "media/White/Frame 18.png"
            width: 100
            height: 100
        }
        Text {
            id: namePlayer1
            x:-18
            y:767
            width: 69
            height: 24
            text: "علی"
            fontSizeMode: Text.VerticalFit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
        }
    }





}




