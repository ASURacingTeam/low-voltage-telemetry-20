import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.4
Item {
    id: id_win
    visible: true
    width: 300
    height: 300
    property int gear : 0
    Rectangle {
        id: id_root
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        color: "#252424"
//        SpinBox {
//           id : spin
//           width: parent.width
//           minimumValue: 0
//           maximumValue: 6
//           value: 0
//           enabled: true
//           style: SpinBoxStyle{
//                  background: Rectangle {
//                      implicitWidth: 100
//                      implicitHeight: 20
//                      border.color: "grey"
//                      radius: 2
//                      color: "#252424"
//                  }
//              }
//           onValueChanged: {
//                id_win.gear = spin.value
//           }
//        }
         Repeater {
           model: 3
           Item {
               height: id_root.height/10
               transformOrigin: Item.Right
               x: (id_root.width/10)+((index+1)*10*(id_root.width/50))
               Rectangle {
                   height: id_root.height * 0.15
                   width: height
                   color: (index+1)*2 - 1 == id_win.gear ? "green" : "grey"
                   border.color: "grey"
                   border.width: 2
                   radius: width/2
                   antialiasing: true
                   anchors.horizontalCenter: parent.horizontalCenter
                   anchors.top: parent.top
                   anchors.topMargin: id_root.height * 0.075

                   Text {
                       anchors.centerIn: parent
                       color: "black"
                       text: (index+1)*2 - 1
                       font.pixelSize: parent.height * 0.5
                       font.family: "Comic Sans MS"
                        }
                   }
                }
               }
         Text {
             anchors.centerIn: parent
             text: "N"
             visible: id_win.gear == 0 ? true : false
             color: "dark red"
             font.pixelSize: gear_shift.height*0.3
             font.family: "Comic Sans MS"
         }

        Image {
               id: gear_shift
               source: "qrc:/images/images/gear_shift.png"
               anchors.centerIn: parent
               scale: 0.3
               mipmap: true
               visible: id_win.gear !=0 ? true : false
               function angleCalculation(gear_value){
                   return (gear_value%2 === 0 && gear_value !== 0 ? 225 - ((gear_value/2)-1)*45 : (gear_value === 1 ? 315 : ((gear_value === 3 || gear_value === 0) ? 0 : 45)))
               }
               property int angle_gear_number :  gear_shift.angleCalculation(gear)
               RotationAnimation on rotation {
                        from: gear_shift.rotation
                        to: ((gear_shift.angle_gear_number - gear_shift.rotation)/45 <= 4) && (gear_shift.angle_gear_number - gear_shift.rotation >= 0) ? gear_shift.angle_gear_number : (gear_shift.angle_gear_number - gear_shift.rotation < 0 ? gear_shift.angle_gear_number : gear_shift.angle_gear_number - 360)
                        duration: 500//*Math.abs(((gear_shift.angle_gear_number - gear_shift.rotation)/45))
                        running: id_win.gear
                    }
               Repeater {
                 model: 3
                 Item {
                     height: gear_shift.height/10
                     transformOrigin: Item.Right
                     x: ((gear_shift.width/10)+((index+1)*10*(gear_shift.width/50)))*1.2
                     Text {
                         height: gear_shift.height * 0.15
                         width: height
                         color: (index+1)*2 - 1 == id_win.gear ? "green" : "black"
                         text: (index+1)*2 - 1
                         font.pixelSize: parent.height*0.8
                         font.family: "Comic Sans MS"
                         antialiasing: true
                         anchors.horizontalCenter: parent.horizontalCenter
                         anchors.top: parent.top
                         anchors.topMargin: gear_shift.height * 0.035
                         }
                      }
                     }
               Repeater {
                 model: 3
                 Item {
                     height: gear_shift.height/10
                     transformOrigin: Item.Right
                     x: ((gear_shift.width/10)+((index+1)*10*(gear_shift.width/50)))*1.2
                     Text {
                         height: gear_shift.height * 0.15
                         width: height
                         color: (index+1)*2 == id_win.gear ? "green" : "black"
                         text: (index+1)*2
                         font.pixelSize: parent.height*0.8
                         font.family: "Comic Sans MS"
                         antialiasing: true
                         anchors.horizontalCenter: parent.horizontalCenter
                         anchors.top: parent.top
                         anchors.topMargin: gear_shift.height*0.35
                         }
                      }
                     }
               }
        Repeater {
          model: 3
          Item {
              height: id_root.height/10
              transformOrigin: Item.Right
              x: (id_root.width/10)+((index+1)*10*(id_root.width/50))
              Rectangle {
                  height: id_root.height * 0.15
                  width: height
                  color: (index+1)*2 == id_win.gear ? "green" : "grey"
                  border.color: "grey"
                  border.width: 2
                  radius: width/2
                  antialiasing: true
                  anchors.horizontalCenter: parent.horizontalCenter
                  anchors.top: parent.top
                  anchors.topMargin: id_root.height * 0.75

                  Text {
                      anchors.centerIn: parent
                      color: "black"
                      text: (index+1)*2
                      font.pixelSize: parent.height * 0.5
                      font.family: "Comic Sans MS"
                       }
                  }
               }
              }
        Text {
             anchors.horizontalCenter: parent.horizontalCenter
             anchors.bottom: parent.bottom
             anchors.bottomMargin: 5
             text: "Gear Position"
             color: "white"
             font.pixelSize: id_root.height * 0.06
             font.family: "Comic Sans MS"
             }
    }

}





