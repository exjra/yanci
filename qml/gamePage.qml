import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
Page {
    id: gameMainPage
    anchors.fill: parent

    title: qsTr("Şimdiki Oyun: " + controller.game.name) + " gamers: " + controller.game.isPaired

    GamerResultProcessDialog {
        id: resultEditDialog
        anchors.centerIn: parent
    }

    function openEditDialog(pResult)
    {
        resultEditDialog.mResult = pResult;
        resultEditDialog.visible = true;
    }

    NewResultDialog {
        id: newResultDialog
        anchors.centerIn: parent
    }

    function openNewResultDialog(pGamer)
    {
        newResultDialog.mGamer = pGamer;
        newResultDialog.visible = true;
    }

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5

            Repeater {
                model: controller.game.gamers
                Gamer {
                    mGamer: model.modelData
                }
            }
        }

//        RowLayout {
//            Layout.alignment: Qt.AlignHCenter
//            spacing: 5

//            Repeater {
//                model: 4
//                Rectangle {
//                    Layout.fillWidth: true
//                    Layout.fillHeight: true
//                    Layout.minimumWidth: 10
//                    Layout.maximumHeight: 100

//                    border.width: 1
//                    color: "red"
//                }
//            }
//        }
    }
}
