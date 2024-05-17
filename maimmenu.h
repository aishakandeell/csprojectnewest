#ifndef MAIMMENU_H
#define MAIMMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class maimmenu;
}
QT_END_NAMESPACE

class maimmenu : public QMainWindow
{
    Q_OBJECT

public:
    maimmenu(QWidget *parent = nullptr);
    ~maimmenu();

private slots:
    void on_startButton_clicked();

    void on_exitbutton_clicked();



    void on_level1button_clicked();

    void on_level2button_clicked();

    void on_level3button_clicked();

    void on_level4button_clicked();

    void on_level3button_2_clicked();

    void on_level5button_clicked();

private:
    Ui::maimmenu *ui;
};
#endif // MAIMMENU_H
