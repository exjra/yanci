import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    property var mGamer;

    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.minimumWidth: 10

    border.width: 1
    color: "transparent"

    ColumnLayout {
        anchors.fill: parent

        Label {
            text: mGamer.name
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            horizontalAlignment: Qt.AlignHCenter
        }

        ListView {
            id: resultsList
            spacing: 10
            clip: true

            Layout.alignment: Qt.AlignHCenter

            Layout.fillWidth: true
            Layout.fillHeight: true

            delegate: GamerResult{
                mResult: model.modelData
            }

            model: mGamer.results
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Button {
                text: "Sonuç Ekle"

                onClicked: {
                    mGamer.clearNewNumberList();
                    gameMainPage.openNewResultDialog(mGamer);
                }
            }

            Button {
                text: "Ceza Ekle"
            }
        }
    }
}
