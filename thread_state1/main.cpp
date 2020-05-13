#include <QCoreApplication>
#include <thread>

#include<iostream>
#include <unistd.h>


void getID(int i)
{
    std::cout << "start" << std::endl;
    usleep(1000000);

    std::thread::id threadID = std::this_thread::get_id();
    usleep(1000000);

    std::cout << i <<". " <<  "Thread ID : " << threadID <<std::endl;

    usleep(1000000);
    std::cout << "end" << std::endl;
}

int main()
{

    std::thread t1(getID,1);
    std::thread t2(getID,2);
    std::thread t3(getID,3);
    std::thread t4(getID,4);

    t1.join();

    t2.join();

    t3.join();

    t4.join();


    return 0;
}
