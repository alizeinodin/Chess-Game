import QtQuick 2.0
import QtQuick.Controls 2.13

Page{
    id: pageReview
    anchors.fill: parent
    Item {
        id: reviewgame
        anchors.leftMargin: 100
        //anchors.horizontalCenter: pageReview.horizontalCenter

    ScrollView {
        id: scrollView


        Grid {
            id: gridView
            //anchors.centerIn: pageReview
            spacing: 15

            Repeater
                        {
                            id:rep
                            model: connection.getindexgame()
                            GroupBox {
                                                id: groupBox
                                                x: 157
                                                y: 86
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
                                                    x: 30
                                                    y: 60
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
                                                    x: 30
                                                    y: 119
                                                    width: 167
                                                    height: 40
                                                    text: "Scores"
                                                    onClicked: MyHandler.score(index)
                                                }
                                            }

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
