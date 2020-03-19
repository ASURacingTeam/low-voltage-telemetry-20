import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.3

Item {
       id: steering_win
        visible: true
        width: 350
        height: 300
        property int steering_angle : 0
        Rectangle {
            id: id_root
            width: parent.width
            height: parent.height
            anchors.centerIn: parent
            color: "#252424"
        Image {
               id: steering
               source: "qrc:/images/images/steering.png"
               anchors.centerIn: parent
               scale: 0.15
               mipmap: true
               RotationAnimation on rotation {
                   from: steering.rotation
                   to: steering_win.steering_angle
                   duration: 100//*Math.abs(steering_win.steering_angle)
                   running: steering_win.steering_angle <= 90 && steering_win.steering_angle >= -90
               }
             }
               Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    text: "Steering angle : " + steering_angle
                    color: "white"
                    font.pixelSize: id_root.height * 0.06
                    font.family: "Comic Sans MS"
                    }

       }
}


