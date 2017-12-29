#include <QApplication>
#include "kdeapp.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    kdeapp kdeapp;
    kdeapp.show();
    return app.exec();
}
