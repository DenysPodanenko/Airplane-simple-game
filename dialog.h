#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <player.h>
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

public slots:
    void playerShoot();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
