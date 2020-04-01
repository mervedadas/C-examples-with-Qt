#ifndef BOOK_H
#define BOOK_H
#include <QList>
#include <QDebug>
#include <iostream>

class Book{
private:
    QString book_name;
    QString author_name;
    QString ISBN;
    int page_number;
    int publish_year;
    QList<QString> keywords;

public:
    Book();
    Book(QString,QString,QString,int,int,QList<QString>);
    void printBook();
    static void addBook();
    static void deleteBook();
    static void sortBook(const QList<Book> b);
    static void displayAllBooks();
};

#endif // BOOK_H
