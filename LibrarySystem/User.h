#ifndef USER_H
#define USER_H
#include<iostream>
#include "Book.h"
#include "File.h"
#include <bubbleSort.cpp>
using namespace std;

QList<Book> books;

class User{
public:
    int id;
    QString username;
    QString password;

    User(int id, QString username, QString password){
        this->id=id;
        this->username=username;
        this->password=password;
    }

    static void addBook(){
        QString book_name;
        QString author_name;
        QString ISBN;
        int page_number;
        int publish_year;
        QList<QString> keywords;

        cout<<"Please Enter Book information"<<endl;
        cout<<"Book Name: ";

        QTextStream b_name(stdin);
        book_name = b_name.readLine();

        cout<<"Author Name: ";
        QTextStream a_name(stdin);
        author_name = a_name.readLine();

        cout <<"ISBN(Should be 9 digits): ";
        QTextStream isbn(stdin);
        ISBN = isbn.readLine();

        cout <<"Page Number: ";
        cin>>page_number;


        cout<<endl<<"Publish Year";
        cin>>publish_year;

        cout<<"Book' Keywords";
        QTextStream kw(stdin);
        keywords.append(kw.readLine());

        Book b(book_name,author_name,ISBN,page_number,publish_year,keywords);
        books.append(b);
        displayAllBooks();
        File::writeFile("Book",book_name,author_name,ISBN,page_number,publish_year,keywords);

    }
    static void deleteBook(){
        QString book_name;
        cout<<"Please enter book name that want to delete";
        QTextStream b_name(stdin);
        book_name = b_name.readLine();

        for(int i =0;i<(books).size();i++){
            if(books[i].book_name==book_name){
                books.removeAt(i);
            }
        }

    }
    static void sortBook(const QList<Book> b){
        int arr[b.size()];
        for (int i =0; i<b.size();i++){
           arr[i]= b[i].publish_year;
        }
        bubbleSort(arr,b.size());
    }
    static void displayAllBooks(){
        cout<<"book size"<<books.size()<<endl;
        for (int i =0; i<books.size();i++){
            books[i].printBook();
        }
    }

};
#endif // USER_H
