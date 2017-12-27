#include <QApplication>
#include "mykdeapp.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    mykdeapp mykdeapp;
    mykdeapp.show();
    return app.exec();
}
