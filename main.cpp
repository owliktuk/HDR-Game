#include <QtGui/QApplication>
#include "hdr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hdr w;
    w.show();

    return a.exec();
}


