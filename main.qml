import QtQuick 2.15
import QtQuick.Window 2.15
import MainWindow1 1.0

Window {
    id: root
    width: 500
    height: 500
    visible: true
    title: qsTr("Warcaby")
    color: "#2a3d25"

    Board {
    }
}
