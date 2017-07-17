#include "myship.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

/*
 * Test to see if this shit works
 * @author : Yan Jun Zhang
 *
 * NOTES - rect is player
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // creates a new scene
    QGraphicsScene *scene = new QGraphicsScene();

    // creates a rectangle object to put into the scene
    MyShip *player = new MyShip();

    // add item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the scene to a new view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // modify sizes and positions
    view->setFixedSize(600, 800);
    scene->setSceneRect(0, 0, 600, 800);
    player->setPos(view->width() / 2, view->height());
    view->show();

    // spawns enemy and initialize the player interaction
    QTimer * spawnner = new QTimer();
    QTimer * checkHit = new QTimer();
    QObject::connect(spawnner, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    QObject::connect(checkHit, SIGNAL(timeout()), player, SLOT(checkHit()));
    spawnner->start(4000);
    checkHit->start(10);

    return a.exec();
}
