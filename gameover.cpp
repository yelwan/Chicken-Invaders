#include "gameover.h"
#include "ui_gameover.h"
#include "player.h"
#include "enemy.h"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include "QGraphicsView"
#include "bullet.h"
gameover::gameover(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gameover)
{
    ui->setupUi(this);
}

gameover::~gameover()
{
    delete ui;
}


