#include <QCoreApplication>
#include <QDebug>
#include <array>
#include<iostream>
using namespace std;
# define my_sizeof(type) ((int *)(&type+1)-(int*)(&type))

int bubble(int argc, char *argv[]){

    int arr []={7,8,5,3,2,1};
    unsigned long long int size = my_sizeof(arr)/my_sizeof(arr[0]);
    unsigned long long int i,k;
    int temp;
    QCoreApplication a(argc, argv);
    for(i=0;i<size;++i){
       cout << arr[i];
    }
    qDebug() << endl;
    for(i =0; i < size;++i){
        for(k=0;k<size;++k){
            if(arr[i]<arr[k]){
              temp=arr[i];
              arr[i]=arr[k];
              arr[k]=temp;
            }
        }
    }
    for(i=0;i<size;++i){
       cout<<arr[i];
    }
    qDebug() << endl;
    return a.exec();
}
