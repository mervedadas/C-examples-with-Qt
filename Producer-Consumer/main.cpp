#include <QCoreApplication>
#include "Thread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    while(1){
        Thread *producer = new Thread();
        producer->producer();
        producer->wait();

        Thread *consumer = new Thread();
        consumer->consumer();
        consumer->wait();
    }

    return a.exec();
}
