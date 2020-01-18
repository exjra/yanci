import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.1

Dialog {
    id: root
    property var mGamer;
    property var mIsValued: false;
    property var mIsFinished: false;
    property var mFinishValue: 0;

    function showTotalNumbersCount()
    {
        totalNumberResult.text = "Toplam: " + mGamer.calculateNewNumbers() * (swPaired.position < 1 ? 1 : 2);
    }

    function getTotalNumbersCount()
    {
        return mGamer.calculateNewNumbers() * (swPaired.position < 1 ? 1 : 2);
    }

    function clearUi()
    {
        mFinishValue = 0;
        swInputType.position = 0;
        swPaired.position = 0;
        totalNumberResult.text = "Toplam: 0";
        txtResultValue.text = ""
    }

    Connections {
        target: mGamer

        onNewNumbersChanged: {
            showTotalNumbersCount();
        }
    }

    modal: true
    title: "Oyuncu: " + mGamer.name + " " + totalNumberResult.text
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
//                anchors.fill: parent
                spacing: 2

                Switch {
                    id: swPaired
                    text: position < 1 ? "Tek" : "Çift"
                    checked: mResult.deleted

                    onPositionChanged: {
                        if(!mIsFinished)
                        {
                            if(!mIsValued)
                                showTotalNumbersCount();
                            else
                                totalNumberResult.text = "Toplam: " + parseInt(txtResultValue.text) * (swPaired.position < 1 ? 1 : 2);
                        }
                        else
                            totalNumberResult.text = "Toplam: " + mFinishValue * (swPaired.position < 1 ? 1 : 2);
                    }
                }

                Switch {
                    id: swInputType
                    text: position < 1 ? "Taş Seç" : "Sayı Gir"
                    checked: mResult.deleted
                    visible: !mIsFinished
                    onPositionChanged: {
                        mIsValued = position < 1 ? false : true;
                    }
                }

                Label {
                    id: totalNumberResult
                    visible: false
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
            visible: !mIsValued && !mIsFinished;
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

                        color: "light green"
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
                            }
                        }
                    }
                }
            }
        }

        TextField {
            id: txtResultValue
            visible: mIsValued

            width: root.width*0.5
            //            Layout.fillWidth: true
            //            Layout.fillHeight: true
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter

            font.pixelSize: Qt.application.font.pixelSize * 3
            Layout.alignment: Qt.AlignHCenter

            inputMethodHints: Qt.ImhDigitsOnly
            placeholderText: "Değer Girin"

            onTextChanged: {
                if(txtResultValue.text == "")
                {
                    totalNumberResult.text = "Toplam: " + 0 * (swPaired.position < 1 ? 1 : 2);
                }
                else
                {
                    totalNumberResult.text = "Toplam: " + parseInt(txtResultValue.text) * (swPaired.position < 1 ? 1 : 2);
                }
            }
        }

        Rectangle {
            visible: !mIsValued && !mIsFinished;
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
                                //showTotalNumbersCount();
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            visible: !mIsValued && !mIsFinished;
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
                                //showTotalNumbersCount();
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            visible: mIsFinished;
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "transparent"

            ColumnLayout{
                anchors.fill: parent
                spacing: 2

                RowLayout {
                    spacing: 2

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumWidth: 10

                        color: "white"
                        border.width: 1

                        Text {
                            anchors.fill: parent
                            text: "Normal\nBitiş"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            font.pixelSize: Qt.application.font.pixelSize * 1.6
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                mFinishValue = controller.normalDone;
                                totalNumberResult.text = "Toplam: " + mFinishValue * (swPaired.position < 1 ? 1 : 2);
                            }
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumWidth: 10

                        color: "white"
                        border.width: 1

                        Text {
                            anchors.fill: parent
                            text: "Okey\nBitiş"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            font.pixelSize: Qt.application.font.pixelSize * 1.6
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                mFinishValue = controller.okeyDone;
                                totalNumberResult.text = "Toplam: " + mFinishValue * (swPaired.position < 1 ? 1 : 2);
                            }
                        }
                    }
                }

                RowLayout {
                    spacing: 2

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumWidth: 10

                        color: "white"
                        border.width: 1

                        Text {
                            anchors.fill: parent
                            text: "Çift\nOkey Bitiş"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            font.pixelSize: Qt.application.font.pixelSize * 1.6
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                mFinishValue = controller.doubleOkeyDone;
                                totalNumberResult.text = "Toplam: " + mFinishValue * (swPaired.position < 1 ? 1 : 2);
                            }
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.minimumWidth: 10

                        color: "white"
                        border.width: 1

                        Text {
                            anchors.fill: parent
                            text: "Elden Bitiş"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            font.pixelSize: Qt.application.font.pixelSize * 1.6
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                mFinishValue = controller.directDone;
                                totalNumberResult.text = "Toplam: " + mFinishValue * (swPaired.position < 1 ? 1 : 2);
                            }
                        }
                    }
                }
            }
        }
    }

    onAccepted: {
        if(!mIsFinished)
        {
            if(!mIsValued)
                mGamer.addNewResult(getTotalNumbersCount());
            else
                mGamer.addNewResult(parseInt(parseInt(txtResultValue.text) * (swPaired.position < 1 ? 1 : 2)));
        }
        else
            mGamer.addNewResult(parseInt(mFinishValue * (swPaired.position < 1 ? 1 : 2)));

        controller.saveGame();
    }

    onRejected: {

    }
}
