#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <list>
using namespace std;

class Account {
private:
    string accountId;
    string role;
    list<string> currBorrows;
    list<string> borrowingHistory;
    int totalFine;
public:
    //constructor
    Account(string userName);
    //member functions
    bool addBook(string bookId);
    bool removeBook(string bookId);
    void checkFine();
    bool payFine(int amount);
    void viewHistory();
};

#endif