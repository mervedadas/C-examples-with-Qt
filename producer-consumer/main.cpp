#include <QCoreApplication>
#include <thread>
#include "producer-consumer.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::thread th1(producer1);
    std::thread th2(consumer1);
    th1.join();
    th2.join();
    std::thread th3(producer2);
    std::thread th4(consumer2);
    th3.join();
    th4.join();


    return a.exec();
}
