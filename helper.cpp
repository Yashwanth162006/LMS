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