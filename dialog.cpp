#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,720);
    ui->graphicsView->setScene(scene);

    player = new Player();
    player->setPos(scene->width()/2-50,scene->height()-100);
    scene->addItem(player);
    player->setFocus();

    spawnEnemyTime = new QTimer();
    connect(spawnEnemyTime,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnEnemyTime->start(1000);

    connect(player,SIGNAL(fire()),this,SLOT(playerShoot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::playerShoot()
{
    bullet = new Bullet();
    bullet->setPos(player->x()+32,player->y()-1);
    scene->addItem(bullet);
}

void Dialog::spawnEnemy()
{
    enemy = new Enemy();

    int a = qrand()%900;
    enemy->setPos(a,-100);
    scene->addItem(enemy);
}
