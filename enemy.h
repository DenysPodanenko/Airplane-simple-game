#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <bullet.h>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy();

    QTimer* timer;
    QRectF boundingRect();

public slots:
    void enemyMove();
};

#endif // ENEMY_H
