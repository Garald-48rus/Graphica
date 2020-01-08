#include <QApplication>

#include"view_example.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 // QGraphicsView -> QGraphicsScene -> QGraphicsItem

View_Example v;

v.show();

    return a.exec();
}
