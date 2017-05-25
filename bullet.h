#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <enemy.h>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet();
    QTimer* timer;
    QRectF boundingRect();

public slots:
    void bulletMove();
};

#endif // BULLET_H
