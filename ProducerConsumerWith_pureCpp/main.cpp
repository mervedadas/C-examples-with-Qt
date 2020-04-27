#include <QCoreApplication>
#include <thread>
#include <QDebug>

#include <mutex>

std::list<int> list;
std::mutex mutex;

void producer()
{   int product;
    product = 0;

    mutex.lock();

    while(list.size()!=10){
       list.push_back(product);
       //qDebug()<<list.back();
       product += 1;
     }

    mutex.unlock();

}

void consumer()
{

    mutex.lock();

    while(list.empty()!=true && list.size() <= 10){


        if(list.front()%2==0)
            qDebug()<<list.front();
        list.pop_front();
    }

    mutex.unlock();
   // producer();


}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::thread th1(producer);
    std::thread th2(consumer);
    th1.join();
    th2.join();

    return a.exec();
}
