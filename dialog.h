#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include <player.h>
#include <enemy.h>
#include <bullet.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    Bullet* bullet;

    QGraphicsScene* scene;
    Player* player;
    Enemy *enemy;

public slots:
    void playerShoot();
    void spawnEnemy();
private:
    Ui::Dialog *ui;
    QTimer *spawnEnemyTime;
};

#endif // DIALOG_H
