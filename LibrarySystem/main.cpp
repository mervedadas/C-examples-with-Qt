#include <QCoreApplication>
#include<iostream>
#include<QList>
#include<QString>
#include<string>
using namespace std;
#include "Book.h"
#include "File.h"
#include "User.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QList<QString> list={"h","b"};
//    Book b("a","b",12,12,2020,list);
//    b.printBook();

    QTextStream u(stdin);
    cout<<"Username: ";
    QString username = u.readLine();
    cout <<endl;

    QTextStream p(stdin);
    cout<<"Password: ";
    QString password = p.readLine();

    QList<User> user;





    return a.exec();
}
