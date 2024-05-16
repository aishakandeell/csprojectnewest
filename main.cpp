#include "maimmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    maimmenu * open = new maimmenu();
    open->show();
    return a.exec();
}
