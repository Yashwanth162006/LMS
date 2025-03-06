#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <list>
using namespace std;

class Account {
private:
    string userName;
    string role;
    list<pair<string,long long>> currBorrows;
    list<list<string>> transactionHistory;
    int totalFine;
public:
    //constructor
    Account(string userName,string role);
    //setters and getters
    list<pair<string,long long>> getCurrBorrows();
    //member functions
    bool addBook(string bookId);
    bool removeBook(string bookId);
    void checkFine();
    bool payFine(int amount);
    void viewHistory();
    void viewCurrBorrows();
};

#endif