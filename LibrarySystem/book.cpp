#include <QDebug>
#include <iostream>
#include "Book.h"
#include "File.h"
QList<Book> books;
void bubbleSort(int arr[],int n);

QString Book::getBook_name() const
{
    return book_name;
}

QString Book::getAuthor_name() const
{
    return author_name;
}

QString Book::getISBN() const
{
    return ISBN;
}

int Book::getPublish_year() const
{
    return publish_year;
}

QList<QString> Book::getKeywords() const
{
    return keywords;
}

int Book::getPage_number() const
{
    return page_number;
}

Book::Book(QString book_name,QString author_name,QString ISBN,int page_number,int publish_year,QList<QString> keywords){
    this->book_name=book_name;
    this->author_name=author_name;
    this->ISBN=ISBN;
    this->page_number=page_number;
    this->publish_year=publish_year;
    this->keywords = keywords;
      //Book *book = new Book(book_name,author_name,ISBN,page_number,publish_year,keywords); // hiç emin değilim

}

void Book::printBook(Book b)
{
    qDebug()<<"Book Name:" << b.book_name;
    qDebug()<<"Author Name: " <<b.author_name;
    qDebug()<<"ISBN: " << b.ISBN;
    qDebug()<< "Page Number: "<<b.page_number;
    qDebug()<< "Publish Year: "<<b.publish_year;
    for(int i =0; i<b.keywords.size();i++)
        qDebug()<< "Keywords: "<< b.keywords[i];
}




void Book::addBook(Book b){

    File file("Book");
    File::writeFileB(file,b);

}

void Book::deleteBook(QString bookname){
    QList<Book> all ;
    File file("Book");
    all=File::readFile(file);

    for(int i =0;i<all.size();i++){
        if(all[i].book_name==bookname){
            all.removeAt(i);
        }
    }
    File::writeFile(file,all);

}

void Book::sortBook(){
     QList<Book> all ;
     File file("Book");
     all=File::readFile(file);
      QList<Book> sortbook = sorting(all);
      for(int i=0;i<sortbook.size();i++){
          printBook(sortbook[i]);
      }
}

void Book::displayingAllBooks()
{   File file("Book");
    QList<Book> all ;
    all=File::readFile(file);
    for(int i =0; i<all.size();i++){
        printBook(all[i]);
    }
}


QList<Book> Book::sorting(QList<Book> b){
    QList<Book> temp;
    temp=b;
    for(int i=0;i<b.size();i++){
        for(int k=0;k<b.size();k++){
            if(b[i].getPublish_year()<b[k].getPublish_year()){
                temp[i]=b[i];
                b[i]=b[k];
                b[k]=temp[i];
            }
        }
    }
    return b;
}
