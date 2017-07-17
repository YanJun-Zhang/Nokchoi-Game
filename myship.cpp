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
    health = 50;
    poly.append(QPoint(-50, 0));
    poly.append(QPoint(50, 0));
    poly.append(QPoint(0, -100));
    this->setPolygon(poly);
}

QPainterPath MyShip::shape() const {
    QPainterPath path;
    // addPolygon is expensive if shape is complicated
    path.addPolygon(poly);
    return path;
}

QRectF MyShip::boundingRect() const {
    return QRectF(-50, -100, 100, 100);
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
    /*
    cout << x() << ", " << y() << endl;
    QRectF r = this->boundingRect();
    cout << r.x() << ", " << r.y() << ", " << r.width() << ", " << r.height() << endl;*/
}

void MyShip::spawnEnemy() {
    Enemy *e = new Enemy();
    int x = rand() % (int)(scene()->width() - e->rect().width());
    e->setPos(x, 0);
    scene()->addItem(e);
}

void MyShip::checkHit() {
    // check interaction
    QList<QGraphicsItem *> hitList = scene()->collidingItems(this);
    int size = hitList.size(); // should only be at most 1 object being hit
    for (int i = 0; i < size; i++) {
        if (typeid(*(hitList[i])) == typeid(Enemy)) {
            health -= 10;
            delete hitList[i];
        }
    }
    if (health <= 0) {
        delete this;
    }
}
