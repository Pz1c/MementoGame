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
        z: 10

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
        z: 0

        contentWidth: -1
        contentHeight: gvMain.height
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AsNeeded

        GridView {
            id: gvMain
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            height: Math.floor(100 / Math.ceil((mainWindow.width - anchors.leftMargin - anchors.rightMargin) / cellWidth)) * cellHeight
            cellHeight: 158
            cellWidth: 105
            cacheBuffer: height * 4
            displayMarginBeginning: height * 4
            displayMarginEnd: height * 4

            delegate: MementoCard {
                id: mdItem
                source: gvMain.model[index].src
                status: gvMain.model[index].status

                /*height: 156
                width: 100*/
                height: 158
                width: 105

                onClicked: {
                    console.log("MementoCard clicked", index);
                    core.click(index);
                }
            }
        }

        MementoCore {
            id: core

            onScoreChanged: function (score) {
                var new_score = "Score: " + score;
                console.log("core.onScoreChanged", new_score);
                ltScore.text = new_score;
            }

            onAction: function (idx, command) {
                console.log("core.onAction", idx, command);
                var card = gvMain.itemAtIndex(idx);
                if (!card) {
                    console.log("core.onAction", "not found item!!");
                    return;
                }
                //console.log("core.onAction", JSON.stringify(card));

                switch(command) {
                case "close":
                    card.showBack();
                    gvMain.model[idx].status = 0;
                    break;
                case "open":
                    card.showFront();
                    gvMain.model[idx].status = 1;
                    break;
                }
            }

            onGameStarted: function (card_model) {
                console.log("core.onGameStarted", card_model);
                gvMain.model = JSON.parse(card_model);
            }

            onReady: {
                coreReady = true;
                if (qmlReady) {
                    core.startGame();
                }
            }
        }
    }

    property bool qmlReady: false
    property bool coreReady: false

    Component.onCompleted: {
        qmlReady = true;
        if (coreReady) {
            core.startGame();
        }
    }

    /*function gameScoreChanged(score) {
        var new_score = "Score: " + score;
        console.log("core.onScoreChanged", new_score);
        ltScore.text = new_score;
    }

    function gameStart(card_model){
        console.log("core.onGameStarted", card_model);
        gvMain.model = JSON.parse(card_model);
    }*/
}
