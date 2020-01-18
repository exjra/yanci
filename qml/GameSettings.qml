import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1

Page {
    id: page
    anchors.fill: parent

    title: qsTr("Oyun Oluştur")

//    MessageDialog {
//        id: gameNameProblems
//        buttons: MessageDialog.Ok
//        text: paired.position < 1 ? "Oyun adı ve oyuncu adları boş olamaz!" : "Oyun adı ve takım adları boş olamaz!"
//    }

//    BusyIndicator {
//        id: busyIndicator
//        running: false
//        anchors.centerIn: parent
//        z: 10
//    }

//    Connections {
//        target: controller.game

//        onGameReady:{
//            busyIndicator.running = false;

//            stackView.push("qrc:/qml/gamePage.qml");
//        }
//    }

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            spacing: 10
            anchors.leftMargin: 10
            Layout.alignment: Qt.AlignHCenter

            Label{
                color: "white"
                text: "Normal Bitiş:"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }

            TextField {
                id: normalDone
                text: controller.normalDone
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
        }

        RowLayout {
            spacing: 10
            anchors.leftMargin: 10
            Layout.alignment: Qt.AlignHCenter

            Label{
                color: "white"
                text: "Okey Bitiş:"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }

            TextField {
                id: okeyDone
                text: controller.okeyDone
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
        }

        RowLayout {
            spacing: 10
            anchors.leftMargin: 10
            Layout.alignment: Qt.AlignHCenter

            Label{
                color: "white"
                text: "Çift Okey Bitiş:"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }

            TextField {
                id: doubleOkeyDone
                text: controller.doubleOkeyDone
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
        }

        RowLayout {
            spacing: 10
            anchors.leftMargin: 10
            Layout.alignment: Qt.AlignHCenter

            Label{
                color: "white"
                text: "Elden Bitiş:"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }

            TextField {
                id: directDone
                text: controller.directDone
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                Layout.alignment: Qt.AlignHCenter
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
        }

        Button {
            id: btnSave
            text: "Kaydet"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                if(normalDone.text == "")
                    normalDone.text = "-100"

                if(okeyDone.text == "")
                    okeyDone.text = "-200"

                if(doubleOkeyDone.text == "")
                    doubleOkeyDone.text = "-400"

                if(directDone.text == "")
                    directDone.text = "-200"

                controller.saveGameSettings(parseInt(normalDone.text), parseInt(okeyDone.text), parseInt(doubleOkeyDone.text), parseInt(directDone.text));

                stackView.pop();
            }
        }
    }
}
