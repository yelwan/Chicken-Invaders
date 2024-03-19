#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include "Player.h"
#include <QMediaPlayer>
#include <QUrl>
Enemy::Enemy() {
        // *******  Setting the size of the enemy ********
    QPixmap pix("/Users/daliakadry/Downloads/chicken.png");
    setPixmap(pix.scaled(pix.height(),pix.width()));

        // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

        // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}

// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy::move() {
    setPos(x(), y() + 5);

    if (y() + pixmap().height() > 800) {
        scene()->removeItem(this);
        delete this;

    }
        QList<QGraphicsItem*> colliding_items = collidingItems();
        for (int i = 0; i < colliding_items.size(); i++) {
            if (typeid(*(colliding_items[i])) == typeid(Player)) {
                Player *player = dynamic_cast<Player*>(colliding_items[i]);
                if (player) {
                    player->decrease();
                }
                scene()->removeItem(this);
                delete this;
                QMediaPlayer* destroySound = new QMediaPlayer();
                destroySound->setMedia(QUrl::fromLocalFile("/Users/daliakadry/Downloads/laser.png"));
                destroySound->setVolume(50); // Adjust volume if necessary
                destroySound->play();
                return;
            }
        }
    }



