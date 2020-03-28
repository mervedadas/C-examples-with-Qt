#include <iostream>
#include "Book.h"
using namespace std;

 void bubbleSort(int arr[],int n){
    int temp;
         for(int i =0; i < n;++i){
             for(int k=0;k<n;++k){
                 if(arr[i]<arr[k]){
                   temp=arr[i];
                   arr[i]=arr[k];
                   arr[k]=temp;
                 }
             }
         }
         for(int i=0;i<n;i++){
             cout<<arr[i]<<endl;
         }
         cout<<endl;

}
