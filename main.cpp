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

int main(){
    cout<<"-------------------------------"<<endl;
    cout<<"Welcome To Yashwanth RJ Library"<<endl;
    cout<<"-------------------------------"<<endl;
    Library lib;
    bool isLibOpen = openLibrary(lib);
    if(isLibOpen){
        cout<<"Library Loaded Successfully"<<endl;
        cout<<endl;
        cout<<"-------------------------------"<<endl;
    }
    string userIn;
    while(1){
        cout<<"Enter username: ";
        cin>>userIn;
        if(userIn=="close") break;
        User* user = lib.identifyUser(userIn);
    
        if(user==nullptr){
            cout<<"User Not Found"<<endl;
        }else{
            if(user->getIsLoggedIn()=="No"){
                authenticate(user,userIn);
                if(user->getIsLoggedIn()=="No") break;
                cout<<endl;
                cout<<"Hello "<<user->getName()<<endl;
                cout<<endl;
            }
            int op;
            if(user->getRole()=="Student"){
                displayStudentPrompts();
                while(1){
                    cout<<"Enter Option: ";
                    cin>>op;
                    if(op==0) break;
                    processStudentRequest(user,op,lib);
                }
            }else if(user->getRole()=="Faculty"){
                displayFacultyPrompts();
                while(1){
                    cout<<"Enter Option: ";
                    cin>>op;
                    if(op==0) break;
                    processFacultyRequest(user,op,lib);
                }
            }else if(user->getRole()=="Librarian"){
                displayLibrarianPrompts();
                while(1){
                    cout<<"Enter Option: ";
                    cin>>op;
                    if(op==0) break;
                    processLibrarianRequest(user,op,lib);
                }
            }
        }
    }
}