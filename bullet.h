#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsEllipseItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};


#endif // BULLET_H
