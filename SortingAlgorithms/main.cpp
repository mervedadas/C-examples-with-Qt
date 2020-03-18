#include <QCoreApplication>
#include <QDebug>
#include <array>
#include<iostream>
using namespace std;

#define my_sizeof(type) ((int *)(&type+1)-(int*)(&type)) //According to type calculating size of array

int main(int argc, char *argv[]){

     QCoreApplication a(argc, argv);
     int arr []={7,8,5,3,2,1};
     int size = my_sizeof(arr)/my_sizeof(arr[0]);
     int temp;
     qDebug()<<"Unsorted Array: ";
     for(int i=0;i<size;++i){
        cout << arr[i]<<" ";
     }
     qDebug() << endl;
     for(int i =0; i < size;++i){
         for(int k=0;k<size;++k){
             if(arr[i]<arr[k]){
               temp=arr[i];
               arr[i]=arr[k];
               arr[k]=temp;
             }
         }
     }
     qDebug()<<"Sorted Array: ";
     for(int i=0;i<size;++i){
        cout<< arr[i]<<" ";
     }
     qDebug() << endl;
     return a.exec();
}
