#include "../user_classes/student.h"
#include "../user_classes/user.h"
#include "../../account/account.h"
#include <iostream>
using namespace std;

//constructor
Student::Student(string name,string phoneNumber,string userName,string password,string role,string isLoggedIn)
    :User(name,phoneNumber,userName,password,role,isLoggedIn){
}
//member functions
bool Student::borrowBook(string bookId){
    return acc->addBook(bookId);
}
bool Student::returnBook(string bookId){
    return acc->removeBook(bookId);
}
void Student::checkFineDetails(){
    acc->checkFine();
}
bool Student::payFine(int amount){
    return acc->payFine(amount);
}
void Student::viewTransactionHistory(){
     acc->viewHistory();
}
void Student::viewCurrentBorrows(){
    acc->viewCurrBorrows();
}