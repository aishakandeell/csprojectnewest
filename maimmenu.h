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

private:
    Ui::maimmenu *ui;
};
#endif // MAIMMENU_H
