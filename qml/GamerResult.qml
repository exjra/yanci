import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12

Rectangle {
    id: root

    property var mResult;

    Layout.fillWidth: true
//    Layout.minimumHeight: 25

    border.width: 1
    color: "transparent"
    width: parent.width;
    height: (resultsList.height/5) < 50 ? 50 : (resultsList.height/5);

    RowLayout{
        anchors.fill: parent
        spacing: 1
        anchors.leftMargin: 10

        Label{
            text: mResult.value
            color: mResult.deleted ? "red" : (mResult.changed ? "yellow" : "white")
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }

        Button {
            text: "İşlem"
            font.pixelSize: Qt.application.font.pixelSize * 1.0

            Layout.alignment: Qt.AlignRight

            onClicked: {
                gameMainPage.openEditDialog(mResult);
            }
        }
    }
}
