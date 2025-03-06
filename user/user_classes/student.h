#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include "user.h"
#include "../../account/account.h"
using namespace std;

class Student:public User {
public:
    const static int borrowPeriod = 15;
    const static int booksLimit = 3;
    const static int fineRate = 10;
public:
    //constructor
    Student (string name,string phoneNumber,string userName,string password,string role,string isLoggedIn);
    //member functions
    bool borrowBook(string bookId) override;
    bool returnBook(string bookId) override;
    void checkFineDetails() override;
    bool payFine(int amount) override;
    void viewTransactionHistory() override;
    void viewCurrentBorrows() override;
};

#endif