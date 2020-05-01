#include <QDebug>
#include <mutex>
#include <queue>


std::queue<int> q;
std::mutex mutex;

void producer1(){
    int product;
    srand (time(NULL));


    mutex.lock();
    for(int i =0 ; i<10;i++){
        product = rand() % 100 + 1;
        q.push(product);

    }
    mutex.unlock();

}

void consumer1(){
    int count=0;
    mutex.lock();

    while(q.size()!=0){
        if(count!=10){
            qDebug()<<q.front() + 2;
            q.pop();
        }
        count++;
    }

    mutex.unlock();
}


void producer2(){
    int product;
    srand (time(NULL));

    mutex.lock();
    for(int i =0 ; i<10;i++){
        product = rand() % 500 + 200;
        q.push(product);

    }
    mutex.unlock();

}

void consumer2(){
    int count=0;
    mutex.lock();

    while(q.size()!=0){
        if(count!=10){
            qDebug()<<q.front() * 10;
            q.pop();
        }
        count++;
    }

    mutex.unlock();
}
