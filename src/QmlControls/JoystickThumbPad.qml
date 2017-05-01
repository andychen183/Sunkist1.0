import QtQuick                  2.5
import QtQuick.Controls         1.2

import QGroundControl               1.0
import QGroundControl.Palette       1.0
import QGroundControl.ScreenTools   1.0

Item {
    id:             _joyRoot

    property bool   onJoystick:     true
    property alias  lightColors:    mapPal.lightColors  ///< true: use light colors from QGCMapPalette for drawing
    property real   xAxis:          0                   ///< Value range [-1,1], negative values left stick, positive values right stick
    property real   yAxis:          0                   ///< Value range [-1,1], negative values up stick, positive values down stick
    property bool   yAxisThrottle:  false               ///< true: yAxis used for throttle, range [1,0], positive value are stick up
    property real   xPositionDelta: 0                   ///< Amount to move the control on x axis
    property real   yPositionDelta: 0                   ///< Amount to move the control on y axis

    property real   _centerXY:              width / 2
    property bool   _processTouchPoints:    false
    property bool   _stickCenteredOnce:     false
    property real   stickPositionX:         _centerXY
    property real   stickPositionY:         yAxisThrottle ? height : _centerXY

    QGCMapPalette { id: mapPal }

//    onStickPositionXChanged: {
//        var xAxisTemp = stickPositionX / width
//        xAxisTemp *= 2.0
//        xAxisTemp -= 1.0
//        xAxis = xAxisTemp
//    }

    onStickPositionXChanged: {
//        if (onJoystick == true)
//        {
            var xAxisTemp = stickPositionX / width
            xAxisTemp *= 2.0
            xAxisTemp -= 1.0
            xAxis = xAxisTemp

            //in mode 3, since yaw is controled by rotate cellphone, thus no matter yAx is Throttle,  xAxis should be 0
            if(((QGroundControl.rcMode===3)) && yAxisThrottle)
            {
                xAxis = 0
            }
            else if(((QGroundControl.rcMode===3)) && (!yAxisThrottle))
            {
                xAxis = 0.6*(xAxisTemp+1)/2-0.3
            }
//        }
    }

//    onStickPositionYChanged: {
//        var yAxisTemp = stickPositionY / height
//        yAxisTemp *= 2.0
//        yAxisTemp -= 1.0
//        if (yAxisThrottle) {
//            yAxisTemp = ((yAxisTemp * -1.0) / 2.0) + 0.5
//        }
//        yAxis = yAxisTemp
//    }

    onStickPositionYChanged: {
        if (onJoystick == true)
        {
            var yAxisTemp = stickPositionY / height
            yAxisTemp *= 2.0
            yAxisTemp -= 1.0
            if (yAxisThrottle) {
                yAxisTemp = ((yAxisTemp * -1.0) / 2.0) + 0.5
            }
            if((QGroundControl.rcMode===3) && (!yAxisThrottle))
            {
                yAxis = 0
            }
            else
            {
                yAxis = 0.3*yAxisTemp+0.25
//                yAxis = 0.65*yAxisTemp          //here we restraint the scope of Throttle to [0,0.53]
                yAxis = yAxisTemp
            }

        }
    }

    function reCenter()
    {
        _processTouchPoints = false

        // Move control back to original position
        xPositionDelta = 0
        yPositionDelta = 0

        // Center sticks
        stickPositionX = _centerXY
        if (!yAxisThrottle) {
            stickPositionY = _centerXY
        }
    }

    function thumbDown(touchPoints)
    {
        // Position the control around the initial thumb position
        xPositionDelta = touchPoints[0].x - _centerXY
        if (yAxisThrottle) {
            yPositionDelta = touchPoints[0].y - stickPositionY
        } else {
            yPositionDelta = touchPoints[0].y - _centerXY
        }

        // We need to wait until we move the control to the right position before we process touch points
        _processTouchPoints = true
    }

    /*
    // Keep in for debugging
    Column {
        QGCLabel { text: xAxis }
        QGCLabel { text: yAxis }
    }
    */

    Image {
        anchors.fill:       parent
        source:             yAxisThrottle ? "qrc:/res/resources/Direction_control.png" : "qrc:/res/resources/Accelerator_control.png"
        mipmap:             true
        smooth:             true
    }

    Rectangle {
        anchors.margins:    parent.width / 4
        anchors.fill:       parent
        radius:             width / 2
        border.color:       mapPal.thumbJoystick
        border.width:       2
        color:              "transparent"
    }

    Rectangle {
        anchors.fill:       parent
        radius:             width / 2
        border.color:       mapPal.thumbJoystick
        border.width:       2
        color:              "transparent"
    }

    Rectangle {
        width:  hatWidth
        height: hatWidth
        radius: hatWidthHalf
        color:  "white"  //mapPal.thumbJoystick
        x:      stickPositionX - hatWidthHalf
        y:      stickPositionY - hatWidthHalf

        readonly property real hatWidth:        ScreenTools.defaultFontPixelHeight
        readonly property real hatWidthHalf:    ScreenTools.defaultFontPixelHeight / 2
    }

    Connections {
        target: touchPoint

        onXChanged: {
            if (_processTouchPoints) {
                _joyRoot.stickPositionX = Math.max(Math.min(touchPoint.x, _joyRoot.width), 0)
            }
        }
        onYChanged: {
            if (_processTouchPoints) {
                _joyRoot.stickPositionY = Math.max(Math.min(touchPoint.y, _joyRoot.height), 0)
            }
        }
    }

    MultiPointTouchArea {
        anchors.fill:       parent
        minimumTouchPoints: 1
        maximumTouchPoints: 1
        touchPoints:        [ TouchPoint { id: touchPoint } ]

        onPressed:  _joyRoot.thumbDown(touchPoints)
        onReleased: _joyRoot.reCenter()
    }
}
