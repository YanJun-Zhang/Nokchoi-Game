#include "enemy.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy() {
    setRect(0, 0, 50, 50);
    health = 2;

    // connect
    QTimer *timer = new QTimer();
    // SLOT is method that is called on SIGNAL
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(200); // every 50 ms, timeout() is called
}

void Enemy::attackedBy(QGraphicsItem *weapon) {
    if (typeid(*weapon) == typeid(Bullet)) {
        health--;
    }

    // defeated
    if (health == 0) {
        delete this;
    }
}

void Enemy::move() {
    // move enemy down
    setPos(x(), y() + 10);

    // delete enemy when offscreen
    if (pos().y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}
