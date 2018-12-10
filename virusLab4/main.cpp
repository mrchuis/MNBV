#include <QCoreApplication>
#include "virus.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Virus vir(&a);
    vir.createList();
    vir.createDublicate();
    //return a.exec();
    return 0;
}
