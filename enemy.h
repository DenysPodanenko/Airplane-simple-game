#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemy : QGraphicsPixmapItem
{
public:
    Enemy();

    QTimer* timer;
    QRectF boundingRect();

public slots:
    void enemyMove();
};

#endif // ENEMY_H
