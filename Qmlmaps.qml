import QtQuick 2.0
import QtLocation 5.9
import QtPositioning 5.9

Rectangle {
    id: window
    width: 800
    height: 600

    // Coordonnées d'Ariana
    property double latitude_1: 36.8666  // Latitude d'Ariana
    property double longitude_1: 10.1895  // Longitude d'Ariana

    // Coordonnées de Tunis
    property double latitude_2: 33.8869  // Latitude de Tunis
    property double longitude_2: 9.5375  // Longitude de Tunis

    // Coordonnées intermédiaires entre Ariana et Tunis
    property double latitude_middle: (latitude_1 + latitude_2) / 2
    property double longitude_middle: (longitude_1 + longitude_2) / 2

    property Component locationmarker_1: locmarker_1
    property Component locationmarker_2: locmarker_2

    Plugin {
        id: osmPlugin
        name: "osm" // Utilisation de OpenStreetMap
    }

    Map {
        id: mapview
        anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(latitude_middle, longitude_middle) // Centrer entre Ariana et Tunis
        zoomLevel: 12
    }

    function setCenterPosition(lati, longi) {
        mapview.pan(latitude_middle - lati, longitude_middle - longi)
        latitude_middle = lati
        longitude_middle = longi
    }

    function setLocationMarking_1(lati, longi) {
        var item = locationmarker_1.createObject(window, {
            Coordinate: QtPositioning.coordinate(lati, longi)
        })
        mapview.addMapItem(item)
    }

    function setLocationMarking_2(lati, longi) {
        var item = locationmarker_2.createObject(window, {
            Coordinate: QtPositioning.coordinate(lati, longi)
        })
        mapview.addMapItem(item)
    }

    Component {
        id: locmarker_1
        MapQuickItem {
            id: locationMarker
            coordinate: QtPositioning.coordinate(latitude_1, longitude_1) // Position du marqueur pour Ariana
            anchorPoint.x: icon.width / 2
            anchorPoint.y: icon.height / 2
            sourceItem: Image {
                id: icon
                width: 32
                height: 32
                source: "qrc:/images/marker-icon.png" // Assure-toi que le fichier est correctement ajouté au .qrc
            }
        }
    }

    Component {
        id: locmarker_2
        MapQuickItem {
            id: locationMarker
            coordinate: QtPositioning.coordinate(latitude_2, longitude_2) // Position du marqueur pour Tunis
            anchorPoint.x: icon.width / 2
            anchorPoint.y: icon.height / 2
            sourceItem: Image {
                id: icon
                width: 32
                height: 32
                source: "qrc:/images/marker-icon.png" // Assure-toi que le fichier est correctement ajouté au .qrc
            }
        }
    }
}
