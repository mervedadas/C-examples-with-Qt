#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread();
    void even();
    void odd();


};

#endif // THREAD_H
