#ifndef _LIBRARIAN_H_
#define _LIBRARIAN_H_
#include <iostream>
#include "../../account/account.h"
#include "user.h"
using namespace std;

class Librarian: public User {
public:
    //constructor
    Librarian (string name,string phoneNumber,string userName,string password,string role,string isLoggedIn);
    //member functions
    bool addUser(string name,string phoneNumber,string userName,string password,string role) override;
    bool deleteUser(string userName) override;
    bool addBook(string title,string author,string publisher,string ISBN,string status) override;
    bool deleteBook(string ISBN) override;
    void viewHistory() override;
    bool borrowBook(string bookId) override;
    bool returnBook(string bookId) override;
    void viewTransactionHistory() override;
    void viewCurrentBorrows() override;
};

#endif