#include <QCoreApplication>
#include <thread>
#include "producer-consumer.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::thread th1(producer1);
    std::thread th3(producer2);
    th1.join();
    th3.join();

   // print();
    std::thread th2(consumer1);
    th2.join();
    std::thread th4(consumer2);
    th4.join();


    return a.exec();
}
