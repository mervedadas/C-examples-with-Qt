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
}


void Book::printBook(){
    qDebug()<<"Book Name:" << this->book_name;
    qDebug()<<"Author Name: " <<this->author_name;
    qDebug()<<"ISBN: " <<this->ISBN;
    qDebug()<< "Page Number: "<<this->page_number;
    qDebug()<< "Publish Year: "<<this->publish_year;
    qDebug()<< "Keywords: "<< this->keywords;
}

void Book::addBook(){
    QString book_name;
    QString author_name;
    QString ISBN;
    int page_number;
    int publish_year;
    QList<QString> keywords;

    qDebug()<<"Please Enter Book information";

    qDebug()<<"Book Name: "<<endl;
    QTextStream b_name(stdin);
    book_name = b_name.readLine();

    qDebug()<<"Author Name: ";
    QTextStream a_name(stdin);
    author_name = a_name.readLine();

    qDebug() <<"ISBN(Should be 9 digits): ";
    QTextStream isbn(stdin);
    ISBN = isbn.readLine();

    qDebug() <<"Page Number: ";
    std::cin>>page_number;


    qDebug()<<endl<<"Publish Year";
    std::cin>>publish_year;

    qDebug()<<"Book' Keywords";
    QTextStream kw(stdin);
    keywords.append(kw.readLine());

    File::writeFile("Book",book_name,author_name,ISBN,page_number,publish_year,keywords);

}

void Book::deleteBook(){
    QList<Book> all ;
    all=File::readFile("Book");
    QString book_name;
    qDebug()<<"Please enter book name that want to delete";
    QTextStream b_name(stdin);
    book_name = b_name.readLine();

    for(int i =0;i<all.size();i++){
        if(all[i].book_name==book_name){
            all.removeAt(i);
        }
    }
    File::writeFile("Book",all);

}

void Book::sortBook(){
     QList<Book> all ;
      all=File::readFile("Book");
      QList<Book> sortbook = sorting(all);
      for(int i=0;i<sortbook.size();i++){
          sortbook[i].printBook();
      }
}

void Book::displayingAllBooks()
{
    QList<Book> all ;
    all=File::readFile("Book");
    for(int i =0; i<all.size();i++){
        all[i].printBook();
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
