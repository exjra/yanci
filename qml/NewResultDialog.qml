import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.1

Dialog {
    property var mGamer;

    function showTotalNumbersCount()
    {
        totalNumberResult.text = "Toplam: " + mGamer.calculateNewNumbers() * (swDelete.position < 1 ? 1 : 2);
    }

    modal: true
    title: "Sonuç Ekle: " + mGamer.name
    standardButtons: Dialog.Ok | Dialog.Cancel

    x: gameMainPage.x
    y: gameMainPage.y
    width: gameMainPage.width
    height: gameMainPage.height

    contentItem: ColumnLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "transparent"

            RowLayout {
                anchors.fill: parent
                spacing: 2

                Repeater {
                    model: mGamer.newNumbers

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumWidth: 10

                        color: "white"
                        border.width: 1

                        Text {
                            anchors.fill: parent
                            text: model.modelData
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            font.pixelSize: Qt.application.font.pixelSize * 1.6
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                mGamer.removeFromNewNumberList(index);
                                showTotalNumbersCount();
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "transparent"

            RowLayout {
                anchors.fill: parent
                spacing: 2

                Switch {
                    id: swDelete
                    text: position < 1 ? "Tek" : "Çift"
                    checked: mResult.deleted

                    onPositionChanged: {
                        showTotalNumbersCount();
                    }
                }

                Label {
                    id: totalNumberResult
                    //            Layout.fillWidth: true
                    //            Layout.fillHeight: true
                    text: "Toplam: 0"
                    font.pixelSize: Qt.application.font.pixelSize * 2.0
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    Layout.alignment: Qt.AlignHCenter
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "transparent"

            RowLayout {
                anchors.fill: parent
                spacing: 2

                Repeater {
                    model: 6

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumWidth: 10

                        color: "white"
                        border.width: 1

                        Text {
                            id: tNumber1
                            anchors.fill: parent
                            text: model.modelData + 1
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            font.pixelSize: Qt.application.font.pixelSize * 1.6
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                mGamer.addToNewNumberList(parseInt(tNumber1.text));
                                showTotalNumbersCount();
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "transparent"

            RowLayout {
                anchors.fill: parent
                spacing: 2

                Repeater {
                    model: 7

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumWidth: 10

                        color: "white"
                        border.width: 1

                        Text {
                            id: tNumber2
                            anchors.fill: parent
                            text: model.modelData + 7
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            font.pixelSize: Qt.application.font.pixelSize * 1.6
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                mGamer.addToNewNumberList(parseInt(tNumber2.text));
                                showTotalNumbersCount();
                            }
                        }
                    }
                }
            }
        }
    }

    onAccepted: {

    }

    onRejected: {

    }
}
