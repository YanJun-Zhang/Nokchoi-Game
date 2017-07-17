#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet() {
    setRect(0, -12, 10, 10);

    // connect
    QTimer *timer = new QTimer();
    // SLOT is method that is called on SIGNAL
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); // every 50 ms, timeout() is called
}

void Bullet::move() {
    // check interaction
    QList<QGraphicsItem *> hitList = this->collidingItems();
    int size = hitList.size(); // should only be at most 1 object being hit
    for (int i = 0; i < size; i++) {
        if (typeid(*(hitList[i])) == typeid(Enemy)) {
            (static_cast<Enemy *>(hitList[0]))->attackedBy(this);
            delete this; // bullet is gone
            return;
        }
    }

    // move bullet up
    setPos(x(), y() - 15);
    // delete bullet when offscreen
    if (pos().y() + rect().height() / 2 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
