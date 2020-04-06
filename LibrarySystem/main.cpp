#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <User.h>
#include <Book.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int id=0;
    QTextStream u(stdin);
    qDebug()<<"Username: ";
    QString username = u.readLine();

    QTextStream p(stdin);
    qDebug()<<"Password: ";
    QString password = p.readLine();

    User user(id,username,password);

    char choice;
    do{
    qDebug() <<"MENU"<<endl;
    qDebug() <<"Please enter the key according to want to do. "<<endl
         <<"Press A to insert a book"<<endl
         <<"Press D to delete a book"<<endl
         <<"Press S to sort all books (date)" <<endl
         <<"Press X to display all books"<<endl
         <<"Press Q to exit"<<endl;
    std::cin >> choice;

    if(choice=='A'){
        Book::addBook();

    }
    else if(choice=='D'){
        Book::deleteBook();

    }
    else if(choice=='S'){
        qDebug()<<"Sorted Book List for publish year ";
        Book::sortBook();

    }
    else if(choice=='X'){
        qDebug()<<"All Books ";
        Book::displayingAllBooks();
    }

    }while(choice!='Q');
    id++;

    return a.exec();
}
