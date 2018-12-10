#include "antivirus.h"
#include <QDir>
#include <QDebug>
#include <windows.h>
Antivirus::Antivirus(QCoreApplication *application)
    : fileName ("")
    , extentionFile ("")
    , instruction ("")
{
}

void Antivirus::createFolder()
{
    QDir dir;
    if (dir.cd("debug"))
    {
        qDebug() << "true";
        QDir().mkdir("files");
        QDir().mkdir("virus");
    }

    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);
    list = dir.entryInfoList();

}


void Antivirus::checkList()
{
    qDebug() << "Find .exe files";
    for (int i = 0; i < list.size(); i++)
    {
        QFileInfo fileInfo = list.at(i);
        qDebug() << app->applicationName();
        parseInfo(fileInfo);

        if (extentionFile == "exe" && fileName != "lab5")
        {
            qDebug() << "Find *.exe file";
            if (compareNames(fileName, list))
                quarantineFiles(fileInfo.fileName(), "/files/");
            else
                quarantineFiles(fileInfo.fileName(), "/virus/");
        }
    }
}

void Antivirus::quarantineFiles(QString name, QString dir)
{

    qDebug() << "Move the file to quarantine " << name
             << app->applicationDirPath()+'/'+name
             << app->applicationDirPath()+dir+name
             << QFile::copy(app->applicationDirPath()+'/'+name,
                            app->applicationDirPath()+dir+name);
//    qDebug() << "Move the file to quarantine " << name << app->applicationDirPath() + '/' + name
//             << app->applicationDirPath() + dir + name
//             << QFile::copy(app->applicationDirPath() + "/debug/" + name,
//                            app->applicationDirPath() + dir + name);
    qDebug() << QFile::remove("C:/Users/Anton/Documents/build-lab5-Desktop_Qt_5_11_2_MinGW_32bit-Debug/debug/" + name);
}

bool Antivirus::compareNames(QString name, QFileInfoList list)
{
    qDebug() << "Look for matches";
    for (int i = 0; i < list.size(); i++)
    {
        QFileInfo fileInfo = list.at(i);
        parseInfo(fileInfo);
        if (fileName == name & extentionFile != "exe" & fileInfo.isHidden())
        {
            qDebug() << "Fond aa file with the same name *.exe:" << fileInfo.fileName();
            setUnhidden(fileInfo.fileName());
            return true;
        }
    }
    qDebug() << "No matches found!";
    return false;
}

void Antivirus::setUnhidden(QString fileName)
{
    QByteArray ba = fileName.toUtf8();
    qDebug() << "Showing the file: " << ba << SetFileAttributesA(ba, FILE_ATTRIBUTE_NORMAL);
}

void Antivirus::parseInfo(QFileInfo fileInfo)
{
    fileName = "";
    instruction = "start ./";
    instruction += fileInfo.fileName();
    QStringList pairs = fileInfo.fileName().split(".");
    if (pairs.length() != 1)
    {
        extentionFile = pairs[pairs.length() - 1];
        for (int i = 0; i < pairs.length() - 1; i++)
        {
            fileName += pairs[i];
            if (pairs.length() - i > 2)
                fileName += '.';
        }
    }
    else
    {
        fileName = pairs[pairs.length() - 1];
        extentionFile = "";
    }
    qDebug() << "File name:" << fileName << "Extention:" << extentionFile;
}



