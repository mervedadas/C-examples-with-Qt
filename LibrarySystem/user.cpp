#include <QDebug>
#include "User.h"
#include "Book.h"
#include "File.h"


QString User::getUsername() const
{
    return username;
}

QString User::getPassword() const
{
    return password;
}

User::User(QString u, QString p)
{
    this->username = u;
    this->password = p;

    User *user = new User(u,p);
    File file("User");
    createUser(*user,file);
}

User::~User()
{
    qDebug()<<"User deconstructor.";
}

void User::createUser(User u, File f){

    if(f.existingUser(f.getFile_name(),u)){
        return;
    }
    else{
        qDebug()<<"User not found.";
        qDebug()<<"Please register to the system.";
        QTextStream u(stdin);
        qDebug()<<"Username: ";
        QString username = u.readLine();
        qDebug() <<endl;
        QTextStream p(stdin);
        qDebug()<<"Password: ";
        QString password = p.readLine();
        f.writeFileU(u);
    }
}

