import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2

Window
{
    visible: true
    width: 640
    height: 480
    title: qsTr("QOAuth2 Test")
    Column
    {
        spacing: first.height
        anchors.centerIn: parent
        Button
        {
            id: first
            text: qsTr("Grant me access")
            onPressed: auth.grant()
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Label
        {
            text: auth.textToDisplay
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
