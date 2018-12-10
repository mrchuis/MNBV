#include <QCoreApplication>
#include "antivirus.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Antivirus antivir(&a);
    antivir.createFolder();
    antivir.checkList();
    //return a.exec();
    return 0;
}
