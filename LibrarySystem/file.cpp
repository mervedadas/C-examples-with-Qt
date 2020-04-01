#include "File.h"

File::File(QString name){
    qDebug()<<"file constructor";
    this->file_name=name;
    QFile file(name+".txt");
    if(!file.open(QFile::ReadWrite | QFile::Text)){
        qDebug() << "Could not open file.";
        return;
    }
    else{
        qDebug()<<"File opening"<<endl;
    }
}

void File::readFile(QString name){
    QFile file(name+".txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"file couldnot open and could not read!";
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString bookname = in.readLine();
        QString authorName = in.readLine();
        QString ISBN = in.readLine();
        QString pagenumber = in.readLine();
        QString publishyear = in.readLine();
        QList<QString> keywords = {" ", " "};
        Book b(bookname,authorName,ISBN,pagenumber.toInt(),publishyear.toInt(),keywords);
//        books.append(b);
    }
}

void File::writeFile(QString name, QString u, QString p){
    QFile file(name+".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QTextStream out(&file);
    out << u << endl;
    out << p << endl;

}

void File::writeFile(QString name, QString book_name,QString author_name,QString ISBN,int page_number,int publish_year,QList<QString> keywords)
{
    QFile file(name+".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QTextStream out(&file);
    out<< book_name<< endl;
    out << author_name << endl;
    out << ISBN << endl;
    out << page_number << endl;
    out << publish_year << endl;
    for(int i=0;i<keywords.size();i++)
        out << keywords[i] << " ";

    out << endl;
}

bool File::existingUser(QString name, QString u, QString p){
    QFile file(name+".txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"file could not be opened.";
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
