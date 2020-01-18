import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1

Page {
    id: page
    anchors.fill: parent

    title: qsTr("Oyun Oluştur")

    MessageDialog {
        id: gameNameProblems
        buttons: MessageDialog.Ok
        text: paired.position < 1 ? "Oyun adı ve oyuncu adları boş olamaz!" : "Oyun adı ve takım adları boş olamaz!"
    }

    BusyIndicator {
        id: busyIndicator
        running: false
        anchors.centerIn: parent
        z: 10
    }

    Connections {
        target: controller.game

        onGameReady:{
            busyIndicator.running = false;

            stackView.pop();
            stackView.push("qrc:/qml/gamePage.qml");
        }
    }

    ColumnLayout {
        anchors.fill: parent

        TextField {
            id: gameName
            placeholderText: "Oyun Adı"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter
        }

        Switch {
            id: paired
            text: position < 1 ? "Tekli" : "Eşli"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter
        }

        TextField {
            id: gamer1
            placeholderText: paired.position < 1 ? "1. Oyuncu" : "1. Takım"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter
        }
        TextField {
            id: gamer2
            placeholderText: paired.position < 1 ? "2. Oyuncu" : "2. Takım"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter
        }
        TextField {
            id: gamer3
            placeholderText: "3. Oyuncu"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter

            visible: paired.position < 1
        }
        TextField {
            id: gamer4
            placeholderText: "4. Oyuncu"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter

            visible: paired.position < 1
        }

        Button {
            id: newGame
            text: "Oyunu Başlat"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter

            onClicked: {

//                //test
//                gameName.text = "mygame";
//                gamer1.text = "gamer1";
//                gamer2.text = "gamer2";
//                gamer3.text = "gamer3";
//                gamer4.text = "gamer4";
//                //test

                if(gameName.text === "")
                    gameNameProblems.visible = true;
                else
                {
                    busyIndicator.running = true;
                    if(paired.position > 0)
                    {
                        gamer3.text = "";
                        gamer4.text = "";
                    }

                    controller.createGame(gameName.text, paired.position < 1 ? false : true, gamer1.text, gamer2.text, gamer3.text, gamer4.text);
                }
            }
        }
    }
}
