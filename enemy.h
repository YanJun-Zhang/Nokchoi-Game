#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT
    int health;
    bool left;
public:
    Enemy();
    void attackedBy(QGraphicsItem *weapon);
public slots:
    void moveDown();
    void moveSide();
};

#endif // ENEMY_H
