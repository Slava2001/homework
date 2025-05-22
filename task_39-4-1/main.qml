import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.0

Window {
    property int box_side_len: 50
    property int ball_radius: 20
    property int ball_walk_step_percent: 10

    width: 200
    height: 100
    visible: true
    minimumHeight: box_side_len
    minimumWidth: box_side_len * 2
    title: qsTr("task_39.4.1")

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "BallInitState"

        RowLayout {
            spacing: 0
            anchors.fill: parent
            Rectangle {
                id: left_rectangle
                width: box_side_len
                height: box_side_len
                border.width: 2
                border.color: "black"
                radius: 5
                Layout.alignment: Qt.AlignCenter

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        ball.walk_progress_percent += ball_walk_step_percent
                        if (ball.walk_progress_percent < 100) {
                            scene.state = "BallWalkState"
                        } else {
                            scene.state = "BallInitState"
                            ball.walk_progress_percent = 0
                        }
                    }
                }
            }
            Rectangle {
                id: right_rectangle
                width: box_side_len
                height: box_side_len
                border.width: 2
                border.color: "black"
                radius: 5
                Layout.alignment: Qt.AlignCenter
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        scene.state = "BallInitState"
                        ball.walk_progress_percent = 0
                    }
                }
            }
        }
        Rectangle {
            id: ball
            width: box_side_len
            height: box_side_len
            color: "transparent"
            property int walk_progress_percent: 0

            Rectangle {
                width: ball_radius * 2
                height: ball_radius * 2
                radius: ball_radius
                border.width: 2
                border.color: "green"
                color: "lime"
                anchors.centerIn: parent
            }
        }

        states: [
            State {
                name: "BallInitState"
                PropertyChanges {
                    target: ball
                    x: left_rectangle.x
                    y: left_rectangle.y
                }
            },
            State {
                name: "BallWalkState"
                PropertyChanges {
                    target: ball
                    x: left_rectangle.x + (right_rectangle.x - left_rectangle.x) / 100 * ball.walk_progress_percent
                    y: left_rectangle.y + (right_rectangle.y - left_rectangle.y) / 100 * ball.walk_progress_percent
                }
            }
        ]
        transitions: [
            Transition {
                from: "BallWalkState"
                to: "BallInitState"
                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: "Bezier"
                }
            }
        ]
    }
}
