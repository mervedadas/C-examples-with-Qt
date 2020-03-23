#ifndef FILE_H
#define FILE_H
#include<QFile>
#include<iostream>
#include<QString>
#include<QTextStream>
#include<QDataStream>
#include<QIODevice>
#include "Book.h"

//using namesapce std;

//class File{
//public:
//    QString file_name;

//    File(QString f_name){
//        this.file_name = f_name;
//    }

//    void openFile(QString f_name){
//        QFile file(f_name);
//        if ( file.open(QIODevice::ReadWrite) ){
//            cout<< "File opened";
//        }
//        else
//            cout<<"File could not be opened.";

//    }

//    void writeFile(File f, Book b){
//        if(!f.open(QIODevice::ReadWrite | QIODevice::Text))
//             cout<<"File could not be opened.";
//        else{
//             QTextStream file(&f); // :(
//             file<<b.book_name;

//        }


//    }

//    void searchFile(QString search){
//        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//             return;

//         QTextStream in(&file);
//         while (!in.atEnd()) {
//             QString line = in.readLine();
//             if(line == search){
//                 //
//                 continue;
//             }
//             process_line(line);
//         }
//   }

//};

#endif // FILE_H
