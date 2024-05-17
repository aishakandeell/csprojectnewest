#ifndef ABILITIESSHOP_H
#define ABILITIESSHOP_H

#include <QDialog>

namespace Ui {
class abilitiesShop;
}

class abilitiesShop : public QDialog
{
    Q_OBJECT

public:
    explicit abilitiesShop(QWidget *parent = nullptr);
    ~abilitiesShop();

private slots:
    void on_nextLev_clicked();

    void on_buy3x_clicked();

    void on_buyhealth_clicked();

private:
    Ui::abilitiesShop *ui;
};

#endif // ABILITIESSHOP_H
