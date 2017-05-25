#include "player.h"

Player::Player()
{
    this->setPixmap(QPixmap(":/images/player.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);

    playerSpeed = new QTimer();
    connect(playerSpeed,SIGNAL(timeout()),this,SLOT(playerMove()));
    playerSpeed->setInterval(20);
}

QRectF Player::boundingRect()
{
    return QRectF(0,0,100,100);
}

void Player::keyPressEvent(QKeyEvent * event)
{
    switch (event->key())
    {
        case Qt::Key_Left :
        {
            isPressedLeft = true;
            playerSpeed->start();
            break;
        }

        case Qt::Key_Right :
        {
            isPressedLeft = false;
            playerSpeed->start();
            break;
        }

        case Qt::Key_Space :
        {
            emit fire();
        }
    }
}

void Player::keyReleaseEvent(QKeyEvent * event)
{
    playerSpeed->stop();
}

void Player::playerMove()
{
    if(isPressedLeft)
    {
        if(this->x() >= 0)
        {
            this->moveBy(-10,0);
        }

    }
    else
    {
        if(this->x()+100 <= 1000)
        {
            this->moveBy(+10,0);
        }

    }
}
