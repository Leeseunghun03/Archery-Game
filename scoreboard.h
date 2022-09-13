#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <QGraphicsScene>
#include <QMainWindow>


class scoreboard
{
public:
    scoreboard(QGraphicsScene*c);
     QGraphicsScene*scene;
     QGraphicsEllipseItem*pan;
     QGraphicsTextItem*score;
     int num[10];
};

#endif // SCOREBOARD_H
