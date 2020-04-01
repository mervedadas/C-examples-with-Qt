#ifndef USER_H
#define USER_H
#include <iostream>
#include<QString>
#include<QTextStream>
#include "File.h"

class User{
private:
    int id;
    QString username;
    QString password;

public:
    User(int, QString, QString);
    ~ User();
    static void createUser(QString, QString);

};



#endif // USER_H
