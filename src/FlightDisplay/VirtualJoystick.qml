/*=====================================================================

QGroundControl Open Source Ground Control Station

(c) 2009, 2015 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

This file is part of the QGROUNDCONTROL project

    QGROUNDCONTROL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    QGROUNDCONTROL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/

import QtQuick 2.5
import QtQuick.Controls         1.2
import QtSensors 5.3

import QGroundControl               1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.Vehicle       1.0

Item {
    QGCMapPalette { id: mapPal; lightColors: !isBackgroundDark }

    property int    _joystickSize:   ScreenTools.defaultFontPixelWidth * 15
    property real   _onesixthX:              width / 6
    property real   _onefifthY:              height / 5
    property real   _origin:                   0
    property int   _count:                   0
    property real   pressedAngle:            0
    property real   revised:                   0

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
//                rightStickGravityMode.yAxis = (accel1.reading.z)/10         //throttle
            }
            else
            {
                leftStickGravityMode.yAxis = 0          //pitch
                rightStickGravityMode.xAxis = 0         //roll
            }
        }
    }

//    Compass{
//        id: compass1
//        dataRate: 20
//        active: false
//        onReadingChanged: {
//            if((QGroundControl.rcMode===3)?true:false)
//            {
//                _count++

//                if( _count < 21)                    //cause there is a delay between last time release and this time pressed
//                {
//                    pressedAngle = compass1.reading.azimuth
//                    revised = 0
//                }
//                _origin = compass1.reading.azimuth                        //azimuth    [-180, 180]

//                if(_count>21)
//                {
//                    revised = _origin - pressedAngle

//                    while(revised <= -180)   revised += 360
//                    while(revised > 180)    revised -= 360


//                    leftStickGravityMode.xAxis =   (revised + 180)/180 - 1        //yaw        [-1, 1]

//                }
//               // console.warn("_count = "+_count+"--_origin = "+_origin+"--revised = "+revised+"------pressedAngle = "+pressedAngle)


//            }
//            else
//            {
//                leftStickGravityMode.xAxis = 0          //yaw
//            }
//        }
//    }

//    MouseArea {//
//        x: _onesixthX*0.4   //67
//        y: _onefifthY       //170
//        width: gyroImage.width
//        height: gyroImage.height
//        Image{
//            id:             gyroImage
//            visible:        (QGroundControl.rcMode===3)?true:false
//            enabled:        (QGroundControl.rcMode===3)?true:false
////            source:         "/qmlimages/VehicleSummaryIcon.png"
//            source:         "qrc:/qmlimages/resources/btn_gravity_nor.png"
//        }
//        onPressed: {
//            accel1.active   = true
//            compass1.active = true
//            rightStickGravityMode.opacity = 1
//            rightStickGravityMode.enabled = true
//            gyroImage.opacity = 0.8

//            _count = 1
//        }

//        onReleased: {
//            accel1.active   = false
//            compass1.active = false
//            gyroImage.opacity = 1
//            rightStickGravityMode.opacity = 0.4
//            rightStickGravityMode.enabled = false
//            _count = 0

//            while ((leftStickGravityMode.yAxis !== 0) ||(rightStickGravityMode.xAxis !== 0))
//            { // reset all the values to default
//                leftStickGravityMode.yAxis = 0
//                rightStickGravityMode.xAxis = 0
//                leftStickGravityMode.xAxis = 0
////                rightStickGravityMode.yAxis = 0.5 //throttle

//            }
//         }
//    }

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

//    Column{
//        x: _onesixthX * 5 //935
//        y: _onefifthY * 2//
//        width:                  parent.height
//        height:                 parent.height

//        JoystickThumbPad {
//            id:                     gyroStick
//            visible:                _gravIsPressed?true:false
//            enabled:                _gravIsPressed?true:false
//            opacity:                0.4//first change to GravMode, opacity should be 0.4
//            anchors.rightMargin:    -xPositionDelta
//            anchors.bottomMargin:   -yPositionDelta
//            anchors.right:          parent.right
//            anchors.bottom:         parent.bottom
//            width:                  _joystickSize
//            height:                 _joystickSize
//            yAxisThrottle:          true // switch throttle to right
//            lightColors:            !isBackgroundDark
//        }

//    }

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
