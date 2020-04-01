#include <QCoreApplication>
//#include <Book.h>
#include <User.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    User::createUser();

    return a.exec();
}
