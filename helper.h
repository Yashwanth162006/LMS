#ifndef _HELPER_H_
#define _HELPER_H_

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

bool openLibrary(Library& lib);
void authenticate(User* user,string& userIn);
void displayStudentPrompts();
void displayFacultyPrompts();
void displayLibrarianPrompts();
void processStudentRequest(User* user,int op);
void processFacultyRequest(User* user,int op);
void processLibrarianRequest(User* user,int op,Library& lib);
#endif