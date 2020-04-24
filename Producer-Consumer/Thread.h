#ifndef THREAD_H
#define THREAD_H


class Thread
{
public:
    Thread();
    int producer();
    void consumer(int product);

};

#endif // THREAD_H
