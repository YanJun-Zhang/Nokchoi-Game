#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QPolygonF>

class MyShip : public QObject, public QGraphicsPolygonItem {
    Q_OBJECT
    QPolygonF poly;
    int health;
private:
    QPainterPath shape() const override;
    QRectF boundingRect() const override;
public:
    int width, height;
    MyShip();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawnEnemy();
    void checkHit();
};

#endif // MYRECT_H
