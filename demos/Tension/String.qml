import QtQuick

Item {
    id: root

    property real mass
    property real k: 1
    property real damping: 1
    property int count: 3
    property var elements: Array()

    function populate(n) {
        let component = Qt.createComponent("StringElement.qml")
        for (let i = 0; i < n; ++i)
            elements.push(component.createObject(stringRow, {
                                                     dm: mass/n,
                                                     k: root.k,
                                                     mu: damping,
                                   }))
        for (let j = 1; j < (n-1); ++j) {
            stringRow.children[j].previousElement = stringRow.children[j - 1]
            stringRow.children[j].nextElement = stringRow.children[j + 1]
        }

    }
    function start() {
        for (let element of elements)
            element.running = true
    }

    Row {
        id: stringRow
        spacing: 10
    }
    Component.onCompleted: {
        populate(count)
    }
}
