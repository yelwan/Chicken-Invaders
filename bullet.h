#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include "player.h"
class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(Player *player);

public slots:
    void move();
private:
    Player *player;

};

#endif // BULLET_H
