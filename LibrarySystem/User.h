#ifndef USER_H
#define USER_H
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
    static void createUser();
    static int menu();

};



#endif // USER_H
