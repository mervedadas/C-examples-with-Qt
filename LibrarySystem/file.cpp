#include <QDebug>
#include "File.h"
#include "Book.h"
#include "User.h"

QString File::getFile_name() const
{
    return file_name;
}

File::File(QString name){
    this->file_name=name;
    File *f = new File(name);

    QFile file(f->getFile_name()+".txt");
    if(!file.open(QFile::ReadWrite | QFile::Text)){
        qDebug() << "Could not open file.";
        return;
    }
    else{
        qDebug()<<"File opening"<<endl;
    }

}

QList<Book> File::readFile(File f){
      QFile file(f.getFile_name()+".txt");
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        qDebug()<<"file could not open and could not read!";
//    }
    QList<Book> all;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString bookname = in.readLine();
        QString authorName = in.readLine();
        QString ISBN = in.readLine();
        QString pagenumber = in.readLine();
        QString publishyear = in.readLine();
        QString keywors = in.readLine();
        QList<QString> keywords;
        auto parts = keywors.split(',');
        keywords =parts;
        Book b(bookname,authorName,ISBN,pagenumber.toInt(),publishyear.toInt(),keywords);
        all.append(b);
    }
    return all;
}


void File::writeFileU(User u){
    QFile file(this->file_name+".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QTextStream out(&file);
    out << u.getUsername() << endl;
    out << u.getPassword() << endl;

}

void File::writeFileB(File f, Book b)
{
    QFile file(f.getFile_name()+".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
        return;
    QTextStream out(&file);
    out<< b.getBook_name()<< endl;
    out << b.getAuthor_name() << endl;
    out << b.getISBN() << endl;
    out << b.getPage_number() << endl;
    out << b.getPublish_year() << endl;
    for(int i=0;i<b.getKeywords().size();i++)
        out << (b.getKeywords())[i] << " ";
    out << endl;
}

void File::writeFile(File f,const QList<Book> all)
{    QFile file(f.getFile_name()+".txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;
     QTextStream out(&file);
      for(int i=0;i<all.size();i++){
     out<< all[i].getBook_name()<< endl;
     out << all[i].getAuthor_name() << endl;
     out << all[i].getISBN() << endl;
     out << all[i].getPage_number() << endl;
     out << all[i].getPublish_year() << endl;
     for(int k=0;i<(all[i].getKeywords()).size();k++)
         out << (all[i].getKeywords())[k]<< " ";
     out << endl;
    }


}

bool File::existingUser(File f, User u){
    QFile file(f.getFile_name()+".txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"file could not be opened.";
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString username = in.readLine();
        QString password = in.readLine();
        if(username == u.getUsername() && password==u.getPassword())
            return true;
    }
    return false;
}
