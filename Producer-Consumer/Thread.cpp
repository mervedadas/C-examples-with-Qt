#include "Thread.h"
#include <QDebug>
#include <time.h>
#include <QList>
int buffer_size = 10;
QList<int> qList;
Thread::Thread()
{
    qDebug()<<"Thread created";
}

int Thread::producer()
{
    int product;
    srand (time(NULL));
    while(1){
    product = rand() % 10 + 1;
    if(qList.size()==buffer_size)
        //wait
    consumer(product);

    }

    return product;
}

void Thread::consumer(int product)
{   while(1){

    if(qList.size()<=10)
    qDebug()<<product;
    }
}
