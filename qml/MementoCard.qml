import QtQuick 2.15

Item {
    id: iMementoCard

    property alias source: mcFront.source
    property int status: 0
    signal clicked

    Rectangle {
        id: mcBack
        anchors.fill: parent
        opacity: 1
        color: "red"
        border.color: "blue"
        border.width: 2

        Image {
            id: mcFront
            anchors.centerIn: parent
            width: parent.width - mcBack.border.width * 2
            height: parent.height - mcBack.border.width * 2
            opacity: 0
        }

        MouseArea {
            id: maBack
            anchors.fill: parent

            onClicked: {
                iMementoCard.clicked();
            }
        }
    }

    NumberAnimation {
        id: paFront
        running: false
        target: mcFront
        property: "opacity"
        from: 0
        to: 1
        duration: 300
    }

    NumberAnimation {
        id: paBack
        target: mcFront
        property: "opacity"
        from: 1
        to: 0
        duration: 300
    }

    function showFront() {
        paFront.start();
    }

    function showBack() {
        paBack.start();
    }

    function toogle() {
        if (paFront.running || paBack.running) {
            return;
        }
        status = status ? 0 : 1;
        if (status === 1) {
            showFront();
        } else {
            showBack();
        }
    }
}
