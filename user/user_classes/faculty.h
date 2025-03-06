#ifndef _FACULTY_H_
#define _FACULTY_H_
#include <iostream>
#include "user.h"
#include "../../account/account.h"
using namespace std;

class Faculty:public User {
private:
    const static int borrowPeriod = 30;
    const static int overDuePeriod = 60;
    const static int booksLimit = 5;
public:
    //constructor
    Faculty (string name,string phoneNumber,string userName,string password,string role,string isLoggedIn);
    bool borrowBook(string bookId) override;
    bool returnBook(string bookId) override;
    void viewTransactionHistory() override;
    void viewCurrentBorrows() override;
};

#endif