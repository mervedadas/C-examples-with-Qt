#ifndef FILE_H
#define FILE_H
#include "Book.h"
#include<QFile>

class File{
private:
    QString file_name;
public:
     File(QString);
     static void readFile(QString);
     static void writeFile(QString,QString,QString);
     static void writeFile(QString, QString,QString ,QString,int,int,QList<QString>);
     static bool existingUser(QString, QString, QString);

};
#endif // FILE_H
