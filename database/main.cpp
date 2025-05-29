#include "doudoumainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DouDouMainWindow w;
    w.show();
    return a.exec();
}
