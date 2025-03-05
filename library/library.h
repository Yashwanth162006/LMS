#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include <iostream>
#include <list>
using namespace std;

class Library {
private:
    list<list<string>> books;
    list<list<string>> users;
    list<list<string>> history;
public:
    //constructor
    Library();
    //member functions
    bool addUser(string name,string phoneNumber,string userName,string password,string role);
    bool deleteUser(string userName);
    bool addBook();
    bool deleteBook();
    bool addTransaction();
    bool loadUsers();
    bool loadBooks();
    bool loadTransactions();
};

#endif