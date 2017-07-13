#include "myship.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPoint>
#include <iostream>

using namespace std;

MyShip::MyShip() {
    width = 100;
    height = 100;
    poly.append(QPoint(-50, 0));
    poly.append(QPoint(50, 0));
    poly.append(QPoint(0, -100));
    this->setPolygon(poly);
}

// Going to use mouse in the future
void MyShip::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    } else if (event->key() == Qt::Key_Up) {
        setPos(x(), y() - 10);
    } else if (event->key() == Qt::Key_Down) {
        setPos(x(), y() + 10);
    } else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x() - bullet->rect().width() / 2, y() - height);
        scene()->addItem(bullet);
    }
}

void MyShip::spawnEnemy() {
    Enemy *e = new Enemy();
    int x = rand() % (int)(scene()->width() - e->rect().width());
    e->setPos(x, 0);
    scene()->addItem(e);
}
