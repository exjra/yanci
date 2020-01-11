import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12

ItemDelegate {
    id: root
    property var mName: ""

    ColumnLayout {
        Label{
            text: mName
        }
    }
}
