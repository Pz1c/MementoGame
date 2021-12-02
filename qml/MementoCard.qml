import QtQuick 2.15

Item {
    id: iMementoCard

    property alias source: mcFront.source
    property int status: 0
    signal clicked

    Rectangle {
        id: mcBack
        anchors.fill: parent
        anchors.leftMargin: 3
        anchors.rightMargin: 3
        anchors.topMargin: 3
        anchors.bottomMargin: 3
        color: "red"
        border.color: "blue"
        border.width: 2

        Image {
            id: mcFront
            anchors.centerIn: parent
            width: parent.width - mcBack.border.width * 2
            height: parent.height - mcBack.border.width * 2
            opacity: status === 0 ? 1 : 0
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
        onFinished: {
            status = 1;
        }
    }

    NumberAnimation {
        id: paBack
        target: mcFront
        property: "opacity"
        from: 1
        to: 0
        duration: 300
        onFinished: {
            status = 0;
        }
    }

    function showFront() {
        paFront.start();
    }

    function showBack() {
        status = 0;
        paBack.start();
    }

    function toogle() {
        if (paFront.running || paBack.running) {
            return;
        }
        if (status === 0) {
            showFront();
        } else {
            showBack();
        }
    }
}
