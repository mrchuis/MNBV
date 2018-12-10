#ifndef VIRUS_H
#define VIRUS_H
#include <QCoreApplication>
#include <QFileInfo>
#include <QStringList>
class Virus
{
private:
    QString extentionFile, fileName, instruction, name;
    QStringList pairs;
    QFileInfoList list;
    QCoreApplication *app;
    //парсинг содержимого каталога
    void parseInfo(QFileInfo fileInfo);
    //скрытие папки
    void hideFile();
public:
    Virus(QCoreApplication *a);
    ~Virus();
    //создание дубликата
    void createDublicate();
    //создание листа
    QFileInfoList createList();
};

#endif // VIRUS_H
