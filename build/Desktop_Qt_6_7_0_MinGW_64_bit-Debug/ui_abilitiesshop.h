/********************************************************************************
** Form generated from reading UI file 'abilitiesshop.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABILITIESSHOP_H
#define UI_ABILITIESSHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_abilitiesShop
{
public:
    QLabel *scorepoints;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Back;
    QLabel *label;
    QPushButton *nextLev;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *buy3x;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *buyfreeze;

    void setupUi(QDialog *abilitiesShop)
    {
        if (abilitiesShop->objectName().isEmpty())
            abilitiesShop->setObjectName("abilitiesShop");
        abilitiesShop->resize(350, 278);
        abilitiesShop->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 47, 48);"));
        scorepoints = new QLabel(abilitiesShop);
        scorepoints->setObjectName("scorepoints");
        scorepoints->setGeometry(QRect(100, 40, 111, 20));
        widget = new QWidget(abilitiesShop);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 331, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Back = new QPushButton(widget);
        Back->setObjectName("Back");

        horizontalLayout->addWidget(Back);

        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        nextLev = new QPushButton(widget);
        nextLev->setObjectName("nextLev");

        horizontalLayout->addWidget(nextLev);

        widget1 = new QWidget(abilitiesShop);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 70, 321, 98));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        buy3x = new QPushButton(widget1);
        buy3x->setObjectName("buy3x");

        horizontalLayout_2->addWidget(buy3x);

        widget2 = new QWidget(abilitiesShop);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(10, 170, 321, 98));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        label_5 = new QLabel(widget2);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        buyfreeze = new QPushButton(widget2);
        buyfreeze->setObjectName("buyfreeze");

        horizontalLayout_3->addWidget(buyfreeze);


        retranslateUi(abilitiesShop);

        QMetaObject::connectSlotsByName(abilitiesShop);
    } // setupUi

    void retranslateUi(QDialog *abilitiesShop)
    {
        abilitiesShop->setWindowTitle(QCoreApplication::translate("abilitiesShop", "Dialog", nullptr));
        scorepoints->setText(QCoreApplication::translate("abilitiesShop", "<html><head/><body><p><span style=\" font-weight:700;\">Score Points:</span></p></body></html>", nullptr));
        Back->setText(QCoreApplication::translate("abilitiesShop", "Back", nullptr));
        label->setText(QCoreApplication::translate("abilitiesShop", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Ability Shop</span></p></body></html>", nullptr));
        nextLev->setText(QCoreApplication::translate("abilitiesShop", "Next Level", nullptr));
        label_2->setText(QCoreApplication::translate("abilitiesShop", "<html><head/><body><p><img src=\"file:///C:/Users/Karim/AppData/Local/Packages/Microsoft.Windows.Photos_8wekyb3d8bbwe/TempState/ShareServiceTempFolder/Ball.jpeg\"/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("abilitiesShop", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">x3 Balls</span></p></body></html>", nullptr));
        buy3x->setText(QCoreApplication::translate("abilitiesShop", "5 Score Points", nullptr));
        label_4->setText(QCoreApplication::translate("abilitiesShop", "<html><head/><body><p><img src=\"file:///C:/Users/Karim/AppData/Local/Packages/Microsoft.Windows.Photos_8wekyb3d8bbwe/TempState/ShareServiceTempFolder/Freeze.jpeg\"/></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("abilitiesShop", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">Slow Time</span></p></body></html>", nullptr));
        buyfreeze->setText(QCoreApplication::translate("abilitiesShop", "3 Score Points", nullptr));
    } // retranslateUi

};

namespace Ui {
    class abilitiesShop: public Ui_abilitiesShop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABILITIESSHOP_H
