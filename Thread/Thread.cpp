#include "Thread.h"
#include <QDebug>

Thread::Thread()
{
    qDebug()<<"Thread created";
}

void Thread::even()
{
    for(int i=0;i<100;i+=2)
        qDebug()<<i;
}

void Thread::odd()
{
    for(int i=1;i<100;i+=2)
        qDebug()<<i;
}
