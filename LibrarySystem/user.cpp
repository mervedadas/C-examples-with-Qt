#include "User.h"
#include "Book.h"

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
        QList<Book> all ;
        all=File::readFile("Book");
        all = Book::deleteBook(all);
        //write again file
        File::writeFile("Book",all);

    }
    else if(choice=='S'){
        QList<Book> all ;
        qDebug()<<"Sorted Book List for publish year ";
        all=File::readFile("Book");
        Book::sortBook(all);

    }
    else if(choice=='X'){
        QList<Book> all ;
        qDebug()<<"Displaying all books ";
        all=File::readFile("Book");
        for(int i =0; i<all.size();i++){
            all[i].printBook();
        }
    }

    }while(choice!='Q');
    return 0;
}
