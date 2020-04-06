#ifndef BOOK_H
#define BOOK_H
#include <QList>

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
    static void printBook(Book b);
    static void addBook(Book b);
    static void deleteBook(QString bookname);
    static void sortBook();
    static void displayingAllBooks();
    QString getBook_name() const;
    QString getAuthor_name() const;
    QString getISBN() const;
    int getPublish_year() const;
    QList<QString> getKeywords() const;
    int getPage_number() const;
    static QList<Book> sorting(QList<Book> b);

};

#endif // BOOK_H
