#ifndef FILE_H
#define FILE_H
#include<QFile>
#include<QTextStream>
#include<QDataStream>
#include<QIODevice>
#include "Book.h"

using namespace std;

class File{
public:
    QString file_name;

    File(QString name){
        cout<<"file constructor"<<endl;
        this->file_name=name;
        QFile file(name+".txt");
        if(!file.open(QFile::ReadWrite | QFile::Text)){
            cout << "Could not open file."<<endl;
            return;
        }
        else{
            cout<<"File opening"<<endl;
        }

    }


    static void readFile(QString name){
        QFile file(name+".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            cout << "hello"<<endl;
            //process_line(line);   //???
        }
    }

   static void writeFile(QString name,QString u,QString p){
        QFile file(name+".txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
            return;
        QTextStream out(&file);
        out << u << endl;
        out << p << endl;

    }

   static bool existingUser(QString u, QString p, QString f_name){
       QFile file(f_name+".txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           cout<<"file could not be opened.";
           return false;
       }

       QTextStream in(&file);
       while (!in.atEnd()) {
           QString username = in.readLine();
           QString password = in.readLine();
           if(username == u && password==p)
               return true;
       }
       return false;
   }


};
#endif // FILE_H
