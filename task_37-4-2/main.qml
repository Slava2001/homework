import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Window {
    visible: true
    title: qsTr("task_37.4.2")
    minimumHeight: 200
    minimumWidth: 300

    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.color: "black"
            radius: 10
            color: "gray"

            ColumnLayout {
                anchors{
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
                Text {
                    Layout.fillWidth: true
                    text: "This is the screen"
                }
                Text {
                    id: video_played_percentage_text
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    text: "0%"
                }
            }
        }

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            spacing: 10

            Component {
                id: player_button

                Button {
                    id: my_btn
                    font.pixelSize: 20
                    background: Rectangle {
                          implicitWidth: 40
                          implicitHeight: 40
                          color: my_btn.down? "gray": "white"
                          border.color: "black"
                          border.width: my_btn.hovered? 3: 1
                    }
                }
            }

            Loader {
                sourceComponent: player_button
                onLoaded: {
                    item.text = "▶️"
                    item.onClicked.connect(()=> {
                        my_progress_bar_timer.start()
                    })
                }
            }
            Loader {
                sourceComponent: player_button
                onLoaded: {
                    item.text = "⏸️"
                    item.onClicked.connect(()=> {
                        my_progress_bar_timer.stop()
                    })
                }
            }
            Loader {
                sourceComponent: player_button
                onLoaded: {
                    item.text = "⏹"
                    item.onClicked.connect(()=> {
                        my_progress_bar_timer.stop()
                        my_progress_bar.value = 0
                    })
                }
            }
            Loader {
                sourceComponent: player_button
                onLoaded: {
                    item.text = "⏪️"
                    item.onClicked.connect(()=> {
                        my_progress_bar.value -= 10
                    })
                }
            }
            Loader {
                sourceComponent: player_button
                onLoaded: {
                    item.text = "⏩️"
                    item.onClicked.connect(()=> {
                        my_progress_bar.value += 10
                    })
                }
            }
        }

        ProgressBar {
            id: my_progress_bar
            padding: parent.spacing
            from: 0
            to: 100
            value: 0
            height: 50
            Layout.fillWidth: true
            onValueChanged: {
                video_played_percentage_text.text = value + "%"
            }
        }

        Timer {
            id: my_progress_bar_timer
            interval: 100
            repeat: true
            onTriggered: {
                my_progress_bar.value += 1
                if (my_progress_bar.value >= 100) {S
                    my_progress_bar.value = 0
                    stop()
                }
            }
        }
    }
}
