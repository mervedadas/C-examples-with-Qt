#include "User.h"
#include "Book.h"

User::User(int, QString u, QString p)
{   this->id=id;
    this->username = u;
    this->password = p;
    createUser(u,p);

}

User::~User()
{
    qDebug()<<"User deconstructor.";
}

void User::createUser(QString username, QString password){
    int id=0;
    if(File::existingUser("User",username,password)){
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
        id+=1;
        File::writeFile("User",username,password);
    }
}

