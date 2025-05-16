import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Window {
    width: 240
    height: 680
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    visible: true
    title: qsTr("task_37.4.3")

    Component {
         id: custom_button
         Button {
             id: my_btn
             font.pixelSize: 20
             background: Rectangle {
                 implicitWidth: 75
                 implicitHeight: 75
                 color: my_btn.down? "gray": "white"
                 border.color: "black"
                 border.width: my_btn.hovered? 3: 1
            }
        }
    }

    ColumnLayout {
         anchors.fill: parent
        GridLayout {
            columns: 3
            columnSpacing: 8
            rowSpacing: 8

            ListModel {
                id: channel_btns
                ListElement { text: "o"; row: 0; col: 0; fn: ()=> { } }
                ListElement { text: "🔇"; row: 0; col: 2; fn: ()=> { volume.set(0) } }
                ListElement { text: "0"; row: 1; col: 0; fn: ()=> { channel.set(0) } }
                ListElement { text: "1"; row: 1; col: 1; fn: ()=> { channel.set(1) } }
                ListElement { text: "2"; row: 1; col: 2; fn: ()=> { channel.set(2) } }
                ListElement { text: "3"; row: 2; col: 0; fn: ()=> { channel.set(3) } }
                ListElement { text: "4"; row: 2; col: 1; fn: ()=> { channel.set(4) } }
                ListElement { text: "5"; row: 2; col: 2; fn: ()=> { channel.set(5) } }
                ListElement { text: "6"; row: 3; col: 0; fn: ()=> { channel.set(6) } }
                ListElement { text: "7"; row: 3; col: 1; fn: ()=> { channel.set(7) } }
                ListElement { text: "8"; row: 3; col: 2; fn: ()=> { channel.set(8) } }
                ListElement { text: "9"; row: 4; col: 1; fn: ()=> { channel.set(9) } }
            }

            Repeater {
                model: channel_btns
                Loader {
                    sourceComponent: custom_button
                    onLoaded: {
                        Layout.row = model.row
                        Layout.column = model.col
                        item.text = model.text
                        item.onClicked.connect(model.fn)
                    }
                }
            }
        }

        GridLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            columns: 2
            columnSpacing: 8
            rowSpacing: 8

            ListModel {
                id: control_btns
                ListElement { text: "^"; row: 0; col: 0; fn: ()=> { channel.set(channel.val + 1) } }
                ListElement { text: "v"; row: 1; col: 0; fn: ()=> { channel.set(channel.val - 1) } }
                ListElement { text: "+"; row: 0; col: 1; fn: ()=> { volume.set(volume.val + 10) } }
                ListElement { text: "-"; row: 1; col: 1; fn: ()=> { volume.set(volume.val - 10) } }
            }

            Repeater {
                model: control_btns
                Loader {
                    sourceComponent: custom_button
                    onLoaded: {
                        Layout.row = model.row
                        Layout.column = model.col
                        item.text = model.text
                        item.onClicked.connect(model.fn)
                    }
                }
            }
        }

        Rectangle {
            width: 200
            height: 100
            border.color: "black"
            radius: 10
            color: "gray"
            anchors.horizontalCenter: parent.horizontalCenter

            ColumnLayout {
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }

                Text {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 40
                    color: "lime"
                    id: channel
                    text: "CH: 0"
                    property int val: 0
                    function set(channel) {
                        val = Math.max(0, Math.min(9, channel))
                        text = "CH: " + val
                    }
                }

                Text {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 40
                    color: "lime"
                    id: volume
                    text: "VL: 100%"
                    property int val: 100
                    function set(volume) {
                        val = Math.max(0, Math.min(100, volume))
                        text = "VL: " + val + "%"
                    }
                }
            }
        }
    }
}
