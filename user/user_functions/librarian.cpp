#include "../user_classes/librarian.h"
#include "../user_classes/user.h"
#include <iostream>
using namespace std;

//constructor
Librarian::Librarian(string name,string phoneNumber,string userName,string password,string role,string isLoggedIn)
    :User(name,phoneNumber,userName,password,role,isLoggedIn){
}
//member functions
bool Librarian::addUser(string name,string phoneNumber,string userName,string password,string role){
    return true;
}
bool Librarian::deleteUser(string userName){
    return true;
}
bool Librarian::addBook(){
    return true;
}
bool Librarian::deleteBook(){
    return true;
}
void Librarian::viewHistory(){

}
bool Librarian::borrowBook(string bookId){
    //Not available for librarian
    return false;
}
bool Librarian::returnBook(string bookId){
    //Not available for librarian
    return false;
}
void Librarian::viewTransactionHistory(){
    //Not available for librarian
}
void Librarian::viewCurrentBorrows(){
    //Not available for librarian
}