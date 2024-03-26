#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsTextItem>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    QGraphicsTextItem *healthText= new QGraphicsTextItem();
    QGraphicsTextItem *scoreText = new QGraphicsTextItem();
public:
    int score;
    int health;
    Player();
    ~Player();
    void initializeText(QGraphicsTextItem* textItem, const QString& text, const QColor& color, int x, int y,int T);

    void decrease();

    void updateText();
public:
    void keyPressEvent(QKeyEvent * event);

public slots:
    void createEnemy();
    void increase();
};

#endif // PLAYER_H
