#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <QMediaPlayer>
#include <QUrl>
Bullet::Bullet(Player *player) :QObject(), QGraphicsPixmapItem()   {
    // Constructor implementation
    // Set the pixmap for the bullet
    QPixmap pix("/Users/daliakadry/Downloads/laser.png");
    setPixmap(pix.scaled(pix.height(), pix.width()));
    this->player=player;
    // Start a timer to move the bullet
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50); // Adjust the interval as needed
}

// Move function is used to 1-  move the bullet upwards
// 2- Handle the collision of the bullets with enemies
void Bullet::move() {
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            player->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            QMediaPlayer* bulletSound = new QMediaPlayer();
            bulletSound->setMedia(QUrl::fromLocalFile("/Users/daliakadry/Downloads/laser.png"));
            bulletSound->setVolume(50); // Adjust volume if necessary
            bulletSound->play();
            return;
        }
    }

    setPos(x(), y() - 10);

    if (pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
