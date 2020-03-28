#include <QCoreApplication>
#include<iostream>
using namespace std;
#include "Book.h"
#include "File.h"
#include "User.h"
void menu();
int main()
{
    cout<<books.size()<<endl;
    QTextStream u(stdin);
    cout<<"Username: ";
    QString username = u.readLine();
    cout <<endl;

    QTextStream p(stdin);
    cout<<"Password: ";
    QString password = p.readLine();

    int id=0;
    if(File::existingUser(username,password,"User")){
        menu();
    }
    else{
        cout<<"User not found."<<endl;
        cout<<"Please register to the system."<<endl;
        QTextStream u(stdin);
        cout<<"Username: ";
        QString username = u.readLine();
        cout <<endl;
        QTextStream p(stdin);
        cout<<"Password: ";
        QString password = p.readLine();
        id+=1;
        File::writeFile("User",username,password,id);
        menu();
    }

    return 0;

}

void menu(){
    char choice;
    do{
    cout <<"MENU"<<endl;
    cout <<"Please enter the key according to want to do. "<<endl
         <<"Press A to insert a book"<<endl
         <<"Press D to delete a book"<<endl
         <<"Press S to sort all books (date)" <<endl
         <<"Press X to display all books"<<endl
         <<"Press Q to exit"<<endl;
    cin >> choice;

    if(choice=='A'){
        User::addBook();

    }
    else if(choice=='D'){
        User::deleteBook();

    }
    else if(choice=='S'){
        cout<<"Sorted Book List for publish year "<<endl;
            User::sortBook(books);

    }
    else if(choice=='X'){
        cout<<"Displaying all books "<<endl;
            User::displayAllBooks();
    }
    }while(choice!='Q');
    return;
}


