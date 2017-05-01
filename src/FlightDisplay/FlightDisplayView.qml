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

import QtQuick                  2.5
import QtQuick.Controls         1.3
import QtQuick.Controls.Styles  1.2
import QtQuick.Dialogs          1.2
import QtLocation               5.3
import QtPositioning            5.2

import QGroundControl               1.0
import QGroundControl.FlightDisplay 1.0
import QGroundControl.FlightMap     1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.Vehicle       1.0
import QGroundControl.Controllers   1.0
import QGroundControl.FactSystem    1.0

/// Flight Display View
QGCView {
    id:             root
    viewPanel:      _panel
    topDialogMargin: height - availableHeight

    QGCPalette { id: qgcPal; colorGroupEnabled: enabled }

    property real availableHeight: parent.height

    readonly property bool isBackgroundDark: _mainIsMap ? (_flightMap ? _flightMap.isSatelliteMap : true) : true

    property var _activeVehicle:    multiVehicleManager.activeVehicle

    readonly property real _defaultRoll:                0
    readonly property real _defaultPitch:               0
    readonly property real _defaultHeading:             0
    readonly property real _defaultAltitudeAMSL:        0
    readonly property real _defaultGroundSpeed:         0
    readonly property real _defaultAirSpeed:            0

    readonly property string _mapName:                  "FlightDisplayView"
    readonly property string _showMapBackgroundKey:     "/showMapBackground"
    readonly property string _mainIsMapKey:             "MainFlyWindowIsMap"
    readonly property string _PIPVisibleKey:            "IsPIPVisible"

    property bool _mainIsMap:           QGroundControl.loadBoolGlobalSetting(_mainIsMapKey,  true)
    property bool _isPipVisible:        QGroundControl.loadBoolGlobalSetting(_PIPVisibleKey, true)

    property real _roll:                _activeVehicle ? _activeVehicle.roll.value    : _defaultRoll
    property real _pitch:               _activeVehicle ? _activeVehicle.pitch.value   : _defaultPitch
    property real _heading:             _activeVehicle ? _activeVehicle.heading.value : _defaultHeading


    property Fact _emptyFact:               Fact { }
    property Fact _groundSpeedFact:         _activeVehicle ? _activeVehicle.groundSpeed      : _emptyFact
    property Fact _airSpeedFact:            _activeVehicle ? _activeVehicle.airSpeed         : _emptyFact

    property bool activeVehicleJoystickEnabled: _activeVehicle ? _activeVehicle.joystickEnabled : false

    property real _savedZoomLevel:      0

    property real pipSize:              mainWindow.width * 0.2

//    property bool _gravIsPressed:       false
    property bool _takeoffIsPressed:    false


    property real _speedCounter:        0

    property bool _throwIsPressed:       false
    property bool _colorChooseIsPressed:       false
    property bool _rotatingIsPressed:       false

    FlightDisplayViewController { id: _controller }

    function setStates() {
        if(_mainIsMap) {
            //-- Adjust Margins
            _flightMapContainer.state   = "fullMode"
            //_flightVideo.state          = "pipMode"
            //-- Save/Restore Map Zoom Level
            if(_savedZoomLevel != 0)
                _flightMap.zoomLevel = _savedZoomLevel
            else
                _savedZoomLevel = _flightMap.zoomLevel
        } else {
            //-- Adjust Margins
            _flightMapContainer.state   = "pipMode"
            //_flightVideo.state          = "fullMode"
            //-- Set Map Zoom Level
            _savedZoomLevel = _flightMap.zoomLevel
            _flightMap.zoomLevel = _savedZoomLevel - 3
        }
    }

    function setPipVisibility(state) {
        _isPipVisible = state;
        QGroundControl.saveBoolGlobalSetting(_PIPVisibleKey, state)
    }

    function px4JoystickCheck() {
        if (_activeVehicle && !_activeVehicle.px4Firmware && (QGroundControl.virtualTabletJoystick || _activeVehicle.joystickEnabled)) {
            px4JoystickSupport.open()
        }
    }

    MessageDialog {
        id:     px4JoystickSupport
        text:   "Joystick support requires MAVLink MANUAL_CONTROL support. " +
                "The firmware you are running does not normally support this. " +
                "It will only work if you have modified the firmware to add MANUAL_CONTROL support."
    }

    Connections {
        target: multiVehicleManager
        onActiveVehicleChanged: px4JoystickCheck()
    }

    Connections {
        target: QGroundControl
        onVirtualTabletJoystickChanged: px4JoystickCheck()
    }

    onActiveVehicleJoystickEnabledChanged: px4JoystickCheck()

    Component.onCompleted: {
        widgetsLoader.source = "FlightDisplayViewWidgets.qml"
        setStates()
        px4JoystickCheck()
    }

    Image {
        id:             background
        anchors.fill: parent
        fillMode: Image.Tile
        source:         "qrc:/qmlimages/resources/Control_bg.png"
        mipmap:         true
        anchors.horizontalCenter: parent.horizontalCenter
        visible:        true
        height:         ScreenTools.defaultFontPixelSize
        width:          ScreenTools.defaultFontPixelSize
        z: -3

    }

    QGCViewPanel {
        id:             _panel
        anchors.fill:   parent

        //-- Map View
        //   For whatever reason, if FlightDisplayViewMap is the _panel item, changing
        //   width/height has no effect.
        Item {
            id: _flightMapContainer
//            z:  _mainIsMap ? _panel.z + 1 : _panel.z + 2
            z:  _mainIsMap ? _panel.z - 5 : _panel.z - 4
            anchors.left:   _panel.left
            anchors.bottom: _panel.bottom
            visible:        _mainIsMap || _isPipVisible
            width:          _mainIsMap ? _panel.width  : pipSize
            height:         _mainIsMap ? _panel.height : pipSize * (9/16)
            states: [
                State {
                    name:   "pipMode"
                    PropertyChanges {
                        target:             _flightMapContainer
                        anchors.margins:    ScreenTools.defaultFontPixelHeight
                    }
                },
                State {
                    name:   "fullMode"
                    PropertyChanges {
                        target:             _flightMapContainer
                        anchors.margins:    0
                    }
                }
            ]
//            FlightDisplayViewMap {
//                id:             _flightMap
//                anchors.fill:   parent
//            }
        }

        //-- Video View
//        FlightDisplayViewVideo {
//            id:             _flightVideo
//            z:              _mainIsMap ? _panel.z + 2 : _panel.z + 1
//            width:          !_mainIsMap ? _panel.width  : pipSize
//            height:         !_mainIsMap ? _panel.height : pipSize * (9/16)
//            anchors.left:   _panel.left
//            anchors.bottom: _panel.bottom
//            visible:        _controller.hasVideo && (!_mainIsMap || _isPipVisible)
//            states: [
//                State {
//                    name:   "pipMode"
//                    PropertyChanges {
//                        target: _flightVideo
//                        anchors.margins:    ScreenTools.defaultFontPixelHeight
//                    }
//                },
//                State {
//                    name:   "fullMode"
//                    PropertyChanges {
//                        target: _flightVideo
//                        anchors.margins:    0
//                    }
//                }
//            ]
//        }

//        QGCPipable {
//            id:                 _flightVideoPipControl
//            z:                  _flightVideo.z + 3
//            width:              pipSize
//            height:             pipSize * (9/16)
//            anchors.left:       _panel.left
//            anchors.bottom:     _panel.bottom
//            anchors.margins:    ScreenTools.defaultFontPixelHeight
//            isHidden:           !_isPipVisible
//            isDark:             isBackgroundDark
//            onActivated: {
//                _mainIsMap = !_mainIsMap
//                setStates()
//            }
//            onHideIt: {
//                setPipVisibility(!state)
//            }
//        }

//////////////////////top button group//////////////////////////////
        MouseArea {
            id:                     _backButtonArea
            width:                  _backButton.width
            height:                 _backButton.height
            anchors.left:           parent.left
            anchors.leftMargin:     width/7
            anchors.top:            parent.top
            anchors.topMargin:      ScreenTools.defaultFontPixelHeight * 2
            Image {
                id:     _backButton
                source: "qrc:/qmlimages/resources/btn_back_nor.png"
            }
            onPressed: {
                 _backButton.source = "qrc:/qmlimages/resources/btn_back_press.png"
            }
            onReleased: {
                _backButton.source = "qrc:/qmlimages/resources/btn_back_nor.png"
            }
            onClicked: {
                //back to the setting page
            }
        }

        MouseArea {
            id:                     __speedButtonArea
            width:                  _speedButton.width
            height:                 _speedButton.height
            anchors.left:           parent.left
            anchors.leftMargin:     ScreenTools.defaultFontPixelHeight * 5
            anchors.top:            parent.top
            anchors.topMargin:      ScreenTools.defaultFontPixelHeight * 2
            Image {
                id:     _speedButton
                source: "qrc:/qmlimages/resources/btn_speed.png"
                Text {
                    id:               _speedText
                    anchors.centerIn: _speedButton
                    text: qsTr("30%")
                    color: "#FFF"
                    font {
                        pixelSize: 34
                    }
                }
            }
            onClicked: {
                //the adjust line change its position
                switch(_speedCounter)
                {
                    case 0:
                    {
                        _speedText.text=qsTr("60%")
                        _speedCounter++
                         _activeVehicle.speedAmount = 60
                        break;
                    }
                    case 1:
                    {
                        _speedText.text=qsTr("100%")
                        _speedCounter++
                        _activeVehicle.speedAmount = 100
                        break;
                    }
                    case 2:
                    {
                        _speedText.text=qsTr("30%")
                        _speedCounter=0
                        _activeVehicle.speedAmount = 30
                        break;
                    }
                    default:
                        _speedText.text=qsTr("30%")
                        break;
                }

            }
        }

        MouseArea {
            id:                     _throwButtonArea
            width:                  _throwButton.width
            height:                 _throwButton.height
            anchors.left:           parent.left
            anchors.leftMargin:     ScreenTools.defaultFontPixelHeight * 10
            anchors.top:            parent.top
            anchors.topMargin:      ScreenTools.defaultFontPixelHeight * 2
            Image {
                id:     _throwButton
                source: _throwIsPressed?"qrc:/qmlimages/resources/btn_throw_press.png":"qrc:/qmlimages/resources/btn_throw_nor.png"
            }
            onClicked: {
                if(_throwIsPressed)
                {
                    _throwIsPressed = false
                    _activeVehicle.throwFly = 1
                }
                else
                     _throwIsPressed = true
            }
        }

        MouseArea {
            id:                     _colorChooseButtonArea
            width:                  _colorChooseButton.width
            height:                 _colorChooseButton.height
            anchors.right:           parent.right
            anchors.rightMargin:     ScreenTools.defaultFontPixelHeight * 10
            anchors.top:            parent.top
            anchors.topMargin:      ScreenTools.defaultFontPixelHeight * 2
            Image {
                id:     _colorChooseButton
                source: _colorChooseIsPressed?"qrc:/qmlimages/resources/btn_light_press.png":"qrc:/qmlimages/resources/btn_light_nor.png"
            }
            onClicked: {
                if(_colorChooseIsPressed)
                     _colorChooseIsPressed = false
                else
                     _colorChooseIsPressed = true
            }
        }

        MouseArea {
            id:                     _rotatingButtonArea
            width:                  _rotatingButton.width
            height:                 _rotatingButton.height
            anchors.right:           parent.right
            anchors.rightMargin:     ScreenTools.defaultFontPixelHeight * 5
            anchors.top:            parent.top
            anchors.topMargin:      ScreenTools.defaultFontPixelHeight * 2
            Image {
                id:     _rotatingButton
                source: _rotatingIsPressed?"qrc:/qmlimages/resources/btn_roll_press.png":"qrc:/qmlimages/resources/btn_roll_nor.png"
            }
            onClicked: {
                if(_rotatingIsPressed)
                {
                    _rotatingIsPressed = false
                    _activeVehicle.spinDirection = 1
                }
                else
                {
                     _rotatingIsPressed = true
                    _activeVehicle.spinDirection = 2
                }
            }
        }

        Rectangle {
            id:             _batteryIcon
            width:                  _batteryPicture.width
            height:                 _batteryPicture.height
            anchors.right:           parent.right
            anchors.rightMargin:     ScreenTools.defaultFontPixelHeight * 1
            anchors.top:            parent.top
            anchors.topMargin:      ScreenTools.defaultFontPixelHeight * 2.5
            Image {
                id:     _batteryPicture
                source: "qrc:/qmlimages/resources/Battery_nor.png"
                Text {
                    anchors.centerIn:   _batteryPicture
                    text:               qsTr("100%")
                    color:              "white"
                    font {
                        pixelSize: 14
                    }
                 //when received from the MAV, the remaining battery should be changed accordingly

                }
            }
        }
//////////////////////top button group//////////////////////////////
//////////////////////bottom background//////////////////////////////
        Rectangle {
            id:             _bottomBackground
            height:         92
            width:          parent.width
            color:          "#000"
            opacity:        0.35
            anchors.left:   parent.left
            anchors.bottom: parent.bottom
        }
////////////////////////bottom background////////////////////////////
//////////////////////////bottom Nudge buttons group////////////////////////////
            MouseArea {
                id:                     __adjustLeftArea
                width:                  _adjustLeft.width
                height:                 _adjustLeft.height
                anchors.left:           parent.left
                anchors.leftMargin:     width/15
                anchors.bottom:         parent.bottom
                anchors.bottomMargin:   2
                Image {
                    id:     _adjustLeft
                    source: "qrc:/qmlimages/resources/btn_AdjustLeft_nor.png"
                }
                onClicked: {
                    //the adjust line change its position
                     _leftAdjustBarPoint.anchors.horizontalCenterOffset -= 2
                }
                onPressed: {
                     _adjustLeft.source = "qrc:/qmlimages/resources/btn_AdjustLeft_press.png"
                }
                onReleased: {
                    _adjustLeft.source = "qrc:/qmlimages/resources/btn_AdjustLeft_nor.png"
                }
            }

            Image{
                id:             _leftAdjustBar
                source:         "qrc:/qmlimages/resources/bar_adjust.png"
                anchors.left:           __adjustLeftArea.right
                anchors.leftMargin:     1
                anchors.verticalCenter: _bottomBackground.verticalCenter
//                anchors.bottom:         parent.bottom
//                anchors.bottomMargin:   2
            }

            MouseArea {
                width:                  _adjustRight.width
                height:                 _adjustRight.height
                anchors.left:           _leftAdjustBar.right
                anchors.leftMargin:     1
                anchors.bottom:         parent.bottom
                anchors.bottomMargin:   2
                Image {
                    id:     _adjustRight
                    source: "qrc:/qmlimages/resources/btn_AdjustRight_nor.png"
                    opacity: 1
                }
                onClicked: {
                    //the point on the adjust line change its position
                    _leftAdjustBarPoint.anchors.horizontalCenterOffset += 2
                }
                onPressed: {
                     _adjustRight.source = "qrc:/qmlimages/resources/btn_AdjustRight_press.png"
                }
                onReleased: {
                    _adjustRight.source = "qrc:/qmlimages/resources/btn_AdjustRight_nor.png"
                }
            }

            Image{
                id:                             _leftAdjustBarPoint
                source:                         "qrc:/qmlimages/resources/point_adjust.png"
                anchors.horizontalCenter:       _leftAdjustBar.horizontalCenter
                anchors.verticalCenter:         _bottomBackground.verticalCenter
            }
////////////////////////////////////////////////////////////////////////////////////////////////////
            //takeoff and landing button
            MouseArea {
                id:             btnTakeoffLanding
                width: _takeoffButton.width
                height: _takeoffButton.height
                anchors.bottom:                parent.bottom
                anchors.bottomMargin:          1
                anchors.horizontalCenter:   parent.horizontalCenter

                Image {
                    id: _takeoffButton
                    source: _takeoffIsPressed?"qrc:/qmlimages/resources/btn_landing_nor.png":"qrc:/qmlimages/resources/btn_takeoff_nor.png"
                    Text {
                        anchors.centerIn:   _takeoffButton
                        text:               _takeoffIsPressed ? qsTr("Landing"):qsTr("Takeoff")
                        color:              _takeoffIsPressed ?"orange":"lightgreen"
                        font {
                            pixelSize: 34
                        }
                    }
                }
                onClicked: {
                    if(_takeoffIsPressed)
                    {
                         _takeoffIsPressed = false
                        _activeVehicle.takeoffOrLanddown = !_activeVehicle.takeoffOrLanddown
                    }
                    else
                    {
                         _takeoffIsPressed = true
                        _activeVehicle.takeoffOrLanddown = !_activeVehicle.takeoffOrLanddown
                    }
                }
            }

////////////////////////////////////horizontal right Nudge buttons group////////////////////////////////////////////
            //Nudge buttons group
            MouseArea {
                id:                     __adjustLeftArea2
                width:                  _adjustLeft2.width
                height:                 _adjustLeft2.height
                anchors.left:           btnTakeoffLanding.right
                anchors.leftMargin:     6
                anchors.bottom:         parent.bottom
                anchors.bottomMargin:   2
                Image {
                    id:     _adjustLeft2
                    source: "qrc:/qmlimages/resources/btn_AdjustLeft_nor.png"
                }
                onClicked: {
                    //the adjust line change its position
                     _leftAdjustBarPoint2.anchors.horizontalCenterOffset -= 2
                }
                onPressed: {
                     _adjustLeft2.source = "qrc:/qmlimages/resources/btn_AdjustLeft_press.png"
                }
                onReleased: {
                    _adjustLeft2.source = "qrc:/qmlimages/resources/btn_AdjustLeft_nor.png"
                }
            }

            Image{
                id:             _leftAdjustBar2
                source:         "qrc:/qmlimages/resources/bar_adjust.png"
                anchors.left:           __adjustLeftArea2.right
                anchors.leftMargin:     1
                anchors.verticalCenter: _bottomBackground.verticalCenter
//                anchors.bottom:         parent.bottom
//                anchors.bottomMargin:   2
            }

            MouseArea {
                width:                  _adjustRight2.width
                height:                 _adjustRight2.height
                anchors.left:           _leftAdjustBar2.right
                anchors.leftMargin:     1
                anchors.bottom:         parent.bottom
                anchors.bottomMargin:   2
                Image {
                    id:     _adjustRight2
                    source: "qrc:/qmlimages/resources/btn_AdjustRight_nor.png"
                    opacity: 1
                }
                onClicked: {
                    //the point on the adjust line change its position
                    _leftAdjustBarPoint2.anchors.horizontalCenterOffset += 2
                }
                onPressed: {
                     _adjustRight2.source = "qrc:/qmlimages/resources/btn_AdjustRight_press.png"
                }
                onReleased: {
                    _adjustRight2.source = "qrc:/qmlimages/resources/btn_AdjustRight_nor.png"
                }
            }

            Image{
                id:                             _leftAdjustBarPoint2
                source:                         "qrc:/qmlimages/resources/point_adjust.png"
                anchors.horizontalCenter:       _leftAdjustBar2.horizontalCenter
                anchors.verticalCenter:         _bottomBackground.verticalCenter
            }
////////////////////////////////////horizontal right Nudge buttons group////////////////////////////////////////////
/////////////////////////////VerticalRightSideNudgeButtonGroup/////////////////////////////////////////////////////
        //Right side Nudge buttons group
        MouseArea {
            id:                     __adjustSideArea2
            width:                  _adjustSideUp2.width
            height:                 _adjustSideUp2.height
            anchors.right:           parent.right
            anchors.rightMargin:     1
            anchors.bottom:         _leftSideAdjustBar2.top
            anchors.bottomMargin:   1
//            anchors.left:           _leftSideAdjustBar2.right
//            anchors.leftMargin:     1

            Image {
                id:     _adjustSideUp2
                source: "qrc:/qmlimages/resources/btn_AdjustLeft_nor.png"
                rotation: 90
            }
            onClicked: {
                //the adjust line change its position
                 _leftSideAdjustBarPoint2.anchors.verticalCenterOffset -= 1
            }
            onPressed: {
                 _adjustSideUp2.source = "qrc:/qmlimages/resources/btn_AdjustLeft_press.png"
            }
            onReleased: {
                _adjustSideUp2.source = "qrc:/qmlimages/resources/btn_AdjustLeft_nor.png"
            }
        }

        Image{
            id:             _leftSideAdjustBar2
            source:         "qrc:/qmlimages/resources/bar_adjust_vertical.png"
            anchors.right:          parent.right
            anchors.rightMargin:    ScreenTools.defaultFontPixelWidth * 2.5
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            id:                     _adjustBottom
            width:                  _adjustSidedown2.width
            height:                 _adjustSidedown2.height
            anchors.top:           _leftSideAdjustBar2.bottom
            anchors.topMargin:     1
            anchors.right:         parent.right
            anchors.rightMargin:   1
            Image {
                id:     _adjustSidedown2
                source: "qrc:/qmlimages/resources/btn_AdjustRight_nor.png"
                opacity: 1
                rotation: 90
            }
            onClicked: {
                //the point on the adjust line change its position
                _leftSideAdjustBarPoint2.anchors.verticalCenterOffset += 1
            }
            onPressed: {
                 _adjustSidedown2.source = "qrc:/qmlimages/resources/btn_AdjustRight_press.png"
            }
            onReleased: {
                _adjustSidedown2.source = "qrc:/qmlimages/resources/btn_AdjustRight_nor.png"
            }
        }

        Image{
            id:                             _leftSideAdjustBarPoint2
            source:                         "qrc:/qmlimages/resources/point_adjust.png"
            anchors.horizontalCenter:       _leftSideAdjustBar2.horizontalCenter
            anchors.verticalCenter:         parent.verticalCenter
            rotation:                       90
        }
///////////////////////////////VerticalRightSideNudgeButtonGroup///////////////////////////////////////////

///////////////////////////////ColorChooseButtonGroup///////////////////////////////////////////
        Rectangle {
            id:                              _ColorChooseBackground
            visible:                        _colorChooseIsPressed
            width:                            _ColorChooseBackgrdPic.width
            height:                          _ColorChooseBackgrdPic.height
            radius:                         50
            anchors.horizontalCenter:        parent.horizontalCenter
            anchors.horizontalCenterOffset:    parent.width/7
            anchors.verticalCenter:     parent.verticalCenter
            anchors.verticalCenterOffset:    parent.height/12
            Image {
                id:     _ColorChooseBackgrdPic
                source: "qrc:/qmlimages/resources/Color_bg.png"
            }

            MouseArea {
                width:                      _whiteButton.width
                height:                     _whiteButton.height
                anchors.top:                parent.top
                anchors.topMargin:          1
                anchors.horizontalCenter:   parent.horizontalCenter

                Image {
                    id:     _whiteButton
                    source: "qrc:/qmlimages/resources/btn_white_nor.png"

                }
                onClicked: {

                    _whiteButton.source =   "qrc:/qmlimages/resources/btn_white_press.png"
                    _blueButton.source  =   "qrc:/qmlimages/resources/btn_blue_nor.png"
                    _greenButton.source =   "qrc:/qmlimages/resources/btn_green_nor.png"
                    _redButton.source   =   "qrc:/qmlimages/resources/btn_red_nor.png"
                    _activeVehicle.ledColor = 1         //send the color change to white command

                }
            }

            MouseArea {
                width:                      _blueButton.width
                height:                     _blueButton.height
                anchors.horizontalCenter:       parent.horizontalCenter
                anchors.verticalCenter:         parent.verticalCenter
                anchors.verticalCenterOffset:   -parent.height/8

                Image {
                    id:     _blueButton
                    source: "qrc:/qmlimages/resources/btn_blue_nor.png"
                }
                onClicked: {

                    _whiteButton.source =   "qrc:/qmlimages/resources/btn_white_nor.png"
                    _blueButton.source  =   "qrc:/qmlimages/resources/btn_blue_press.png"
                    _greenButton.source =   "qrc:/qmlimages/resources/btn_green_nor.png"
                    _redButton.source   =   "qrc:/qmlimages/resources/btn_red_nor.png"
                    _activeVehicle.ledColor = 2             //send the color change to blue command
                 }
            }

            MouseArea {
                width:                          _greenButton.width
                height:                         _greenButton.height
                anchors.horizontalCenter:       parent.horizontalCenter
                anchors.verticalCenter:         parent.verticalCenter
                anchors.verticalCenterOffset:   parent.height/8

                Image {
                    id:     _greenButton
                    source: "qrc:/qmlimages/resources/btn_green_nor.png"
                }
                onClicked: {

                    _whiteButton.source =   "qrc:/qmlimages/resources/btn_white_nor.png"
                    _blueButton.source  =   "qrc:/qmlimages/resources/btn_blue_nor.png"
                    _greenButton.source =   "qrc:/qmlimages/resources/btn_green_press.png"
                    _redButton.source   =   "qrc:/qmlimages/resources/btn_red_nor.png"
                    _activeVehicle.ledColor = 3             //send the color change to green command
                }
            }

            MouseArea {
                width:                      _redButton.width
                height:                     _redButton.height
                anchors.bottom:                parent.bottom
                anchors.topMargin:          1
                anchors.horizontalCenter:   parent.horizontalCenter

                Image {
                    id:     _redButton
                    source: "qrc:/qmlimages/resources/btn_red_nor.png"
                }
                onClicked: {

                    _whiteButton.source =   "qrc:/qmlimages/resources/btn_white_nor.png"
                    _blueButton.source  =   "qrc:/qmlimages/resources/btn_blue_nor.png"
                    _greenButton.source =   "qrc:/qmlimages/resources/btn_green_nor.png"
                    _redButton.source   =   "qrc:/qmlimages/resources/btn_red_press.png"

                    _activeVehicle.ledColor = 4         //send the color change to red command
                }
            }

        }
///////////////////////////////ColorChooseButtonGroup///////////////////////////////////////////

//        MouseArea {
//            width: joystickControl.width
//            height: joystickControl.height
//            anchors.top:                parent.top
//            anchors.topMargin:          ScreenTools.defaultFontPixelHeight * 2
//            anchors.horizontalCenter:   parent.horizontalCenter

//            Image {
//                id: joystickControl
//                source: "qrc:/qmlimages/resources/btn_pattern.png"
//                Text {
//                    anchors.centerIn: joystickControl
//                    text: _gravIsPressed ? qsTr("GravMode"):qsTr("ComMode")
//                    color: "#FFF"
//                    font {
//                        pixelSize: 40
//                    }
//                }
//            }
//            onClicked: {
//                if(_gravIsPressed)
//                     _gravIsPressed = false
//                else
//                     _gravIsPressed = true

//            }
//        }



        //-- Widgets
        Loader {
            id:                 widgetsLoader
            z:                  _panel.z + 4
            anchors.right:      parent.right
            anchors.left:       parent.left
            anchors.bottom:     parent.bottom
            height:             availableHeight
            asynchronous:       true
            visible:            status == Loader.Ready

            property bool isBackgroundDark: root.isBackgroundDark
            property var qgcView: root
        }

        //-- Virtual Joystick
        Loader {
            id:                         multiTouchItem
            z:                          _panel.z + 5
            width:                      parent.width  - (pipSize / 2)
            height:                     Math.min(parent.height * 0.25, ScreenTools.defaultFontPixelWidth * 16)
            visible:                    true    //QGroundControl.virtualTabletJoystick
            anchors.bottom:             _adjustBottom.top
            anchors.bottomMargin:       ScreenTools.defaultFontPixelHeight * 1
            anchors.horizontalCenter:   parent.horizontalCenter
            source:                     "qrc:/qml/VirtualJoystick.qml"
            active:                     true    //QGroundControl.virtualTabletJoystick
        }
    }
}
