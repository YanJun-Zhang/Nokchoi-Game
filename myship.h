#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QPolygonF>

class MyShip : public QObject, public QGraphicsPolygonItem {
    Q_OBJECT
    QPolygonF poly;
public:
    int width, height;
    MyShip();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawnEnemy();
};

#endif // MYRECT_H
