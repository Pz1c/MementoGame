import QtQuick
import QtQuick.Window
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import ua.sp.memento 0.1
import "qrc:/qml"

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Memento game")


    Rectangle {
        id: rTop
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.167 * parent.height

        color: "grey"

        BtnBig {
            id: btnStart
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            height: 0.8 * parent.height
            width: 0.25 * parent.width
            text: "Start new game"

            onClicked: {
                core.startGame();
            }
        }

        LargeText {
            id: ltScore
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            height: 0.8 * parent.height
            width: 0.25 * parent.width
            text: "Score: 0"
        }
    }

    ScrollView {
        id: svMain
        anchors.top: rTop.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        contentWidth: -1
        contentHeight: gvMain.height
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AsNeeded

        GridView {
            id: gvMain
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: Math.floor(100 / Math.ceil(mainWindow.width / cellWidth)) * cellHeight
            cellHeight: 158
            cellWidth: 105

            model: [/*"file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_annis_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_annis_l.tga",
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_wolfwint_l.tga"*/]

            delegate: Column {
                height: 158
                width: 105

                MementoCard {
                    id: mdItem
                    source: gvMain.model[index].src

                    height: 156
                    width: 100

                    onClicked: {
                        console.log("MementoCard clicked", index);
                        //toogle();
                        core.click(index);
                    }
                }
            }
        }

        MementoCore {
            id: core

            onScoreChanged: {
                var new_score = "Score: " + core.score;
                console.log("core.onScoreChanged", new_score);
                ltScore.text = new_score;
            }

            onAction: {
                console.log("core.onAction", idx, command);
            }

            onGameStarted: {
                console.log("core.onGameStarted", card_model);
                gvMain.model = JSON.parse(card_model);
            }
        }
    }

    Component.onCompleted: {
        core.startGame();
    }
}
