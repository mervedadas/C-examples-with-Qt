#ifndef FILE_H
#define FILE_H
#include<QFile>
#include<iostream>
#include<QString>
#include<QTextStream>
#include<QDataStream>
#include<QIODevice>
#include "Book.h"

using namespace std;

class File{
public:
    QString file_name;

    File(QString name){
        this->file_name=name;
        QFile file(name+".txt");
        if(!file.open(QFile::ReadWrite | QFile::Text)){
            cout << "Could not open file.";
            return;
        }
    }

    void readFile(QString name){
        QFile file(name+".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            //process_line(line);   //???
        }
    }

    void writeFile(QString name){
        QFile file(name+".txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
//        out << "QFile Tutorial";   //burası değişecek
//        file.flush();
//        file.close();
    }

    bool existing(QString u, QString p, QString f_name){
        QFile file(f_name+".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            cout<<"file could not be opened.";
            return false;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if(line == u)
                return true;
        }
    }


};

#endif // FILE_H
