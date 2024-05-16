#include "maimmenu.h"
#include "ui_maimmenu.h"
#include "game.h"
#include "levels.h"
levels*Levels;
game *Game;
maimmenu::maimmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::maimmenu)
{
    ui->setupUi(this);
}

maimmenu::~maimmenu()
{
    delete ui;
}

void maimmenu::on_startButton_clicked()
{
    this->~maimmenu();
    Game=new game();
    Levels = new levels();
    Game->nextlevel(); // Open a new level
}


void maimmenu::on_exitbutton_clicked()
{
    this->~maimmenu();
}
