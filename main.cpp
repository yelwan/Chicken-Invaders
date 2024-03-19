#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "gameover.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create the view and set its properties
    QGraphicsView view;
    view.setFixedSize(800, 600);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create the scene and set its properties
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);

    // Create the player and set its initial position
    Player *player = new Player();
    player->setPos(view.width() / 2, view.height() - player->pixmap().height());

    // Set player's focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Create GameManager and GameOverWindow instances

    // Connect GameManager's gameOver signal to GameOverWindow's open slot
    // Connect GameManager's checkGameOver slot to Player's decrease method

    // Create timer for spawning enemies
    QTimer enemyTimer;
    QObject::connect(&enemyTimer, &QTimer::timeout, player, &Player::createEnemy);
    enemyTimer.start(2000); // Spawn an enemy every 2000 ms

    // Add player to the scene
    scene.addItem(player);

    // Set the scene to the view and show the view
    view.setScene(&scene);
    view.show();

    // Execute the game
    return a.exec();
}
