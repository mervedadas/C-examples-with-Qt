#include <QDebug>
#include <mutex>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <time.h>


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


void consumer1(){
    int count=0;
    mutex.lock();

   while(q.size()!=10){
        if(count!=0){
            qDebug()<<q.front() + 2;
            q.push(q.front()+2);
            q.pop();

        }
        count++;
    }

    mutex.unlock();
}

void consumer2(){
    int count=0;
    mutex.lock();

   while(q.size()!=10){
        if(count!=1){
            qDebug()<<q.front() * 10;
            q.pop();
        }
        count++;
    }

    mutex.unlock();
}

void print(){
    for(int i=0;i<20;i++){
        qDebug()<<q.front();
        q.pop();
    }
    qDebug()<<"----------------------------";
}
