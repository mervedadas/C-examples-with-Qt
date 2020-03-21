#include <QCoreApplication>
#include <QDebug>
#include<iostream>
using namespace std;

#define COL 5
#define ROW 7

void findRegion(int arr[][COL],int row,int col);
bool existCoordinate(int r,int c);
void printMatrix(int arr[][COL]);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int totalRegion=0;

    int  array[][COL] ={ { 1, 1, 0, 0, 0 },
                         { 0, 0, 1, 1, 1 },
                         { 0, 0, 1, 0, 0 },
                         { 0, 1, 1, 0, 0 },
                         { 1, 0, 1, 0, 1 },
                         { 1, 0, 1, 1, 1 },
                         { 0, 0, 1, 0, 0}};


    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++)
            if(array[i][j]==0){
                totalRegion+=1;
                findRegion(array,i,j);
            }
    }

    cout<<"Number of Total Region: "<<totalRegion<<endl;

    return a.exec();
}
void findRegion(int arr[][COL],int row,int col){

   if(existCoordinate(row, col)==true){
       if(arr[row][col]==0){
           arr[row][col]=1;
           findRegion(arr,row,col+1);
          // printMatrix(arr);
           findRegion(arr,row,col-1);
          // printMatrix(arr);
           findRegion(arr,row+1,col);
          //printMatrix(arr);
           findRegion(arr,row-1,col);
          //printMatrix(arr);

       }
   }
}
bool existCoordinate(int r,int c){
    //cout<<"hello"<<endl;
    if(r>=0 && r<ROW){
        if(c>=0 && c<COL){
            return true;
        }
    }
    return false;
}

void printMatrix(int arr[][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++)
            cout<< arr[i][j]<<" ";
        cout<<endl;
    }
}

