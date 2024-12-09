
import QtQuick.Window 2.2


import QtQuick.Controls 2.0
import QtQuick 2.0
import QtLocation 5.9
import QtPositioning 5.9

Item {
    visible: true
    width: 640
    height: 480

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "https://tile.openstreetmap.org/"
        }
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(35.0354,9.4839)
        zoomLevel: 7
        activeMapType: map.supportedMapTypes[map.supportedMapTypes.length - 1]

        MapItemView {
            model: ListModel {
                id: markerModel
                ListElement { latitude: 33.8869; longitude: 9.5375 } // Default coordinates
                // Add more elements dynamically using JavaScript
            }

            delegate: MapQuickItem {
                anchorPoint.x: image.width/2
                anchorPoint.y: image.height
                coordinate: QtPositioning.coordinate(model.latitude, model.longitude)
                //anchorPoint: Qt.point(0.5, 1)
                sourceItem: Image {
                    id: image
                    source: "qrc:/icon/mapmarker.png"
                    sourceSize.width: 40
                    sourceSize.height: 40
                }

            }
        }

        Component.onCompleted: {
            // Clear the default coordinates
            markerModel.clear();

            // Add coordinates fetched from backend
            for (var i = 0; i < backend.dataList.length; ++i) {
                var coordinate = backend.dataList[i];
                markerModel.append({ "latitude": coordinate["LATITUDE"], "longitude": coordinate["LONGITUDE"] });
            }
        }

    }
}
