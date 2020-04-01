#ifndef FILE_H
#define FILE_H
#include<QFile>
#include "Book.h"
#include <QDebug>

class File{
private:
    QString file_name;
public:
     File(QString);
     static QList<Book> readFile(QString);
     static void writeFile(QString,QString,QString);
     static void writeFile(QString, QString,QString ,QString,int,int,QList<QString>);
     static void writeFile(QString, const QList<Book>);
     static bool existingUser(QString, QString, QString);

};
#endif // FILE_H
