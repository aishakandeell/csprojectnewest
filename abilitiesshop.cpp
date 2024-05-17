#include "abilitiesshop.h"
#include "qmessagebox.h"
#include "ui_abilitiesshop.h"
#include "game.h"
#include "abilities.h"

extern game* Game;
extern int scorec;
extern bool own3x;
extern bool ownslow;

abilitiesShop::abilitiesShop(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::abilitiesShop)
{
    ui->setupUi(this);
    ui->scorepoints->setText("Score Points: " + QString::number(scorec));
}

abilitiesShop::~abilitiesShop()
{
    delete ui;
}

void abilitiesShop::on_nextLev_clicked()
{
    delete this;
    Game->nextlevel();
}


void abilitiesShop::on_buy3x_clicked()
{
    if(scorec >= 5){
        own3x = true;
        QMessageBox msgbox;
        QString messagee="3x Ball Ability Purchased";
        msgbox.setWindowTitle("Purchased Ability");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);//level1 function
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
    else{
        QMessageBox msgbox;
        QString messagee="Not Enough Score Points";
        msgbox.setWindowTitle("Unable to Purchase");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);//level1 function
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
}


void abilitiesShop::on_buyfreeze_clicked()
{
    if(scorec >= 3){
        ownslow = true;
        QMessageBox msgbox;
        QString messagee="Slow Time Ability Purchased";
        msgbox.setWindowTitle("Purchased Ability");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);//level1 function
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
    else{
        QMessageBox msgbox;
        QString messagee="Not Enough Score Points";
        msgbox.setWindowTitle("Unable to Purchase");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);//level1 function
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
}

