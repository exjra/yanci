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
            text: "Oyuna Katıl"
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: Qt.application.font.pixelSize * 1.6
        }
    }
}
