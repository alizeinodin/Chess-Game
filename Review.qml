import QtQuick 2.13
import QtQuick.Controls 2.13

Page{
    id: pageReview
    anchors.fill: parent
    Connections{
        target: connection
        onEnd:{
            Component.onC
        }
    }

    Item {
        id: reviewgame
        anchors.leftMargin: 100
        //        anchors.horizontalCenter: pageReview.horizontalCenter

        ScrollView {
            id: scrollView
            anchors.fill: parent

            Grid {
                id: gridView
                spacing: 15
                anchors.fill: parent
                //                flow: Grid.TopToBottom

                GroupBox {
                    id: groupBox
                    width: 250
                    height: 200


                    Text {
                        id: name
                        width: 176
                        height: 21
                        text: connection.getgamename(index)
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                    }
                    /*
                Repeater
                {
                    id:rep
                    model: connection.getindexgame()
                    anchors.fill: parent
                    GroupBox {
                        id: groupBox
                        width: 250
                        height: 200


                        Text {
                            id: name
                            width: 176
                            height: 21
                            text: connection.getgamename(index)
                            horizontalAlignment: Text.AlignHCenter
                            font.bold: true
                        }
                        Button
                        {
                            id:b
                            width: 167
                            height: 40
                            text:"Exam"
                            onClicked: {
                                MyHandler.exam(index)
                                stackView.push("exam.qml")
                            }
                        }

                        Button
                        {
                            id:b2
                            width: 167
                            height: 40
                            text: "Scores"
                            onClicked: MyHandler.score(index)
                        }
                    }

                }
                */

                }
            }





            }
        }
    }

    /*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
