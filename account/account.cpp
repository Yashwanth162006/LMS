#include "account.h"
#include "../library/library.h"
#include "../user/user_classes/student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;

//helper functions
list<pair<string,long long>> filterHistory(list<list<string>>& transactionHistory,string userName){
    list<pair<string,long long>> borrows;
    for(auto it=transactionHistory.begin();it!=transactionHistory.end();it++){
        auto nameIt = it->begin();
        nameIt++;nameIt++;
        if(*(nameIt)=="Borrowed"){
            nameIt--;
            auto date = it->end();date--;
            borrows.push_back({*(nameIt),stoll(*(date))});
        }else{
            nameIt--;
            for(auto it1=borrows.begin();it1!=borrows.end();it1++){
                if((*it1).first == *(nameIt)) borrows.remove({(*it1).first,(*it1).second});
            }
        }
    }
    return borrows;
}
void convertMillisecondsToDateTime(long long milliseconds) {
    time_t seconds = milliseconds / 1000;
    tm* localTime = localtime(&seconds);
    cout << "Date-Time: " << put_time(localTime, "%Y-%m-%d %H:%M:%S") << endl;
}
long long getCurrentTimeInMilliseconds() {
    auto now = chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
    return milliseconds;
}
int calculateFine(list<pair<string,long long>>& currBorrows){
    int sum=0;
    int fineRate = Student::fineRate;
    for(auto it=currBorrows.begin();it!=currBorrows.end();it++){
        long long borrowInstance = (*it).second;
        long long currInstance = getCurrentTimeInMilliseconds();
        long long diff = currInstance-borrowInstance;
        long long borrowPeriod = static_cast<long long>(Student::borrowPeriod) * 24 * 60 * 60 * 1000;
        if(diff > borrowPeriod){
            sum += fineRate*((diff-borrowPeriod)/8640000);
        }
    }
    return sum;
}
//constructor
Account::Account(string userName,string role){
    //username
    this->userName = userName;
    //role
    this->role = role;
    Library lib1;
    lib1.loadUsers();
    //transaction history
    bool isHistoryLoaded = lib1.loadTransactions();
    if(isHistoryLoaded) transactionHistory = lib1.getHistory(userName);
    //current borrows
    currBorrows = filterHistory(transactionHistory,userName);
    //total fine
    if(role=="Faculty" || role=="Librarian") totalFine=0;
    else totalFine = calculateFine(currBorrows)+lib1.getFine(userName);
}
//getters and setters
list<pair<string,long long>> Account::getCurrBorrows(){
    return currBorrows;
}
//member functions
bool Account::addBook(string bookId){
    if(role=="Student"){
        if(totalFine>0){
            cout<<"Clear the pending fine to borrow"<<endl;
            return false;
        }else if(currBorrows.size()==3){
            cout<<"You have reached the maximum limit"<<endl;
            return false;
        }else{
            Library lib;
            lib.loadBooks();
            Book* book = lib.identifyBook(bookId);
            book->updateStatus("Unavailable");
            lib.updateBookStatus(bookId,"Unavailable");
            list<string> transaction;
            transaction.push_back(userName);transaction.push_back(bookId);
            transaction.push_back("Borrowed");transaction.push_back(to_string(getCurrentTimeInMilliseconds()));
            currBorrows.push_back({bookId,getCurrentTimeInMilliseconds()});
            transactionHistory.push_back(transaction);
            return lib.addTransaction(transaction);
        }
    }else if(role=="Faculty"){
        if(currBorrows.size()==5){
            cout<<"You have reached the maximum limit"<<endl;
            return false;
        }else{
            return true;
        }
    }
    return false;
}
bool Account::removeBook(string bookId){
    if(role=="Student"){
        return true;
    }else if(role=="Faculty"){
        return true;
    }
    return false;
}
void Account::checkFine(){
    cout<<"Your Total Fine is: "<<totalFine<<endl;
}
bool Account::payFine(int amount){
    if(amount>=totalFine){
        return false;
    }else{
        totalFine -= amount;
        return true;
    }
}
void Account::viewHistory(){
    for(auto it=transactionHistory.begin();it!=transactionHistory.end();it++){
        int index=0;
        for(auto innerIt=it->begin();innerIt!=it->end();innerIt++,index++){
            if(index!=3)cout<<*(innerIt)<<" ";
            else convertMillisecondsToDateTime(stoll(*(innerIt)));
        }
    }
}
void Account::viewCurrBorrows(){
    for(auto it=currBorrows.begin();it!=currBorrows.end();it++){
        cout<<(*it).first<<" ";
        convertMillisecondsToDateTime((*it).second);
    }
}