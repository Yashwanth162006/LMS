#include "library.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

//constructor
Library::Library(){

}
//getters and setters
void Library::setBooks(list<list<string>> books){
    this->books = books;
}
list<list<string>> Library::getBooks(){
    return books;
}
void Library::setUsers(list<list<string>> users){
    this->users = users;
}
list<list<string>> Library::getUsers(){
    return users;
}
void Library::setHistory(list<list<string>> history){
    this->history = history;
}
list<list<string>> Library::getHistory(){
    return history;
}
list<list<string>> Library::getHistory(string userName){
    list<list<string>> userHistory;
    for(auto it=history.begin();it!=history.end();it++){
        auto nameIt = it->begin();
        if(*(nameIt)==userName){
            list<string> hist;
            for(auto innerIt=it->begin();innerIt!=it->end();innerIt++){
                hist.push_back(*(innerIt));
            }
            userHistory.push_back(hist);
        }
    }
    return userHistory;
}
//member functions
bool Library::addUser(string name,string phoneNumber,string userName,string password,string role){
    return true;
}
bool Library::deleteUser(string userName){
    return true;
}
bool Library::addBook(){
    return true;
}
bool Library::deleteBook(){
    return true;
}
bool Library::addTransaction(){
    return true;
}
User* Library::identifyUser(string userName){
    vector<string> userDetails;
    for(auto it=users.begin();it!=users.end();it++){
        auto nameIt = it->begin();
        nameIt++;nameIt++;
        if(*(nameIt)==userName){
            for(auto innerIt=it->begin();innerIt!=it->end();innerIt++){
                userDetails.push_back(*(innerIt));
            }
        }
    }
    if(userDetails.size()==0) return nullptr;
    else if(userDetails[4]=="Student") return new Student(userDetails[0],userDetails[1],userDetails[2],userDetails[3],userDetails[4],userDetails[5]);
    else if(userDetails[4]=="Faculty") return new Faculty(userDetails[0],userDetails[1],userDetails[2],userDetails[3],userDetails[4],userDetails[5]);
    else if(userDetails[4]=="Librarian") return new Librarian(userDetails[0],userDetails[1],userDetails[2],userDetails[3],userDetails[4],userDetails[5]);
    else return nullptr;
}
//Loading Data
bool Library::loadUsers(){
    ifstream readUsers("./data/users.csv");
    if(!readUsers.is_open()) return false;
    string name,phoneNumber,userName,password,role,isLoggedIn;
    string line;
    while(getline(readUsers,line,'\n')){
        list<string> user;
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,phoneNumber,',');
        getline(ss,userName,',');
        getline(ss,password,',');
        getline(ss,role,',');
        getline(ss,isLoggedIn,'\n');
        user.push_back(name);user.push_back(phoneNumber);user.push_back(userName);
        user.push_back(password);user.push_back(role);user.push_back(isLoggedIn);
        users.push_back(user);
    }
    readUsers.close();
    return true;
}
bool Library::loadBooks(){
    ifstream readBooks("./data/books.csv");
    if(!readBooks.is_open()) return false;
    string title,author,publisher,ISBN,status;
    string line;
    while(getline(readBooks,line,'\n')){
        list<string> book;
        stringstream ss(line);
        getline(ss,title,',');
        getline(ss,author,',');
        getline(ss,publisher,',');
        getline(ss,ISBN,',');
        getline(ss,status,'\n');
        book.push_back(title);book.push_back(author);book.push_back(publisher);book.push_back(ISBN);book.push_back(status);
        books.push_back(book);
    }
    readBooks.close();
    return true;
}
bool Library::loadTransactions(){
    ifstream readHistory("./data/transactions.csv");
    if(!readHistory.is_open()) return false;
    string userName,ISBN,action,date;
    string line;
    while(getline(readHistory,line,'\n')){
        list<string> hist;
        stringstream ss(line);
        getline(ss,userName,',');
        getline(ss,ISBN,',');
        getline(ss,action,',');
        getline(ss,date,'\n');
        hist.push_back(userName);hist.push_back(ISBN);hist.push_back(action);hist.push_back(date);
        history.push_back(hist);
    }
    readHistory.close();
    return true;
}
void Library::displayUsers(){
    for(auto it=users.begin();it!=users.end();it++){
        for(auto innerIt=it->begin();innerIt!=it->end();innerIt++){
            cout<<*(innerIt)<<" ";
        }
        cout<<endl;
    }
}
void Library::displayBooks(){
    for(auto it=books.begin();it!=books.end();it++){
        for(auto innerIt=it->begin();innerIt!=it->end();innerIt++){
            cout<<*(innerIt)<<" ";
        }
        cout<<endl;
    }
}
void Library::displayHistory(){
    for(auto it=history.begin();it!=history.end();it++){
        for(auto innerIt=it->begin();innerIt!=it->end();innerIt++){
            cout<<*(innerIt)<<" ";
        }
        cout<<endl;
    }
}