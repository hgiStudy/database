#include "peasmainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PeasMainWindow w;
    w.show();
    return a.exec();
}
