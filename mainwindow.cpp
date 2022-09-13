#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scoreboard.h"
#include "scoreboard.cpp"
#include "aim_x.h"
#include "aim_x.cpp"
#include "aim_y.h"
#include "aim_y.cpp"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QDebug>
#include <QTimer>
#include <iostream>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    xtimer1=new QTimer;
    xtimer1->start();
    xtimer1->setInterval(1);

    xtimer2=new QTimer;
    xtimer2->start();
    xtimer2->setInterval(0);

    ytimer1=new QTimer;
    ytimer1->start();
    ytimer1->setInterval(1);

    ytimer2=new QTimer;
    ytimer2->start();
    ytimer2->setInterval(0);

    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    ground=new scoreboard(scene);
    QGraphicsView*view=new QGraphicsView(this);
    view->setScene(scene);
    ui->verticalLayout->addWidget(view);
    ui->label_8->setNum(0);
    ui->label_9->setNum(1);
    ui->label_12->setNum(best_score);
    save();
}


void MainWindow::whowin(int p1, int p2)
{
    r=scene->addRect(-250,-100,500,200);
    r->setPen(QPen(Qt::black));
    r->setFlag(QGraphicsItem::ItemIsSelectable);
    r->setBrush(QBrush(Qt::white));
    QGraphicsTextItem*text=new QGraphicsTextItem(r);
    text->setPos(-100,-10);
    text->setFont(QFont("Courier", 16));
    if(p1>p2)
        text->setPlainText("Player 1 is Win!\n Press  <Start>");
    else if(p2>p1)
        text->setPlainText("Player 2 is Win!\n Press  <Start>");
    else
        text->setPlainText("Ended in a draw!\n Press  <Start>");


}

void MainWindow::on_pushButton_clicked() //Start
{
    if(gameset==1)
    {
        ui->label_2->setNum(0);
        ground=new scoreboard(scene);
        delete r;
        gameset=0;
    }
    if(startable==0)
    {
    if(ui->radioButton->isChecked())
    {
    linex=new aim_x(scene);
    connect(xtimer1,SIGNAL(timeout()),this,SLOT(xmove()));
    level=0;
    startable=1;
    stopable=1;
    }
    else if(ui->radioButton_2->isChecked())
    {
    linex=new aim_x(scene);
    connect(xtimer2,SIGNAL(timeout()),this,SLOT(xmove()));
    level=1;
    startable=1;
    stopable=1;
    }
    }
}

void MainWindow::xmove()
{

    if(level==0||level==1)
    {
    if(x==250)
    {
        xmode=1;
    }

    else if(x==-300)
    {
        xmode=0;
    }

    if(xmode==0)
    {
    QGraphicsItem*item=linex->aimx;
    if(item){
        QTransform transform = item->transform();
        transform.translate(1,0);
        item->setTransform(transform);
        x+=1;
    }
    }

    else if(xmode==1)
    {
        QGraphicsItem*item=linex->aimx;
        if(item){
            QTransform transform = item->transform();
            transform.translate(-1,0);
            item->setTransform(transform);
            x-=1;
        }
    }
    }
}

void MainWindow::ymove()
{
    if(y==260)
    {
        ymode=1;
    }

    else if(y==-260)
    {
        ymode=0;
    }

    if(ymode==0)
    {
    QGraphicsItem*item=liney->aimy;
    if(item){
        QTransform transform = item->transform();
        transform.translate(0,1);
        item->setTransform(transform);
        y+=1;
    }
    }

    else if(ymode==1)
    {
        QGraphicsItem*item=liney->aimy;
        if(item){
            QTransform transform = item->transform();
            transform.translate(0,-1);
            item->setTransform(transform);
            y-=1;
        }
    }
}

void MainWindow::scar(int x, int y)
{

    if(player==0)
    {
        s=scene->addEllipse(x-5,y-5,10,10);
        s->setPen(QPen(Qt::black));
        s->setFlag(QGraphicsItem::ItemIsSelectable);
        s->setBrush(QBrush(Qt::cyan));
        ui->label_9->setNum(1);
    }

    else if(player==1)
    {
        s=scene->addEllipse(x-5,y-5,10,10);
        s->setPen(QPen(Qt::black));
        s->setFlag(QGraphicsItem::ItemIsSelectable);
        s->setBrush(QBrush(Qt::magenta));
        ui->label_9->setNum(2);
    }

    exscore=sqrt((x*x)+(y*y));
    if(exscore<=25)
    {
    score+=10;
    onescore=10;
    }
    else if(exscore<=50)
    {
    score+=9;
    onescore=9;
    }
    else if(exscore<=75)
    {
    score+=8;
    onescore=8;
    }
    else if(exscore<=100)
    {
    score+=7;
    onescore=7;
    }
    else if(exscore<=125)
    {
    score+=6;
    onescore=6;
    }
    else if(exscore<=150)
    {
    score+=5;
    onescore=5;
    }
    else if(exscore<=175)
    {
    score+=4;
    onescore=4;
    }
    else if(exscore<=200)
    {
    score+=3;
    onescore=3;
    }
    else if(exscore<=225)
    {
    score+=2;
    onescore=2;
    }
    else if(exscore<=250)
    {
    score+=1;
    onescore=1;
    }
    else if(exscore)
    {
    score+=0;
    onescore=0;
    }

    exscore=0;

    if(player==0)
    {
        ui->label_5->setNum(score);
        ui->label_2->setNum(onescore);
    }

    else if(player==1)
    {
        ui->label_6->setNum(score);
        ui->label_2->setNum(onescore);
    }

    turn++;
    ui->label_8->setNum(turn);
    onescore=0;
    startable=0;

    if(turn==10)
    {
        if(playermode==0)
        {

            p1sum=score;
            playermode=1;
            player=1;
            ui->label_8->setNum(0);
            ui->label_9->setNum(2);

        }
        else if(playermode==1)
        {
            p2sum=score;
            playermode=0;
            gameset=1;
            player=0;
            ui->label_9->setNum(1);
            whowin(p1sum,p2sum);
            ui->label_8->setNum(0);
            save();
        }

        turn=0;
        score=0;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() //Stop
{
    if(stopable==1||stopable==2)
    {
    if(xtoy==0)
    {
    disconnect(xtimer1,SIGNAL(timeout()),this,SLOT(xmove()));
    disconnect(xtimer2,SIGNAL(timeout()),this,SLOT(xmove()));
    x_rotation=x;
    qDebug()<<x_rotation;
    liney=new aim_y(scene);
    if(level==0)
    connect(ytimer1,SIGNAL(timeout()),this,SLOT(ymove()));
    else if(level==1)
    connect(ytimer2,SIGNAL(timeout()),this,SLOT(ymove()));
    xtoy=1;
    x=-300;
    }
    else if(xtoy==1)
    {
        disconnect(ytimer1,SIGNAL(timeout()),this,SLOT(ymove()));
        disconnect(ytimer2,SIGNAL(timeout()),this,SLOT(ymove()));
        y_rotation=y;
        qDebug()<<y_rotation;
        xtoy=0;
        y=-260;
        delete linex->aimx;
        delete liney->aimy;
        scar(x_rotation, y_rotation);
    }
    if(stopable==1)
        stopable=2;
    else if(stopable==2)
        stopable=0;
    }

}

void MainWindow::save()
{
    using namespace std;

    load();

    if(p1sum>=p2sum)
    {
        exsum=p1sum;
    }
    else if(p1sum<p2sum)
    {
        exsum=p2sum;
    }

    if(exsum>=best_score)
        best_score=exsum;

    ofstream fout("C:\\output.txt");
    fout<<best_score;
    fout.close();

    ui->label_12->setNum(best_score);
}

void MainWindow::load()
{
    qDebug()<<"end";
    using namespace std;
    ifstream fin;
    fin.open("C://output.txt");
    fin>>best_score;
    fin.close();
    qDebug()<<"end";
}



