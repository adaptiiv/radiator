/*
 * Radiator
 * Copyright (C) 2018  Stefan Böhmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
import QtQuick 2.9
import QtQuick.Controls 2.2
import Radiator 1.0

import "."

Rectangle {
    id: root
    property int status: Build.Unknown
    property string buildNumber: "Hello"
    border.color: "black"
    border.width: 1
    color: Fonts.getJobBackgroundColor(root.status, 0.8)

    ToolTip.visible: ma.containsMouse
    ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
    ToolTip.text: buildNumber

    MouseArea {
        id: ma
        anchors.fill: parent
        hoverEnabled: true
    }
}
