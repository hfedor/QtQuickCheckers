import QtQuick 2.15
import QtQuick.Window 2.15
import MainWindow1 1.0

Rectangle {

    anchors {
        verticalCenter: paret.verticalCenter
        horizontalCenter: paret.horizontalCenter
    }

    height: width
    width: 2*radius
    radius: parent.height * 2 / 5
}
