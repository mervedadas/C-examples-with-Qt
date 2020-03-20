#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    int *workPackage = NULL;
    int size;
    int temp;
    int workingTime=0;
    char controlKey = NULL;
    do{
    workingTime = 0;
    srand (time(NULL));
    cout<<"Enter array size for work packages: ";
    cin>>size;
    workPackage = new int[size];
    for(int i =0; i<size;i++){
        workPackage[i]=rand() % 10 + 1;
    }
    cout << "Work Packages: ";
    for(int i=0;i<size;i++){
       cout<<" "<<workPackage[i];
    }
    cout<<endl;
    for(int i =0; i < size;++i){
        for(int k=0;k<size;++k){
            if(workPackage[i]<workPackage[k]){
              temp=workPackage[i];
              workPackage[i]=workPackage[k];
              workPackage[k]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
       workingTime += workingTime + workPackage[i];

    }
    cout<<"Shortest Working Time: "<< workingTime <<endl;
    cout<<"Could you continue? (If yes, please enter any key(except 'q') or quit for 'q')";
    cin >>controlKey;
    }while(controlKey != 'q');
    return a.exec();
}
