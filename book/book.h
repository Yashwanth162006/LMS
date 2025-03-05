#ifndef _BOOK_H_
#define _BOOK_H_
#include <iostream>
using namespace std;

class Book {
private:
    string title,author,publisher,ISBN,status;
public:
    //constructor
    Book (string title,string author,string publisher,string ISBN,string status);
    //member functions
    void getDetails();
    bool updateStatus(string newStatus);
    bool checkAvailability();
};

#endif