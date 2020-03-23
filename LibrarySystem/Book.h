#ifndef BOOK_H
#define BOOK_H
#include "File.h"
#include<iostream>
#include<QString>
#include<QList>
#include<QDebug>
using namespace std;
class Book{
private:

    QString book_name;
    QString author_name;
    int ISBN;
    int page_number;
    int publish_year;
    QList<QString> keywords;

public:

    Book(QString book_name,QString author_name,int ISBN,int page_number,int publish_year,QList<QString> keywords){
        cout<<"Object created"<<endl;
        this->book_name=book_name;
        this->author_name=author_name;
        this->ISBN=ISBN;
        this->page_number=page_number;
        this->publish_year=publish_year;
        this->keywords = keywords;

    }


    void printBook(){
        qDebug()<<"Book Name: "<< this->book_name;
        qDebug()<<"Author Name: " <<this->author_name;
        qDebug()<< "ISBN Number: "<<this->ISBN;
        qDebug()<< "Page Number: "<<this->page_number;
        qDebug()<< "Publish Year: "<<this->publish_year;
        qDebug()<< "Keywords: "<< this->keywords;
    }

//    void friend addBook(Book book){
//        book.printBook();
//        File file("Book");
//        file.writeFile(book);



//   }





};

































#endif // BOOK_H
