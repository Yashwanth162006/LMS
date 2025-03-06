#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include <iostream>
#include <list>
#include <vector>
#include "../user/user_classes/user.h"
#include "../user/user_classes/student.h"
#include "../user/user_classes/faculty.h"
#include "../user/user_classes/librarian.h"
using namespace std;

class Library {
private:
    list<list<string>> books;
    list<list<string>> users;
    list<list<string>> history;
public:
    //constructor
    Library();
    //getters and setters
    void setBooks(list<list<string>> books);
    list<list<string>> getBooks();
    void setUsers(list<list<string>> users);
    list<list<string>> getUsers();
    void setHistory(list<list<string>> history);
    list<list<string>> getHistory();
    list<list<string>> getHistory(string userName);
    //member functions
    //users
    bool addUser(string name,string phoneNumber,string userName,string password,string role);
    bool deleteUser(string userName);
    bool loadUsers();
    void displayUsers();
    User* identifyUser(string userName);
    //books
    bool addBook();
    bool deleteBook();
    bool loadBooks();
    void displayBooks();
    //history
    bool addTransaction();
    bool loadTransactions();
    void displayHistory();
};

#endif