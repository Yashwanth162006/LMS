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
    Account* acc;
public:
    bool login(string userName,string password);
    bool borrowBook(string bookId);
    bool returnBook(string bookId);
    void viewBrrowingHistory();
};

#endif