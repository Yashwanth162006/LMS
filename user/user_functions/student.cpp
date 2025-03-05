#include "../user_classes/student.h"
#include "../../account/account.h"
#include <iostream>
using namespace std;

//member functions
bool Student::login(string userName,string password){
    if(password == this->password){
        acc = new Account(userName);
        return true;
    }else{
        return false;
    }
}
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
 void Student::viewBrrowingHistory(){
     acc->viewHistory();
}