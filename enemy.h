#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include "player.h"
class Enemy: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT
public:
    Enemy();

public slots:
    void move();
private:

};

#endif // ENEMY_H
