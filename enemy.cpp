#include "enemy.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy() {
    setRect(0, 0, 50, 50);
    health = 2;
    left = true;

    // connect
    QTimer *moveDownTimer = new QTimer();
    QTimer *moveSideTimer = new QTimer();

    // SLOT is method that is called on SIGNAL
    connect(moveDownTimer, SIGNAL(timeout()), this, SLOT(moveDown()));
    connect(moveSideTimer, SIGNAL(timeout()), this, SLOT(moveSide()));

    moveDownTimer->start(200);
    moveSideTimer->start(10);
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

void Enemy::moveDown() {
    // move enemy down
    setPos(x(), y() + 10);

    // delete enemy when offscreen
    if (pos().y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::moveSide() {
    if (left) {
        setPos(x() - 2, y());
    } else {
        setPos(x() + 2, y());
    }

    if (x() + 50 > scene()->width() || x() < 0) {
        left = !left;
    }
}
