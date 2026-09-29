// MY_LIBRARY (HPP) - Leng Panhaleap 
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
using namespace std;

const int MAX_ITEMS = 100;

struct Book {
    string title;
    string author;
    string ISBN;
    int quantity;
};

struct Borrower {
    string name;
    string ID;
    string contactInfo;
};

struct Transaction {
    string borrowerID;
    string bookISBN;
    string dateBorrowed;
    string dateReturned;
};

// Book 
void addBook();
void displayBooks();
void searchBook();
void updateBook();
void deleteBook();
void saveBooks();
void loadBooks();

// Borrower 
void addBorrower();
void displayBorrowers();
void searchBorrower();
void updateBorrower();
void deleteBorrower();
void saveBorrowers();
void loadBorrowers();

// Transaction 
void borrowBook();
void returnBook();
void displayTransactions();
void saveTransactions();
void loadTransactions();

#endif
