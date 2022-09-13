#include "scoreboard.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <iostream>
#include <fstream>
#include <QGraphicsTextItem>

scoreboard::scoreboard(QGraphicsScene*c)
{
    scene=c;
    pan=scene->addEllipse(-250,-250,500,500);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::white));
    pan=scene->addEllipse(-225,-225,450,450);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::white));
    pan=scene->addEllipse(-200,-200,400,400);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::black));
    pan=scene->addEllipse(-175,-175,350,350);
    pan->setPen(QPen(Qt::white));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::black));
    pan=scene->addEllipse(-150,-150,300,300);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::blue));
    pan=scene->addEllipse(-125,-125,250,250);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::blue));
    pan=scene->addEllipse(-100,-100,200,200);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::red));
    pan=scene->addEllipse(-75,-75,150,150);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::red));
    pan=scene->addEllipse(-50,-50,100,100);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::yellow));
    pan=scene->addEllipse(-25,-25,50,50);
    pan->setPen(QPen(Qt::black));
    pan->setFlag(QGraphicsItem::ItemIsSelectable);
    pan->setBrush(QBrush(Qt::yellow));


}
