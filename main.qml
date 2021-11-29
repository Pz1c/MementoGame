import QtQuick
import QtQuick.Window
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import ua.sp.memento 0.1
import "qrc:/qml"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Memento game")


    MementoCore {
        id: core
    }

    ScrollView {
        id: svMain
        anchors.fill: parent
        contentWidth: -1
        contentHeight: 2720
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AsNeeded

        GridView {
            id: gvMain
            width: 640
            height: 2720
            cellHeight: 158
            cellWidth: 105

            model: ["file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_a_bat_l.tga",
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
                "file:///C:/Project/Qt/MementoGame/res/nw_portraits/po_wolfwint_l.tga"]

            delegate: Column {
                height: 158
                width: 105

                MementoCard {
                    id: mdItem
                    source: gvMain.model[index]

                    height: 156
                    width: 100

                    onClicked: {
                        console.log("MementoCard clicked", index);
                        toogle();
                    }
                }
            }
        }
    }
}
