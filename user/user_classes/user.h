#ifndef _USER_H_
#define _USER_H_
#include <iostream>
using namespace std;

class User{
protected:
    //attributes
    string name,phoneNumber,userName,password,role;
public:
    //constructor
    User (string name,string phoneNumber,string userName,string password,string role);
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
    //member functions
    void displayDetails();
};

#endif