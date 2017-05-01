/*=====================================================================

 QGroundControl Open Source Ground Control Station

 (c) 2009 - 2015 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

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
import QtQuick.Controls         1.2
import QtQuick.Controls.Styles  1.2
import QtQuick.Dialogs          1.1

import QGroundControl                       1.0
import QGroundControl.FactSystem            1.0
import QGroundControl.FactControls          1.0
import QGroundControl.Controls              1.0
import QGroundControl.ScreenTools           1.0
import QGroundControl.MultiVehicleManager   1.0
import QGroundControl.Palette               1.0

Rectangle {

    id:                 _generalRoot
    color:              __qgcPal.window
    anchors.fill:       parent
    anchors.margins:    ScreenTools.defaultFontPixelWidth

    QGCPalette {
        id:                 qgcPal
        colorGroupEnabled:  enabled
    }

    QGCFlickable {
        clip:               true
        anchors.fill:       parent
        contentHeight:      settingsColumn.height
        contentWidth:       settingsColumn.width


        Column {
            id:                 settingsColumn
            anchors.margins:    ScreenTools.defaultFontPixelWidth
            spacing:            ScreenTools.defaultFontPixelHeight / 2

            QGCLabel {
                text:   "Control mode switching"
                font.pixelSize: ScreenTools.mediumFontPixelSize
            }
            Rectangle {
                height: 1
                width:  parent.width
                color:  qgcPal.button
            }
            Item {
                height: ScreenTools.defaultFontPixelHeight / 2
                width:  parent.width
            }


            //-----------------------------------------------------------------


            //-----------------------------------------------------------------
            //-- Palette Styles
            Row {
                spacing:    ScreenTools.defaultFontPixelWidth
                QGCLabel {
                    width: ScreenTools.defaultFontPixelWidth * 16
                    text: "RC Mode"
                }
                QGCComboBox {
                    width: ScreenTools.defaultFontPixelWidth * 20
                    model: [ "Mode 1: Japanese", "Mode 2: American", "Mode 3: Chinese", "Mode 4: Gravity" ]
                    currentIndex: QGroundControl.rcMode
                    onActivated: {
                        if (index != -1) {
                            currentIndex = index
                            console.warn( "-------index = "+ index)
                            QGroundControl.rcMode = index
                        }
                    }
                }
            }

            Item {
                height: ScreenTools.defaultFontPixelHeight / 2
                width:  parent.width
            }



            Row {
                spacing:    ScreenTools.defaultFontPixelWidth

                Image {
                    id:                 _JapaneseRC
                    visible:            QGroundControl.rcMode == 0
                    source:             "qrc:/qmlimages/resources/JapaneseRC.png"
                    mipmap:             true
                    smooth:             true
                }

                Image {
                    id:                 _AmericanRC
                    visible:            QGroundControl.rcMode == 1
                    source:             "qrc:/qmlimages/resources/AmericanRC.png"
                    mipmap:             true
                    smooth:             true
                }


                Image {
                    id:                 _ChineseRC
                    visible:            QGroundControl.rcMode == 2
                    source:             "qrc:/qmlimages/resources/ChineseRC.png"
                    mipmap:             true
                    smooth:             true
                }

                Image {
                    id:                 _GravityRC
                    visible:            QGroundControl.rcMode == 3
                    source:             "qrc:/qmlimages/resources/GravityRC.png"
                    mipmap:             true
                    smooth:             true
                }

            }





        }
    }
}
