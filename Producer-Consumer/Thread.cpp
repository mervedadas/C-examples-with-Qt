#include "Thread.h"
#include <QDebug>
#include <time.h>
#include <QList>
#include<QMutex>

QList<int> list;
QMutex mutex;


Thread::Thread()
{
    qDebug()<<"Thread created";
}

void Thread::producer()
{   int product;
    product = 0;

    mutex.lock();

    while(list.size()!=10){
       list.append(product);
       //qDebug()<<list.last();
       product += 1;
     }

    mutex.unlock();


}

void Thread::consumer()
{

    mutex.lock();

    while(list.empty()!=true && list.size() <= 10){

        if(list.first()%2==0)
            qDebug()<<list.first();
        list.removeFirst();
    }

    mutex.unlock();


}
