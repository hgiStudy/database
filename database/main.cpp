#include "peasmainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font("Microsoft YaHei", 12);
    a.setFont(font);

    PeasMainWindow w;
    w.showMaximized();
    return a.exec();
}
