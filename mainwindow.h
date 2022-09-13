#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "scoreboard.h"
#include <QKeyEvent>
#include "aim_x.h"
#include "aim_y.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene*scene;
    QGraphicsEllipseItem*s;
    QGraphicsRectItem*r;
    int x=-300;
    int y=-260;
    scoreboard*ground;
    aim_x*linex;
    aim_y*liney;
    QTimer*xtimer1;
    QTimer*xtimer2;
    QTimer*ytimer1;
    QTimer*ytimer2;

private slots:
    void on_pushButton_clicked();
    void xmove();
    void ymove();
    void on_pushButton_2_clicked();
    void scar(int x, int y);
    void whowin(int p1, int p2);
    void save();
    void load();

private:
    Ui::MainWindow *ui;
    int xmode=0;
    int ymode=0;
    int x_rotation=0;
    int y_rotation=0;
    int level=-1;
    int xtoy=0;
    int score=0;
    int startable=0;
    int stopable=0;
    int player=0;
    int turn=0;
    int onescore=0;
    int p1sum=0;
    int p2sum=0;
    int playermode=0;
    double exscore=0;
    int gameset=0;
    int exsum=0;
    int best_score=0;
};
#endif // MAINWINDOW_H


