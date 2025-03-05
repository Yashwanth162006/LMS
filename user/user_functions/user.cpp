#include "../user_classes/user.h"
#include <iostream>
using namespace std;

//constructor
User::User(string name,string phoneNumber,string userName,string password,string role){
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->userName = userName;
    this->password = password;
    this->role = role;
}
//getters and setters
void User::setName(string name) {
    this->name = name;
}
string User::getName() {
    return name;
}
void User::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
string User::getPhoneNumber() {
    return phoneNumber;
}
void User::setUserName(string userName) {
    this->userName = userName;
}
string User::getUserName() {
    return userName;
}
void User::setPassword(string password) {
    this->password = password;
}
string User::getPassword() {
    return password;
}
void User::setRole(string role){
    this->role = role;
}
string User::getRole(){
    return role;
}
//member functions
void User::displayDetails(){
    cout<<"Username: "<<userName<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Role: "<<role<<endl;
    cout<<"Phone Number: "<<phoneNumber<<endl;
}