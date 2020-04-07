#ifndef USER_H
#define USER_H
#include<QString>
#include "File.h"


class User{
private:
    QString username;
    QString password;

public:
    User(QString username, QString password);
    ~ User();
    void createUser(User u, File f);
    QString getUsername() const;
    QString getPassword() const;
};

#endif // USER_H
