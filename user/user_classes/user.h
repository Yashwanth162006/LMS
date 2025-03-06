#ifndef _USER_H_
#define _USER_H_
#include <iostream>
#include "../../account/account.h"
using namespace std;

class User{
protected:
    //attributes
    string name,phoneNumber,userName,password,role,isLoggedIn;
    Account* acc;
public:
    //constructor
    User (string name,string phoneNumber,string userName,string password,string role,string isLoggedIn);
    //getters and setters
    void setName(string name);
    string getName();
    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber();
    void setUserName (string userName);
    string getUserName ();
    void setPassword (string password);
    string getPassword ();
    void setRole(string role);
    string getRole();
    void setIsLoggedIn(string isLoggedIn);
    string getIsLoggedIn();
    //member functions
    void displayDetails();
    bool login(string userName,string password);
    virtual bool borrowBook(string bookId)=0;
    virtual bool returnBook(string bookId)=0;
    virtual void viewTransactionHistory()=0;
    virtual void viewCurrentBorrows()=0;
    virtual void checkFineDetails(){};
    virtual bool payFine(int amount){return true;};
};

#endif