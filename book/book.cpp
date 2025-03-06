#include "book.h"
#include <iostream>
#include "../library/library.h"
using namespace std;

//constructor
Book::Book(string title,string author,string publisher,string ISBN,string status){
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->ISBN = ISBN;
    this->status = status;
}
//member functions
void Book::getDetails(){
    cout<<"ISBN: "<<ISBN<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Publisher: "<<publisher<<endl;
    cout<<"Status: "<<status<<endl;
}
bool Book::updateStatus(string newStatus){
    Library lib2;
    lib2.loadBooks();
    return lib2.updateBookStatus(ISBN,newStatus);
}
bool Book::checkAvailability(){
    if(status=="Available") return true;
    else return false;
}