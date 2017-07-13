#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT
    int health;
public:
    Enemy();
    void attackedBy(QGraphicsItem *weapon);
public slots:
    void move();
};

#endif // ENEMY_H
