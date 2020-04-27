#include <QCoreApplication>
#include <thread>
#include <QDebug>

void even()
{
    for(int i=0;i<10;i+=2)
        qDebug()<<i;
}

void odd()
{
    for(int i=1;i<10;i+=2)
        qDebug()<<i;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::thread th1(even);
    th1.join();

    std::thread th2(odd);
    th2.join();


    return a.exec();
}
