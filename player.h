#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player();

    QTimer* playerSpeed;
    bool isPressedLeft;

    QRectF boundingRect();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

public slots:
    void playerMove();

signals:
    void fire();
};

#endif // PLAYER_H
