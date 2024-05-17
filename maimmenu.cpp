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


void maimmenu::on_level1button_clicked()
{
    this->~maimmenu();
    Game=new game();
    Levels = new levels();
    Game->level1();
}


void maimmenu::on_level2button_clicked()
{
    this->~maimmenu();
    Game=new game();
    Levels = new levels();
    Game->level2();
}


void maimmenu::on_level3button_clicked()
{
    this->~maimmenu();
    Game=new game();
    Levels = new levels();
    Game->level3();
}


void maimmenu::on_level4button_clicked()
{
    this->~maimmenu();
    Game=new game();
    Levels = new levels();
    Game->level4();
}


void maimmenu::on_level3button_2_clicked()
{
    this->~maimmenu();
    Game=new game();
    Levels = new levels();
    Game->level5();
}


void maimmenu::on_level5button_clicked()
{
    this->~maimmenu();
    Game=new game();
    Levels = new levels();
    Game->level5();
}

