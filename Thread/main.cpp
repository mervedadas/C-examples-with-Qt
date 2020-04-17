#include<thread>
#include<QDebug>
#include <unistd.h>

void even_number();
void odd_number();

int main(void){

    std::thread odd(odd_number);
    odd.join();

    std::thread even(even_number);
    even.join();

    return 0;
}
void even_number(){

    for(int i=0;i<10;i+=2){
      qDebug()<<i;
    }

}
void odd_number(){

    for(int i=1;i<10;i+=2){
        qDebug()<<i;
    }

}
