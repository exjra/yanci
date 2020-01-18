import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
Page {
    id: page
    anchors.fill: parent
    
    title: qsTr("Ana Ekran")

    ColumnLayout {
        anchors.fill: parent

        Button {
            id: newGame
            text: "Yeni Oyun"
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: stackView.push("qrc:/qml/createGame.qml")
        }

        Button {
            id: joinGame
            visible: false
            text: "Oyuna Katıl"
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: Qt.application.font.pixelSize * 1.6
        }

        Button {
            id: readGame
            text: "Oyuna Devam"
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: Qt.application.font.pixelSize * 1.6

            onClicked: {
                controller.readGame();
                stackView.pop();
                stackView.push("qrc:/qml/gamePage.qml");
                controller.refreshResults();
            }
        }

        Button {
            id: settings
            text: "Oyun Ayarları"
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: stackView.push("qrc:/qml/GameSettings.qml")
        }
    }
}
