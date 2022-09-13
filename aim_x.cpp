#include "aim_x.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>

aim_x::aim_x(QGraphicsScene*x)
{
    scene=x;
    aimx=scene->addRect(-301,-260,3,520);
    aimx->setPen(Qt::NoPen);
    aimx->setFlag(QGraphicsItem::ItemIsSelectable);
    aimx->setBrush(QBrush(Qt::green));
}
