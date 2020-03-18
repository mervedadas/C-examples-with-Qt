#include <QCoreApplication>
#include <QDebug>
#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
# define my_sizeof(type) ((int **)(&type+1)-(int**)(&type))

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    int *arr = NULL;
    unsigned long long int size,i,k;
    int temp;
    int sum=0;

    srand (time(NULL));
    cout<<"Enter size ";
    cin>>size;
    arr = new int[size];
    for(unsigned long long int i =0; i<size;i++){
        arr[i]=rand() % 10 + 1;
    }
    for(unsigned long long int i=0;i<size;i++){
       cout<<" "<<arr[i];
    }
    qDebug()<<endl;
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
        cout<<" "<<arr[i];
    }
    qDebug()<<endl;
    for(i=0;i<size;i++){
       sum += sum +arr[i];

    }
    cout<<"Total Sum: "<<sum<<endl;
    return a.exec();
}

