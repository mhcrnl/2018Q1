#include <QApplication>
#include "salut.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    salut salut;
    salut.show();
    return app.exec();
}
