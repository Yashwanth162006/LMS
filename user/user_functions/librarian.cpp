#include "../user_classes/librarian.h"
#include <iostream>
using namespace std;

bool Librarian::login(string userName,string password){
    if(password == this->password){
        acc = new Account(userName);
        return true;
    }else{
        return false;
    }
}
bool Librarian::addUser(string name,string phoneNumber,string userName,string password,string role){

}
bool Librarian::deleteUser(string userName){

}
bool Librarian::addBook(){

}
bool Librarian::deleteBook(){
    
}