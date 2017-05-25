#include "enemy.h"

Enemy::Enemy()
{
    this->setPixmap(QPixmap(":/images/enemy.png"));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(enemyMove()));
    timer->start(100);
}

void Enemy::enemyMove()
{
    this->moveBy(0,+10);
    if(this->y()>820)
    {
        delete this;
    }
}

QRectF Enemy::boundingRect()
{
    return QRectF(0,0,100,100);
}
