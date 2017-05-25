#include "bullet.h"

Bullet::Bullet()
{
    this->setPixmap(QPixmap(":/images/bullet.png"));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(bulletMove()));
    timer->start(20);
}

QRectF Bullet::boundingRect()
{
    return QRectF(0,0,20,20);
}

void Bullet::bulletMove()
{
    this->moveBy(0,-10);
    if(this->y()<-20)
    {
        delete this;
        return;
    }

    if(!this->collidingItems().isEmpty())
    {
        delete collidingItems()[0];
        delete this;
        return;
    }
}
