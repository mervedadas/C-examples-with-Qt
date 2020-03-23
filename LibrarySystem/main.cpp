#include <QCoreApplication>
#include "Book.h"
#include<iostream>
#include<QList>
#include<QString>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QList<QString> list={"h","b"};
//    Book b("a","b",12,12,2020,list);
//    b.printBook();

    QString username;

    return a.exec();
}
