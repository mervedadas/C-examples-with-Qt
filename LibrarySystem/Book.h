#ifndef BOOK_H
#define BOOK_H
#include "File.h"
#include<iostream>
#include<QString>
#include<QList>
#include<QDebug>
using namespace std;
class Book{

public:
    QString book_name;
    QString author_name;
    int ISBN[9];
    int page_number;
    int publish_year;
    QList<QString> keywords;

    Book(QString book_name,QString author_name,int ISBN[9],int page_number,int publish_year,QList<QString> keywords){
        cout<<"Object created"<<endl;
        this->book_name=book_name;
        this->author_name=author_name;
        for(int i=0;i<9;i++){
            this->ISBN[i]=ISBN[i];
        }
        this->page_number=page_number;
        this->publish_year=publish_year;
        this->keywords = keywords;

    }
    void printBook(){
        qDebug()<<"Book Name: "<< this->book_name;
        qDebug()<<"Author Name: " <<this->author_name;
        for(int i=0;i<9;i++){
            cout<<this->ISBN[i];
        }
        qDebug()<< "Page Number: "<<this->page_number;
        qDebug()<< "Publish Year: "<<this->publish_year;
        qDebug()<< "Keywords: "<< this->keywords;
    }

};
#endif // BOOK_H
