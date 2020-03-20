#include <QCoreApplication>
#include <QDebug>
#include<iostream>

using namespace std;

#define ROW 5
#define COL 7

int findConnected(int array[][COL], int x, int y) {

            if (array[x][y] == 1) {
                array[x][y] = 0;

                findConnected(array, x + 1, y);
                findConnected(array, x, y + 1);
                findConnected(array, x - 1, y);
                findConnected(array, x, y - 1);
                findConnected(array, x + 1, y + 1);
                findConnected(array, x - 1, y - 1);
                findConnected(array, x + 1, y - 1);
                findConnected(array, x - 1, y + 1);

            }
            return 1;
}

int main(){
     int  array[][COL] ={ { 1, 0, 0, 0, 0 },
                          { 0, 0, 1, 1, 1 },
                          { 0, 0, 1, 0, 0 },
                          { 0, 1, 1, 0, 0 },
                          { 1, 0, 0, 0, 1 },
                          { 1, 0, 0, 1, 1 },
                          { 0, 0, 0, 0, 0}};

//     for(int i=0;i<ROW;i++){
//         for(int j=0;j<COL;j++){
//             if(array[i][j]==1)
//                 array[i][j]=0;
//             else
//                 array[i][j]=1;
//         }
//     }


     for(int i=0;i<ROW;i++){
         for(int j=0;j<COL;j++){
             cout<<array[i][j]<<" ";
         }
         cout<<endl;
     }


       int total = 0;
       for(int i=0; i<ROW; i++){
           for(int j=0; j<COL; j++){
               if(array[i][j] == 1){
                   cout<<"Im total: "<<total<<endl;
                   findConnected(array,i,j);
                   total+=1;

               }

           }
       }
       cout<<"Total number of connected path is " << total<<endl;
       return 0;
}




