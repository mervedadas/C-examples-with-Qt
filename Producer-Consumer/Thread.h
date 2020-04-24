#ifndef THREAD_H
#define THREAD_H

#include<QThread>


class Thread : public QThread
{
public:
    Thread();
    void producer();
    void consumer();

};

#endif // THREAD_H
