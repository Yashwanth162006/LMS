#include "../user_classes/faculty.h"
#include "../../account/account.h"
#include <iostream>
using namespace std;

//member functions
bool Faculty::login(string userName,string password){
    if(password == this->password){
        acc = new Account(userName);
        return true;
    }else{
        return false;
    }
}
bool Faculty::borrowBook(string bookId){
    return acc->addBook(bookId);
}
bool Faculty::returnBook(string bookId){
    return acc->removeBook(bookId);
}
 void Faculty::viewBrrowingHistory(){
     acc->viewHistory();
}