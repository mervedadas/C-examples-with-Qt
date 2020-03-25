#ifndef USER_H
#define USER_H
#include<QList>
#include<QString>
#include<iostream>
#include "Book.h"
#include "File.h"
using namespace std;

class User{
public:
    int id;
    QString username;
    QString password;
    QList<Book> books;

    User(int id, QString username, QString password){
        this->id=id;
        this->username=username;
        this->password=password;
    }

    void addBook(Book b){
        this->books.append(b);
    }
    void deleteBook(Book b){
        this->books.removeOne(b);
    }
    void sortBook(QList<Book> b){
        for (int i =0; i<b.size();i++){
           cout << b[i].publish_year;
        }
    }
    void displayAllBooks(QList<Book> b){
        for (int i =0; i<b.size();i++){
            b[i].printBook();
        }
    }


};

#endif // USER_H
