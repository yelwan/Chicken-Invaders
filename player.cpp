#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QMessageBox>
#include "GameOver.h"
#include "QGraphicsView"
Player::Player() {
    health = 3;
    score = 0;
    healthText = new QGraphicsTextItem("Health: " + QString::number(health));
    scoreText = new QGraphicsTextItem("Score: " + QString::number(score));
    QPixmap pix("/Users/daliakadry/Downloads/ship.png");
    setPixmap(pix.scaled(pix.height(), pix.width()));
}

Player::~Player() {
    delete healthText;
    delete scoreText;
}

void Player::updateText() {
    healthText->setPlainText("Health: " + QString::number(health));
    scoreText->setPlainText("Score: " + QString::number(score));
}

void Player::initializeText(QGraphicsTextItem* textItem, const QString& text, const QColor& color, int x, int y, int T) {
    textItem->setPlainText(text + QString::number(T));
    textItem->setDefaultTextColor(color);
    textItem->setPos(x, y);
    scene()->addItem(textItem);
}

void Player::keyPressEvent(QKeyEvent *event) {
    initializeText(healthText, "Health: ", Qt::red, 10, 10, health);
    initializeText(scoreText, "Score: ", Qt::blue, 60, 80, score);
    if (event->key() == Qt::Key_Left) {
        if (x() > 0) // to prevent the player from getting out of the screen
            setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_Right) {
        if (x() + 100 < 800) // to prevent the player from getting out of the screen
            setPos(x() + 10, y());
    } else if (event->key() == Qt::Key_Space) {
        if (scene()) { // Ensure scene is valid
            Bullet *bullet = new Bullet(this); // Pass Player object to Bullet constructor
            bullet->setPos(x() + 30, y());
            scene()->addItem(bullet);
        }
    }

    updateText();
}

void Player::createEnemy() {
    if (scene()) { // Ensure scene is valid
        Enemy* enemy = new Enemy();
        scene()->addItem(enemy);
    }
}

void Player::decrease() {
    health--;
    healthText->setPlainText("Health: " + QString::number(health));
    if (health < 1) {
        this->hide();
        gameover *g= new gameover;
        g->show();
        return;
    }
}

void Player::increase() {
    score++;
    scoreText->setPlainText("Score: " + QString::number(score));
}

