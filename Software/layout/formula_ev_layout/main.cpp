#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QPalette pal = w.palette();
    pal.setColor(QPalette::Window, QColor(QString("#221f1f")));
    w.setPalette(pal);
    w.showMaximized();
    return a.exec();
}
