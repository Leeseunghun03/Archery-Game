#include "aim_y.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

aim_y::aim_y(QGraphicsScene*y)
{
    scene=y;
    aimy=scene->addRect(-290,-262,580,5);
    aimy->setPen(Qt::NoPen);
    aimy->setFlag(QGraphicsItem::ItemIsSelectable);
    aimy->setBrush(QBrush(Qt::green));
}
