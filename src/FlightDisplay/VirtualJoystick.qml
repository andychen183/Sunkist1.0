/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


import QtQuick 2.5
import QtQuick.Controls 1.2
import QtSensors 5.3

import QGroundControl               1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.Vehicle       1.0

Item {
    //property bool useLightColors - Must be passed in from loaded

    property int    _joystickSize:   ScreenTools.defaultFontPixelWidth * 15
    property real   _onesixthX:              width / 6
    property real   _onefifthY:              height / 5
    property real   _origin:                   0
    property int   _count:                   0
    property real   pressedAngle:            0
    property real   revised:                   0

//    Timer {
//        interval:   40  // 25Hz, same as real joystick rate
//        running:    QGroundControl.virtualTabletJoystick && _activeVehicle
//        repeat:     true
//        onTriggered: {
//            if (_activeVehicle) {
//                _activeVehicle.virtualTabletJoystickValue(rightStick.xAxis, rightStick.yAxis, leftStick.xAxis, leftStick.yAxis)
//            }
//        }
//    }

//    JoystickThumbPad {
//        id:                     leftStick
//        anchors.leftMargin:     xPositionDelta
//        anchors.bottomMargin:   -yPositionDelta
//        anchors.left:           parent.left
//        anchors.bottom:         parent.bottom
//        width:                  parent.height
//        height:                 parent.height
//        yAxisThrottle:          true
//        lightColors:            useLightColors
//    }

//    JoystickThumbPad {
//        id:                     rightStick
//        anchors.rightMargin:    -xPositionDelta
//        anchors.bottomMargin:   -yPositionDelta
//        anchors.right:          parent.right
//        anchors.bottom:         parent.bottom
//        width:                  parent.height
//        height:                 parent.height
//        lightColors:            useLightColors
//    }

    Timer {
        interval:   20// change to 10hz |  40  // 25Hz, same as real joystick rate
        running:    QGroundControl.virtualTabletJoystick && _activeVehicle
        repeat:     true
        onTriggered: {
            if (_activeVehicle) {
                //virtualTabletJoystickValue(double roll, double pitch, double yaw, double thrust)

                 switch(QGroundControl.rcMode)
                 {
                     case 0: //_JapaneseRC
                     {
                        _activeVehicle.virtualTabletJoystickValue(rightStick.xAxis, leftStick.yAxis, leftStick.xAxis, rightStick.yAxis)
                         break;
                     }
                     case 1: //_AmericanRC
                     {
                        _activeVehicle.virtualTabletJoystickValue(rightStickAmericanMode.xAxis, rightStickAmericanMode.yAxis, leftStickAmericanMode.xAxis, leftStickAmericanMode.yAxis)
                         break;
                     }
                     case 2: //_ChineseRC
                     {
                         _activeVehicle.virtualTabletJoystickValue(leftStick.xAxis, leftStick.yAxis, rightStick.xAxis, rightStick.yAxis)
                         break;
                     }
                     case 3: //_GravityRC
                     {
                        _activeVehicle.virtualTabletJoystickValue(rightStickGravityMode.xAxis, leftStickGravityMode.yAxis, leftStickGravityMode.xAxis, rightStickGravityMode.yAxis)
                         break;
                     }
                     default: //_JapaneseRC
                         _activeVehicle.virtualTabletJoystickValue(rightStick.xAxis, leftStick.yAxis, leftStick.xAxis, rightStick.yAxis)
                         break;
                 }

            }
        }
    }

    Accelerometer {
        id: accel1
        dataRate: 20
        active: (QGroundControl.rcMode===3)?true:false
        onReadingChanged: {
            if((QGroundControl.rcMode===3)?true:false)
            {
                leftStickGravityMode.yAxis = (accel1.reading.x)/10          //pitch
                rightStickGravityMode.xAxis = (accel1.reading.y)/10         //roll
            }
            else
            {
                leftStickGravityMode.yAxis = 0          //pitch
                rightStickGravityMode.xAxis = 0         //roll
            }
        }
    }

        Column{
            x:_onesixthX
            y: _onefifthY*1.5 //-150
            width:                  parent.height
            height:                 parent.height
            visible:                ((QGroundControl.rcMode===0)||(QGroundControl.rcMode===2))?true:false
            JoystickThumbPad {
                id:                     leftStick
                visible:                ((QGroundControl.rcMode===0)||(QGroundControl.rcMode===2))?true:false
                enabled:                ((QGroundControl.rcMode===0)||(QGroundControl.rcMode===2))?true:false
                anchors.rightMargin:    -xPositionDelta
                anchors.bottomMargin:   -yPositionDelta
                anchors.right:          parent.right
                anchors.bottom:         parent.bottom
                width:                  _joystickSize
                height:                 _joystickSize
                yAxisThrottle:          (QGroundControl.rcMode===1)?true:false
                lightColors:            !isBackgroundDark
            }



        }

        Column{
            x: _onesixthX * 5 //935
            y: _onefifthY * 2//     145
            width:                  parent.height
            height:                 parent.height
            visible:                ((QGroundControl.rcMode===0)||(QGroundControl.rcMode===2))?true:false
            JoystickThumbPad {
                id:                     rightStick
                visible:                ((QGroundControl.rcMode===0)||(QGroundControl.rcMode===2))?true:false
                enabled:                ((QGroundControl.rcMode===0)||(QGroundControl.rcMode===2))?true:false
                anchors.rightMargin:    -xPositionDelta
                anchors.bottomMargin:   -yPositionDelta
                anchors.right:          parent.right
                anchors.bottom:         parent.bottom
                width:                  _joystickSize
                height:                 _joystickSize
                yAxisThrottle:          (QGroundControl.rcMode===1)?false:true
                lightColors:            !isBackgroundDark
            }


        }

    //------------------------------------------------------------
        Column{
            x:_onesixthX
            y: _onefifthY*1.5 //-150
            width:                  parent.height
            height:                 parent.height
            visible:                (QGroundControl.rcMode===1)?true:false
            JoystickThumbPad {
                id:                     leftStickAmericanMode
                visible:                (QGroundControl.rcMode===1)?true:false
                enabled:                (QGroundControl.rcMode===1)?true:false
                anchors.rightMargin:    -xPositionDelta
                anchors.bottomMargin:   -yPositionDelta
                anchors.right:          parent.right
                anchors.bottom:         parent.bottom
                width:                  _joystickSize
                height:                 _joystickSize
                yAxisThrottle:          (QGroundControl.rcMode===1)?true:false
                lightColors:            !isBackgroundDark
            }

        }

        Column{
            x: _onesixthX * 5 //935
            y: _onefifthY * 2//     145
            width:                  parent.height
            height:                 parent.height
            visible:                (QGroundControl.rcMode===1)?true:false
            JoystickThumbPad {
                id:                     rightStickAmericanMode
                visible:                (QGroundControl.rcMode===1)?true:false
                enabled:                (QGroundControl.rcMode===1)?true:false
                anchors.rightMargin:    -xPositionDelta
                anchors.bottomMargin:   -yPositionDelta
                anchors.right:          parent.right
                anchors.bottom:         parent.bottom
                width:                  _joystickSize
                height:                 _joystickSize
                yAxisThrottle:          (QGroundControl.rcMode===1)?false:true
                lightColors:            !isBackgroundDark
            }

        }
    //------------------------------------------------------------

    //-------------------------GravityMode-----------------------------------
        Column{
            x:_onesixthX
            y: _onefifthY*1.5 //-150
            width:                  parent.height
            height:                 parent.height
            visible:                (QGroundControl.rcMode===3)?true:false
            JoystickThumbPad {
                id:                     leftStickGravityMode                //only control yaw
                visible:                (QGroundControl.rcMode===3)?true:false
                enabled:                (QGroundControl.rcMode===3)?true:false
                opacity:                (QGroundControl.rcMode===3)?0.8:1
                anchors.rightMargin:    -xPositionDelta
                anchors.bottomMargin:   -yPositionDelta
                anchors.right:          parent.right
                anchors.bottom:         parent.bottom
                width:                  _joystickSize
                height:                 _joystickSize
                yAxisThrottle:          (QGroundControl.rcMode===3)?false:true
                lightColors:            !isBackgroundDark
            }

        }

        Column{
            x: _onesixthX * 5 //935
            y: _onefifthY * 2//     145
            width:                  parent.height
            height:                 parent.height
            visible:                (QGroundControl.rcMode===3)?true:false
            JoystickThumbPad {
                id:                     rightStickGravityMode               //only control throttle
                enabled:                (QGroundControl.rcMode===3)?true:false
                opacity:                (QGroundControl.rcMode===3)?0.8:1
                anchors.rightMargin:    -xPositionDelta
                anchors.bottomMargin:   -yPositionDelta
                anchors.right:          parent.right
                anchors.bottom:         parent.bottom
                width:                  _joystickSize
                height:                 _joystickSize
                yAxisThrottle:          (QGroundControl.rcMode===3)?true:false
                lightColors:            !isBackgroundDark
            }
       }


}
