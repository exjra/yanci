import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.1

Dialog {
    property var mResult;

    modal: true
    title: "İşlemler"
    standardButtons: Dialog.Ok | Dialog.Cancel

    x: (parent.width - width) / 2
    y: (parent.height - height) / 2;

    contentItem: ColumnLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true

//        spacing: 3

        TextField {
            id: txtResultValue
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            Layout.alignment: Qt.AlignHCenter
            text: mResult.value
            inputMethodHints: Qt.ImhDigitsOnly
        }

        Switch {
            id: swDelete
            text: "İptal"
            checked: mResult.deleted
        }
    }

    onAccepted: {

        mResult.setValue(parseInt(txtResultValue.text))

        if(mResult.initialValue !== mResult.value)//parseInt(txtResultValue.text))
            mResult.setChanged(true);
        else
            mResult.setChanged(false);

//        if(!mResult.changed)
//        {
//            if(mResult.initialValue !== parseInt(txtResultValue.text))
//                mResult.setChanged(true);
//        }

//        mResult.setValue(parseInt(txtResultValue.text))
        mResult.setDeleted(swDelete.position > 0);

        controller.refreshResults();
    }

    onRejected: {

    }
}
