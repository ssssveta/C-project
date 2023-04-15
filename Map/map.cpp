#include <QFileDialog>
#include <utility>
#include <qgssymbol.h>
#include <qgssinglesymbolrenderer.h>
#include <QDebug>
#include <QMessageBox>
#include "map.h"
#include <QMainWindow>
#include <QWidget>

Map::Map(QWidget *parent): QMainWindow(parent)
{
    map=new QgsMapCanvas(this);
    map->setLayers({earthLayer, oceanLayer});
    map->setExtent(earthLayer->extent());
    QgsCoordinateReferenceSystem crs("EPSG:4326");
    map->setDestinationCrs(crs);
    map->refresh();
    this->setCentralWidget(map);

    this->setMinimumSize(800, 600);
    toolBar = new QToolBar(this);
}

QList<QgsVectorLayer *> LayerHandler::handleLayerBase(const QString &layerPath, const QString& layerName) const {
        QgsVectorLayer::LayerOptions options;
        options.loadDefaultStyle = false;

        QString onlyName = layerName.mid(layerName.lastIndexOf("/") + 1);
        if (onlyName == "points" ||
            onlyName == "controlPoints" ||
            onlyName == "controlLines" ||
            onlyName == "trajectories") {
                return {};
        }

        QgsVectorLayer* layer = new QgsVectorLayer(layerPath, layerName, "ogr", options);
        if ( !layer->isValid() )
            return {};
        QList<QgsVectorLayer*> layers;
        layers.push_back(layer);
        return layers;
    }

        QList<QgsVectorLayer *> ShpLayerHandler::handleLayer(const QString &layerPath) const {
        QString layerName = layerPath;
        layerName.remove(".shp");
        return LayerHandler::handleLayerBase(layerPath,layerName);
    }




void Map::addLayer() {
       QFileDialog dialog(this, QString("Добавить слой").toLocal8Bit());
       dialog.setOption(QFileDialog::DontUseNativeDialog);
       dialog.setNameFilter("*.shp *.000 *.sxf");

       if (dialog.exec() == QDialog::Accepted) {
           QString layerPath =dialog.selectedFiles()[0];
           if (!QFile::exists(layerPath))
               return;
           std::unique_ptr<LayerHandler> layerHandler;
           if (layerPath.contains(".shp"))
               layerHandler = std::make_unique<ShpLayerHandler>();

       }
}

Map::~Map()
{
   delete map;
   delete earthLayer;
   delete oceanLayer;
   delete toolBar;
}

