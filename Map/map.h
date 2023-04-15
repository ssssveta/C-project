#ifndef MAP_H
#define MAP_H

#include <QBoxLayout>
#include <QStatusBar>
#include <QWidget>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsmaptoolpan.h>
#include <qgsmaptoolidentifyfeature.h>
#include <memory>
#include <QMainWindow>
#include <QToolBar>
#include <qgsmaptoolemitpoint.h>


class Map : public  QMainWindow{
   Q_OBJECT

public:
   Map(QWidget *parent = nullptr);
   ~Map();
   void addLayer();

private:
  QgsMapCanvas* map=nullptr;
  QgsVectorLayer * earthLayer= new QgsVectorLayer("/root/project/maps/kx-world-land-areas-110-million-SHP/world-land-areas-110-million.shp", "earth", "ogr");
  QgsVectorLayer* oceanLayer = new QgsVectorLayer("/root/project/maps/kx-world-bathymetry-110-million-SHP/world-bathymetry-110-million.shp", "water", "ogr");
  QToolBar* toolBar;
};

class LayerHandler {
public:
       LayerHandler() = default;
       virtual ~LayerHandler() = default;
       virtual QList<QgsVectorLayer *> handleLayer(const QString& layerPath) const = 0;

protected:
       QList<QgsVectorLayer *> handleLayerBase(const QString &layerPath, const QString& layerName) const;
};


class ShpLayerHandler final: public LayerHandler {
       public:
       QList<QgsVectorLayer *> handleLayer(const QString& layerPath)  const override;
};

#endif // MAP_H
