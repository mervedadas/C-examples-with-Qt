#include "User.h"

void User::createUser(){

    QTextStream u(stdin);
    qDebug()<<"Username: ";
    QString username = u.readLine();

    QTextStream p(stdin);
    qDebug()<<"Password: ";
    QString password = p.readLine();

    int id=0;
    if(File::existingUser("User",username,password)){
        menu();
    }
    else{
        qDebug()<<"User not found.";
        qDebug()<<"Please register to the system.";
        QTextStream u(stdin);
        qDebug()<<"Username: ";
        QString username = u.readLine();
        qDebug() <<endl;
        QTextStream p(stdin);
        qDebug()<<"Password: ";
        QString password = p.readLine();
        id+=1;
        File::writeFile("User",username,password);
        menu();
    }
}

int User::menu(){
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
        File::readFile("Book");
       // Book::sortBook(books);

    }
    else if(choice=='X'){
        QList<Book> all;
        qDebug()<<"Displaying all books ";
        File::readFile("Book");
        Book::displayAllBooks();
    }
    }while(choice!='Q');
    return 0;
}
