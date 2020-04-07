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
     QList<Book> readFile();
     void writeFileU(User u);
     void writeFileB(Book b);
     void writeFile(const QList<Book>);
     bool existingUser(User u);

     QString getFile_name() const;
};
#endif // FILE_H
