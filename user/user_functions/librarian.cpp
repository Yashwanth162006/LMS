#include "../user_classes/librarian.h"
#include "../user_classes/user.h"
#include "../../library/library.h"
#include <iostream>
using namespace std;

//constructor
Librarian::Librarian(string name,string phoneNumber,string userName,string password,string role,string isLoggedIn)
    :User(name,phoneNumber,userName,password,role,isLoggedIn){
}
//member functions
bool Librarian::addUser(string name,string phoneNumber,string userName,string password,string role){
    Library lib;
    lib.loadUsers();
    return lib.addUser(name,phoneNumber,userName,password,role);
}
bool Librarian::deleteUser(string userName){
    Library lib;
    lib.loadUsers();
    return lib.deleteUser(userName);
}
bool Librarian::addBook(string title,string author,string publisher,string ISBN,string status){
    Library lib;
    lib.loadBooks();
    return lib.addBook(title,author,publisher,ISBN,status);
}
bool Librarian::deleteBook(string ISBN){
    Library lib;
    lib.loadBooks();
    return lib.deleteBook(ISBN);
}
void Librarian::viewHistory(){
    Library lib;
    lib.loadTransactions();
    return lib.displayHistory();
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