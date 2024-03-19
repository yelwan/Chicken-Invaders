#include "over.h"
#include "ui_over.h"
#include "player.h"
over::over(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::over)
{
    ui->setupUi(this);
}

over::~over()
{
    delete ui;
}

void over::on_restartpush_clicked()
{

    hide();
    Player *player= new Player;
    player->
}

