import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
Page {
    id: page
    anchors.fill: parent

    title: qsTr("Şimdiki Oyun: " + controller.game.name) + " gamers: " + controller.game.isPaired

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5

            //            ListView {
            //                id: gamersList
            //                spacing: 10
            ////                Layout.alignment: Qt.AlignHCenter
            ////                width: parent.width
            //                delegate: Gamer {
            //                    mName: model.modelData.name
            //                }

            //                /*DeviceListItem{
            //                    mName: model.modelData.name
            //                    mUid: model.modelData.uid
            //                    mDeviceId: model.modelData.deviceId
            //                    mActivated: model.modelData.isActivated
            //                }*/

            //                model: controller.game.gamers

            //                ScrollIndicator.vertical: ScrollIndicator { }
            //            }

            Repeater {
                model: controller.game.isPaired ? 2 : 4
                Gamer {
                    mName: controller.game.gamers[0].name
                }
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5

            Repeater {
                model: 4
                Rectangle {
                    width: 100; height: 40
                    border.width: 1
                    color: "red"
                }
            }
        }
    }
}
