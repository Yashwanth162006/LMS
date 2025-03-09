#include <iostream>
#include <vector>
#include "./library/library.h"
#include "./account/account.h"
#include "./user/user_classes/user.h"
#include "./user/user_classes/student.h"
#include "./user/user_classes/faculty.h"
#include "./user/user_classes/librarian.h"
#include "./book/book.h"
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
            cout<<"-------------------------------"<<endl;
            break;
        }else{
            cout<<"Wrong password"<<endl;
            if(i!=2) cout<<"Try Again"<<endl;
        }
    }
}
void displayStudentPrompts(){
    cout<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"What do you want to do ?"<<endl;
    cout<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1) To borrow a book enter 1"<<endl;
    cout<<"2) To return a book enter 2"<<endl;
    cout<<"3) To enquire about a book enter 3"<<endl;
    cout<<"4) To view fine enter 4"<<endl;
    cout<<"5) To pay fine enter 5"<<endl;
    cout<<"6) To view history enter 6"<<endl;
    cout<<"7) To view current borrows enter 7"<<endl;
    cout<<"8) To view your profile enter 8"<<endl;
    cout<<"9) Enter 0 to exit"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<endl;
}
void processStudentRequest(User* user,int op,Library& lib){
    if(op==1){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        lib.loadBooks();
        Book* book = lib.identifyBook(bookId);
        if(book == nullptr) cout<<"Invalid ISBN number"<<endl;
        else if(book->checkAvailability()){
            bool borrowResult = user->borrowBook(bookId);
            if(borrowResult) cout<<"Scuccessfully borrowed"<<endl;
            else cout<<"Error: failed to borrow"<<endl;
        }
        else cout<<"Book is unavailable"<<endl;
        lib.loadBooks();
        lib.loadTransactions();
    }else if(op==2){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        lib.loadBooks();
        Book* book = lib.identifyBook(bookId);
        if(book==nullptr) cout<<"Invalid ISBN number"<<endl;
        bool returnResult = user->returnBook(bookId);
        if(returnResult) cout<<"Returned Succesfully"<<endl;
        else cout<<"Error: Returning the book"<<endl;
        lib.loadBooks();
        lib.loadTransactions();
    }else if(op==3){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        lib.loadBooks();
        Book* book = lib.identifyBook(bookId);
        if(book == nullptr) cout<<"Invalid ISBN number"<<endl;
        else book->getDetails();
    }else if(op==4){
        user->checkFineDetails();
    }else if(op==5){
        int amount=0;
        user->checkFineDetails();
        cout<<"Enter valid amount: ";cin>>amount;
        if(user->payFine(amount)) cout<<"Payment Successful"<<endl;
        else cout<<"Entered amount is more that your total fine try again"<<endl;
        user->checkFineDetails();
    }
    else if(op==6){
        user->viewTransactionHistory();
    }else if(op==7){
        user->viewCurrentBorrows();
    }else if(op==8){
        user->displayDetails();
    }
}
void displayFacultyPrompts(){
    cout<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"What do you want to do ?"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<endl;
    cout<<"1) To borrow a book enter 1"<<endl;
    cout<<"2) To return a book enter 2"<<endl;
    cout<<"3) To enquire about a book enter 3"<<endl;
    cout<<"4) To view history enter 4"<<endl;
    cout<<"5) To view current borrows enter 5"<<endl;
    cout<<"6) To view your profile enter 6"<<endl;
    cout<<"7) Enter 0 to exit"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<endl;
}
void processFacultyRequest(User* user,int op,Library& lib){
    if(op==1){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        lib.loadBooks();
        Book* book = lib.identifyBook(bookId);
        if(book == nullptr) cout<<"Invalid ISBN number"<<endl;
        else if(book->checkAvailability()){
            bool borrowResult = user->borrowBook(bookId);
            if(borrowResult) cout<<"Scuccessfully borrowed"<<endl;
            else cout<<"Error: failed to borrow"<<endl;
        }
        else cout<<"Book is unavailable"<<endl;
        lib.loadBooks();
        lib.loadTransactions();
    }else if(op==2){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        lib.loadBooks();
        Book* book = lib.identifyBook(bookId);
        if(book==nullptr) cout<<"Invalid ISBN number"<<endl;
        bool returnResult = user->returnBook(bookId);
        if(returnResult) cout<<"Returned Succesfully"<<endl;
        else cout<<"Error: Returning the book"<<endl;
        lib.loadBooks();
        lib.loadTransactions();
    }else if(op==3){
        string bookId;
        cout<<"Enter ISBN number: ";
        cin>>bookId;
        Book* book = lib.identifyBook(bookId);
        if(book == nullptr) cout<<"Invalid ISBN number"<<endl;
        else book->getDetails();
    }
    else if(op==4){
        user->viewTransactionHistory();
    }else if(op==5){
        user->viewCurrentBorrows();
    }else if(op==6){
        user->displayDetails();
    }
}
void displayLibrarianPrompts(){
    cout<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"What do you want to do ?"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<endl;
    cout<<"1) To add a user enter 1"<<endl;
    cout<<"2) To delete a user enter 2"<<endl;
    cout<<"3) To add a book enter 3"<<endl;
    cout<<"4) To delete a book enter 4"<<endl;
    cout<<"5) To view history enter 5"<<endl;
    cout<<"6) To view all books enter 6"<<endl;
    cout<<"7) To view all users enter 7"<<endl;
    cout<<"8) To view your profile enter 8"<<endl;
    cout<<"9) To exit enter 0"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<endl;
}
void processLibrarianRequest(User* user,int op,Library& lib){
    if(op==1){
        vector<string> details;
        vector<string> prompts;
        prompts.push_back("Enter name: ");prompts.push_back("Enter Phone Number: ");prompts.push_back("Enter username: ");
        prompts.push_back("Enter password: ");prompts.push_back("Enter role: ");
        string userIn;
        for(int i=0;i<5;i++){
            if(i!=2){
                cout<<prompts[i];
                cin>>userIn;
            }
            else{
                User* user1;
                while(1){
                    cout<<prompts[2];
                    cin>>userIn;
                    user1 = lib.identifyUser(userIn);
                    if(user1==nullptr) break;
                    cout<<"Username not available"<<endl;
                }
            }
            details.push_back(userIn);
        }
        for(int i=0;i<5;i++){
            char c=',';
            if(i==4) c='\n';
            cout<<details[i]<<c;
        }
        cout<<endl;
        if(user->addUser(details[0],details[1],details[2],details[3],details[4])){
            cout<<"User added"<<endl;
        }else{
            cout<<"Failed to add user"<<endl;
        }
    }else if(op==2){
        string userIn;
        while(1){
            cout<<"Enter username: ";
            cin>>userIn;
            User* user1 = lib.identifyUser(userIn);
            if(user1!=nullptr) break;
            cout<<"User does not exist"<<endl;
            cout<<endl;
        }
        if(user->deleteUser(userIn)){
            cout<<"User Deleted"<<endl<<endl;
        }else{
            cout<<"Failed to delete user"<<endl<<endl;
        }
    }else if(op==3){
        vector<string> details;
        vector<string> prompts;
        prompts.push_back("Enter title: ");prompts.push_back("Enter author: ");prompts.push_back("Enter publisher: ");
        prompts.push_back("Enter ISBN: ");prompts.push_back("Enter status: ");
        string userIn;
        for(int i=0;i<5;i++){
            if(i!=3){
                cout<<prompts[i];
                cin>>userIn;
            }
            else{
                Book* book1;
                while(1){
                    cout<<prompts[3];
                    cin>>userIn;
                    book1 = lib.identifyBook(userIn);
                    if(book1==nullptr) break;
                    cout<<"ISBN not available"<<endl;
                }
            }
            details.push_back(userIn);
        }
        for(int i=0;i<5;i++){
            char c=',';
            if(i==4) c='\n';
            cout<<details[i]<<c;
        }
        cout<<endl;
        if(user->addBook(details[0],details[1],details[2],details[3],details[4])){
            cout<<"Book added"<<endl;
        }else{
            cout<<"Failed to add book"<<endl;
        }
    }else if(op==4){
        string userIn;
        while(1){
            cout<<"Enter ISBN: ";
            cin>>userIn;
            Book* book1 = lib.identifyBook(userIn);
            if(book1!=nullptr) break;
            cout<<"Book does not exist"<<endl;
            cout<<endl;
        }
        if(user->deleteBook(userIn)){
            cout<<"Book Deleted"<<endl<<endl;
        }else{
            cout<<"Failed to delete book"<<endl<<endl;
        }
    }else if(op==5){
        user->viewHistory();
    }else if(op==6){
        lib.displayBooks();
    }else if(op==7){
        lib.displayUsers();
    }
    else if(op==8){
        user->displayDetails();
    }
}