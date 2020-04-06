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

    User user(username,password);

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

        Book b(book_name,author_name,ISBN,page_number,publish_year,keywords);
        Book::addBook(b);

    }
    else if(choice=='D'){
        QString book_name;
        qDebug()<<"Please enter book name that want to delete";
        QTextStream b_name(stdin);
        book_name = b_name.readLine();

        Book::deleteBook(book_name);

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
