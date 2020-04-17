#include <QCoreApplication>
#include "Thread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Thread *even = new Thread();
    Thread *odd = new Thread();

    odd->odd();
    even->even();
    odd->wait();
    even->wait();


    return a.exec();
}
