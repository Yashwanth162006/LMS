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
    bool addUser(string name,string phoneNumber,string userName,string password,string role);
    bool deleteUser(string userName);
    bool addBook();
    bool deleteBook();
};

#endif