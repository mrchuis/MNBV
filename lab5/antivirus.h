#ifndef ANTIVIRUS_H
#define ANTIVIRUS_H
#include <QCoreApplication>
#include <QFileInfoList>

class Antivirus
{
private:
    QCoreApplication *app;
    QString fileName, extentionFile, instruction, filename;
    QFileInfoList list;
    void parseInfo(QFileInfo fileInfo);
    bool compareNames(QString name, QFileInfoList list);
    void setUnhidden(QString fileName);
    void quarantineFiles(QString name, QString dir);
public:
    Antivirus(QCoreApplication *application);
    void checkList();
    void createFolder();

};

#endif // ANTIVIRUS_H
