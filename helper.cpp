#include <iostream>
#include <vector>
#include "./library/library.h"
#include "./account/account.h"
#include "./user/user_classes/user.h"
#include "./user/user_classes/student.h"
#include "./user/user_classes/faculty.h"
#include "./user/user_classes/librarian.h"
#include "helper.h"
using namespace std;

bool openLibrary(Library& lib){
    if(!lib.loadUsers()){
        cout<<"Failed To Load Users"<<endl;
        return false;
    }
    if(!lib.loadBooks()){
        cout<<"Failed To Load Books";
        return false;
    }
    if(!lib.loadTransactions()){
        cout<<"Failed To Load History";
        return false;
    }
    return true;
}
void authenticate(User* user,string& userIn){
    for(int i=0;i<3;i++){
        if(i==2) cout<<"Last Chance"<<endl;
        cout<<"Enter Password: ";
        cin>>userIn;
        if(user->login(user->getUserName(),userIn)){
            cout<<"Logged In"<<endl;
            break;
        }else{
            cout<<"Wrong password"<<endl;
            if(i!=2) cout<<"Try Again"<<endl;
        }
    }
}
void displayStudentPrompts(){
    cout<<endl;
    cout<<"What do you want to do ?"<<endl;
    cout<<endl;
    cout<<"1) To borrow a book enter 1"<<endl;
    cout<<"2) To return a book enter 2"<<endl;
    cout<<"3) To view fine enter 3"<<endl;
    cout<<"4) To pay fine enter 4"<<endl;
    cout<<"5) To view history enter 5"<<endl;
    cout<<"6) To view current borrows enter 6"<<endl;
    cout<<"7) To view your profile enter 7"<<endl;
    cout<<"8) Enter 0 to exit"<<endl;
    cout<<endl;
}
void processStudentRequest(User* user,int op){
    if(op==1){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        bool borrowResult = user->borrowBook(bookId);
    }else if(op==2){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        bool returnResult = user->returnBook(bookId);
    }else if(op==3){
        user->checkFineDetails();
    }else if(op==4){
        int amount=0;
        user->checkFineDetails();
        cout<<"Enter valid amount: ";cin>>amount;
        if(user->payFine(amount)) cout<<"Payment Successful"<<endl;
        else cout<<"Entered amount is more that your total fine try again"<<endl;
        user->checkFineDetails();
    }
    else if(op==5){
        user->viewTransactionHistory();
    }else if(op==6){
        user->viewCurrentBorrows();
    }else if(op==7){
        user->displayDetails();
    }
}
void displayFacultyPrompts(){
    cout<<endl;
    cout<<"What do you want to do ?"<<endl;
    cout<<endl;
    cout<<"1) To borrow a book enter 1"<<endl;
    cout<<"2) To return a book enter 2"<<endl;
    cout<<"3) To view history enter 3"<<endl;
    cout<<"4) To view current borrows enter 4"<<endl;
    cout<<"5) To view your profile enter 5"<<endl;
    cout<<"6) Enter 0 to exit"<<endl;
    cout<<endl;
}
void processFacultyRequest(User* user,int op){
    if(op==1){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        bool borrowResult = user->borrowBook(bookId);
    }else if(op==2){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        bool returnResult = user->returnBook(bookId);
    }else if(op==3){
        user->viewTransactionHistory();
    }else if(op==4){
        user->viewCurrentBorrows();
    }else if(op==5){
        user->displayDetails();
    }
}
void displayLibrarianPrompts(){
    cout<<endl;
    cout<<"What do you want to do ?"<<endl;
    cout<<endl;
    cout<<"1) To add a user enter 1"<<endl;
    cout<<"2) To delete a user enter 2"<<endl;
    cout<<"3) To add a book enter 3"<<endl;
    cout<<"4) To delete a book enter 4"<<endl;
    cout<<"5) To view history enter 5"<<endl;
    cout<<"6) To view your profile enter 6"<<endl;
    cout<<"7) Enter 0 to exit"<<endl;
    cout<<endl;
}
void processLibrarianRequest(User* user,int op){
    
}