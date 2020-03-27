#ifndef USER_H
#define USER_H
#include<iostream>
#include "Book.h"
#include "File.h"
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
        File file("User");

        if(file.existingUser(username,password,"User")){
            menu();
        }
        else{
           cout<<"REGISTER"<<endl;
           cout<<"Username: ";

           file.writeFile("User",username,password);
        }
    }
        int menu(){
            char choice;
            cout <<"MENU"<<endl;
            cout <<"Please enter the key according to want to do. "<<endl
                 <<"Press A to insert a book"<<endl
                 <<"Press D to delete a book"<<endl
                 <<"Press S to sort all books (date)" <<endl
                 <<"Press X to display all books"<<endl
                 <<"Press Q to exit"<<endl;
            cin >> choice;

            if(choice=='A'){
                QString book_name;
                QString author_name;
                int ISBN[9];
                int page_number;
                int publish_year;
                QList<QString> keywords;

                cout<<"Please Enter Book information"<<endl;
                cout<<"Book Name: ";

                QTextStream b_name(stdin);
                book_name = b_name.readLine();

                cout<<"Author Name: ";
                QTextStream a_name(stdin);
                book_name = a_name.readLine();

                cout <<"Page Number: ";
                cin>>page_number;

                cout <<"ISBN(Should be 9 digits): ";
                for(int i=0;i<9;i++){
                    cin>>ISBN[i];
                }
                cout<<endl<<"Publish Year";
                cin>>publish_year;

                cout<<"Book' Keywords";
                QTextStream kw(stdin);
                keywords.append(kw.readLine());

                Book b(book_name,author_name,&ISBN[9],page_number,publish_year,keywords);
                addBook(b);

                return 0;
            }
            else if(choice=='D'){
                QString book_name;
                cout<<"Please enter book name that want to delete";
                QTextStream b_name(stdin);
                book_name = b_name.readLine();

                for(int i =0;i<(books).size();i++){
                    if(books[i].book_name==book_name){
                        deleteBook(i);
                        cout<<"remove function gelcek";
                    }
                }
                return 0;
            }
            else if(choice=='S'){
                cout<<"Sorted Book List for publish year "<<endl;
                    sortBook(books);
                return 0;
            }
            else if(choice=='X'){
                cout<<"Displaying all books "<<endl;
                    displayAllBooks(books);
            }
            else if(choice=='Q'){
                    return 0;
            }

            return 0;
        }


    void addBook(Book b){
        books.append(b);
    }
    void deleteBook(int i){
        books.removeAt(i);
    }
    void sortBook(const QList<Book> b){
        for (int i =0; i<b.size();i++){
           cout << b[i].publish_year; // sıralama algoritması
        }
    }
    void displayAllBooks(QList<Book> b){
        for (int i =0; i<b.size();i++){
            b[i].printBook();
        }
    }


};
#endif // USER_H
