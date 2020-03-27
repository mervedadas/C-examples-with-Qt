#include <QCoreApplication>
#include<iostream>
using namespace std;
#include "Book.h"
#include "File.h"
#include "User.h"

int main()
{

//    QList<QString> list={"h","b"};
//    Book b("a","b",12,12,2020,list);
//    b.printBook();
    //User us(1,"mervos","856");

    QTextStream u(stdin);
    cout<<"Username: ";
    QString username = u.readLine();
    cout <<endl;

    QTextStream p(stdin);
    cout<<"Password: ";
    QString password = p.readLine();




    return 0;

}


