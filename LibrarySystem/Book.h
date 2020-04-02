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
    static QList<Book> deleteBook(QList<Book> b);
    static void sortBook(const QList<Book> b);
    QString getBook_name() const;
    QString getAuthor_name() const;
    QString getISBN() const;
    int getPublish_year() const;
    QList<QString> getKeywords() const;
    int getPage_number() const;
    static QList<Book> sorting(QList<Book> b);
};

#endif // BOOK_H
