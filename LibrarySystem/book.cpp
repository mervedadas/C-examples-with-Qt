#include "Book.h"


void bubbleSort(int arr[],int n);

Book::Book(QString book_name,QString author_name,QString ISBN,int page_number,int publish_year,QList<QString> keywords){
    qDebug()<<"Object created";
    this->book_name=book_name;
    this->author_name=author_name;
    this->ISBN=ISBN;
    this->page_number=page_number;
    this->publish_year=publish_year;
    this->keywords = keywords;
}

void Book::printBook(){
    qDebug()<<"Book Name:" << this->book_name;
    qDebug()<<"Author Name: " <<this->author_name;
    qDebug()<<"ISBN: " <<this->ISBN;
    qDebug()<< "Page Number: "<<this->page_number;
    qDebug()<< "Publish Year: "<<this->publish_year;
    qDebug()<< "Keywords: "<< this->keywords;
}

void Book::addBook(){
    QString book_name;
    QString author_name;
    QString ISBN;
    int page_number;
    int publish_year;
    QList<QString> keywords;

    qDebug()<<"Please Enter Book information";
    qDebug()<<"Book Name: ";

    QTextStream b_name(stdin);
    book_name = b_name.readLine();

    qDebug()<<"Author Name: ";
    QTextStream a_name(stdin);
    author_name = a_name.readLine();

    qDebug() <<"ISBN(Should be 9 digits): ";
    QTextStream isbn(stdin);
    ISBN = isbn.readLine();

    qDebug() <<"Page Number: ";
    std::cin>>page_number;


    qDebug()<<endl<<"Publish Year";
    std::cin>>publish_year;

    qDebug()<<"Book' Keywords";
    QTextStream kw(stdin);
    keywords.append(kw.readLine());

    Book b(book_name,author_name,ISBN,page_number,publish_year,keywords);
//    books.append(b);
   // displayAllBooks();
//    File::writeFile("Book",book_name,author_name,ISBN,page_number,publish_year,keywords);

}

void Book::deleteBook(){
    QString book_name;
    qDebug()<<"Please enter book name that want to delete";
    QTextStream b_name(stdin);
    book_name = b_name.readLine();

//    for(int i =0;i<(books).size();i++){
//        if(books[i].book_name==book_name){
//            books.removeAt(i);
//        }
//    }
}

void Book::sortBook(const QList<Book> b){
    int arr[b.size()];
    for (int i =0; i<b.size();i++){
       arr[i]= b[i].publish_year;
       qDebug()<<b[i].book_name << b[i].publish_year;
    }
    bubbleSort(arr,b.size());
}

void Book::displayAllBooks(){

//    qDebug()<<"book size"<<books.size();
//    for (int i =0; i<books.size();i++){
//        books[i].printBook();
//    }
}

void bubbleSort(int arr[],int n){
   int temp;
        for(int i =0; i < n;++i){
            for(int k=0;k<n;++k){
                if(arr[i]<arr[k]){
                  temp=arr[i];
                  arr[i]=arr[k];
                  arr[k]=temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            qDebug()<<arr[i];
        }
        qDebug();

}
