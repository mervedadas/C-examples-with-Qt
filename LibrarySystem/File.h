#ifndef FILE_H
#define FILE_H
#include<QFile>
#include "Book.h"
#include "User.h"


class File{
private:
    QString file_name;
public:
     File(QString);
     static QList<Book> readFile(File f);
     void writeFileU( User u);
     static void writeFileB(File f, Book b);
     static void writeFile(File f, const QList<Book>);
     static bool existingUser(File f, User u);

     QString getFile_name() const;
};
#endif // FILE_H
