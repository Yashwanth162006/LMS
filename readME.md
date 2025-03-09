# 📚 Library Management System

A comprehensive Library Management System built using **C++** to manage books, users, and transactions. Supports students, faculty, and librarians with essential library functionalities and file-based data persistence.

## 📖 Table of Contents

- [Features](#features)
- [Setup](#setup)
- [Run Instructions](#run-instructions)
- [Data Format](#data-format)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Important Instructions](#️-important-instructions)

**If you are testing this code, please use the data in Books.txt and Users.txt**

## Features

✅ Multi-role support (Students, Faculty, Librarians)  
✅ Book borrowing system with timestamps  
✅ Fine management with payment options  
✅ Easy tracking of overdue books and borrowing history  
✅ Librarian tools for book and user management  
✅ File-based data persistence for secure storage  
✅ Console-based interface with clear navigation

## Setup

1. **Clone the Repository**

```bash
git clone https://github.com/Yashwanth162006/LMS
cd LMS
```

## Run Instructions

Option 1: Compile Using find (Recommended for Linux/Unix)

```bash
g++ $(find . -name "*.cpp") -o main # Compiles all .cpp files
./main                              # Runs the compiled executable
```

Option 2: Compile by Listing Files (Recommended for Windows)

```bash
g++ main.cpp account/account.cpp book/book.cpp library/library.cpp user/user_functions/faculty.cpp user/user_functions/librarian.cpp
user/user_functions/student.cpp user/user_functions/user.cpp helper.cpp main.cpp -o main.exe # Compile all .cpp files
./main                                                                                                   # Runs the compiled executable

```

## Data Format

Title,Author,Publisher,ISBN,Status

**Sample**

```bash
Book1,Author1,Publisher1,ISBN1,Available
```

status can be anything among "Available" and "Borrowed"

Name,phoneNumber,User,Password,Student,Login Status,Previous Transactions Fine

**Sample**

```bash
Book0,Author0,Publisher0,ISBN0,Available
```

UserRole can be anything among "Student","Faculty" and "Librarian"
UserName is the unique identifier for the users

UserName,ISBN,Action,Date

**Sample**

```bash
User1,ISBN2,Borrowed,1741513253395
```

Action can be anything among "Borrowed","Returned"

## Usage

📖 Introduction
The Library Management System is a console-based application designed to efficiently manage library operations for Students, Faculty, and Librarians. It provides a user-friendly interface for borrowing, returning, and tracking books while ensuring data is securely stored using file handling techniques.

🔹 Key Features

- Multi-role access with unique features for Students, Faculty, and Librarians.
- Book borrowing system with timestamps for accurate tracking.
- Fine management system to calculate, track, and allow users to pay fines.
- Librarians can manage book records and user details.
- Data persistence using file handling to ensure all changes are saved automatically.
- Whether you are a student looking to borrow books, a faculty member tracking borrowed resources, or a librarian managing the system, this application simplifies the entire process.

📋 Step-by-Step Instructions

- Run the Program using the commands mentioned in [Run Instructions](#run-instructions) session.
  🔐 Login Instructions
  When you run the application, you'll see the following menu:

  1.  **Enter Username**
  2.  **Enter Password**

💡 **Tip:** Ensure you follow the correct input format to avoid errors.

### 📋 Usage Instructions

**If you are testing, use data from books.csv, users.csv and transactions.csv**

When logged in as a Student, you will see the following menu:

#### 📋 Student Menu Options

- **Enter `1`** to borrow a book
- **Enter `2`** to return a book
- **Enter `3`** to enquire about a book
- **Enter `4`** to view fine
- **Enter `5`** to pay fine
- **Enter `6`** to view history
- **Enter `7`** to view current borrows
- **Enter `8`** to view profile
- **Enter `0`** to exit

When you logged in as Faculty you will see the following menu:

#### 📋 Faculty Menu Options

- **Enter `1`** to borrow a book
- **Enter `2`** to return a book
- **Enter `3`** to enquire about a book
- **Enter `4`** to view history
- **Enter `5`** to view current borrows
- **Enter `6`** to view profile
- **Enter `0`** to exit

When you logged in as a Librarian You will see the following menu:

#### 📋 Librarian Menu Options

- **Enter `1`** to add a new user
- **Enter `2`** to remove a user
- **Enter `3`** to add a book
- **Enter `4`** to remove a book
- **Enter `5`** to view history
- **Enter `0`** to exit

## File Structure

LIBMS/  
├── .vscode/ # VS Code settings folder  
├── 📄 account/  
│ ├── 📄 account.cpp # Account class implementation  
│ └── 📄 account.h # Header file for Account class  
├── 📄 book/  
│ ├── 📄 book.cpp # Book class implementation  
│ └── 📄 book.h # Header file for Book class  
├── 📁 data/ # Data storage files  
│ ├── 📄 books.csv # Sample book data  
│ ├── 📄 transactions.csv # Transaction records  
│ └── 📄 users.csv # Sample user data  
├── 📄 library/  
│ ├── 📄 library.cpp # Library core logic  
│ └── 📄 library.h # Header file for Library class  
├── 📁 user/  
│ ├── 📁 user_classes/ # User classes folder  
│ │ ├── 📄 faculty.h # Header file for Faculty class  
│ │ ├── 📄 librarian.h # Header file for Librarian class  
│ │ ├── 📄 student.h # Header file for Student class  
│ │ └── 📄 user.h # Header file for User class  
│ └── 📁 user_functions/ # User function implementations  
│ ├── 📄 faculty.cpp # Faculty class implementation  
│ ├── 📄 librarian.cpp # Librarian class implementation  
│ ├── 📄 student.cpp # Student class implementation  
│ └── 📄 user.cpp # User class implementation  
├── 📄 helper.cpp # Helper functions implementation  
├── 📄 helper.h # Header file for helper functions  
├── 📄 main.cpp # Entry point of the program  
├── 📄 main.exe # Compiled executable (Windows)  
└── 📄 ReadMe.md # Project documentation

## ⚠️ Important Instructions

Please follow these guidelines to ensure smooth usage and testing of the system:

- ➤ **Enter valid data** to avoid unexpected errors or system crashes.
- ➤ **If you are testing:**
  - Use the data available in **books.csv**, **users.csv** and **transactions.csv**.
  - For **Book IDs**, refer to the **books.csv** or use the **Display Books** command in the interface for correct numbers.
- ➤ **Do not modify the data format** in the `.txt` files directly.
- ➤ Always update or modify data using the **command line interface** to maintain data integrity.
- ➤ UserID is UserName ,BookId is ISBN, every data is stored as a string.

## 📞 Contact

If you have any questions or suggestions, feel free to reach out. I'm happy to help!

📧 **Email:** [yashwanth23@iitk.ac.in](mailto:yashwanth23@iitk.ac.in)
