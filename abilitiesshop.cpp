#include "abilitiesshop.h"
#include "qmessagebox.h"
#include "ui_abilitiesshop.h"
#include "game.h"
#include "abilities.h"
#include "levels.h"
#include <QDebug>
extern levels* Levels;
extern game* Game;
extern int scorec;
extern bool owns3x;
extern bool ownshealth;

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

    Game->nextlevel();
    delete this;

}
void abilitiesShop::on_buy3x_clicked()
{
    if(scorec >= 5){
        owns3x = true;
        scorec=scorec-5;
        QMessageBox msgbox;
        QString messagee="3x Ball Ability Purchased";
        msgbox.setWindowTitle("Purchased Ability");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
    else{
        QMessageBox msgbox;
        QString messagee="Not Enough Score Points";
        msgbox.setWindowTitle("Unable to Purchase");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        //connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);//level1 function
        connect(nextlevelbutton, &QPushButton::clicked, [&msgbox, this]() {
            //this->hide();
            game::nextlevel();
            delete this;
        });
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
}

void abilitiesShop::on_buyhealth_clicked()
{
    if(scorec >= 3){

        ownshealth = true;
        scorec=scorec-3;
        qDebug()<<"ownshealth"<<ownshealth;
        QMessageBox msgbox;
        QString messagee="Health Purchased";
        msgbox.setWindowTitle("Purchased Ability");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        //connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);//level1 function
        connect(nextlevelbutton, &QPushButton::clicked, [&msgbox, this]() {
            //this->hide();
            game::nextlevel();
            delete this;
        });
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
    else{
        QMessageBox msgbox;
        QString messagee="Not Enough Score Points";
        msgbox.setWindowTitle("Unable to Purchase");
        msgbox.setText(messagee);

        QPushButton *nextlevelbutton = new QPushButton("Go To Next Level");
        //connect(nextlevelbutton, &QPushButton::clicked, this, game::nextlevel);//level1 function
        connect(nextlevelbutton, &QPushButton::clicked, [&msgbox, this]() {
            //this->hide();
            game::nextlevel();
            delete this;
        });
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        msgbox.exec();
    }
}

