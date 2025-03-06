#include "../user_classes/faculty.h"
#include "../user_classes/user.h"
#include "../../account/account.h"
#include <iostream>
using namespace std;

//constructor
Faculty::Faculty(string name,string phoneNumber,string userName,string password,string role,string isLoggedIn)
    :User(name,phoneNumber,userName,password,role,isLoggedIn){
}

//member functions
bool Faculty::borrowBook(string bookId){
    return acc->addBook(bookId);
}
bool Faculty::returnBook(string bookId){
    return acc->removeBook(bookId);
}
 void Faculty::viewBrrowingHistory(){
     acc->viewHistory();
}