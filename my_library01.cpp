// MY_LIBRARY (CPP) - Leng Panhaleap
#include "my_library01.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Book books[MAX_ITEMS];
int bookCount = 0;

Borrower borrowers[MAX_ITEMS];
int borrowerCount = 0;

Transaction transactions[MAX_ITEMS];
int transactionCount = 0;

// Book  
void addBook() {
    if (bookCount >= MAX_ITEMS) return;
    cout << "Enter title: ";
    getline(cin >> ws, books[bookCount].title);
    cout << "Enter author: ";
    getline(cin, books[bookCount].author);
    cout << "Enter ISBN: ";
    getline(cin, books[bookCount].ISBN);
    cout << "Enter quantity: ";
    cin >> books[bookCount].quantity;
    if (books[bookCount].quantity < 0) books[bookCount].quantity = 0;
    bookCount++;
    cout << "Book added!\n";
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        cout << i+1 << ". " << books[i].title << ", " << books[i].author
             << ", " << books[i].ISBN << ", Qty: " << books[i].quantity << endl;
    }
}

void searchBook() {
    string input;
    cout << "Enter ISBN or Title: ";
    getline(cin >> ws, input);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].ISBN == input || books[i].title == input) {
            cout << "Found: " << books[i].title << ", Qty: " << books[i].quantity << endl;
            return;
        }
    }
    cout << "Book not found.\n";
}

void updateBook() {
    string isbn;
    cout << "Enter ISBN: ";
    getline(cin >> ws, isbn);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].ISBN == isbn) {
            cout << "Enter new quantity: ";
            cin >> books[i].quantity;
            if (books[i].quantity < 0) books[i].quantity = 0;
            cout << "Updated.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void deleteBook() {
    string isbn;
    cout << "Enter ISBN: ";
    getline(cin >> ws, isbn);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].ISBN == isbn) {
            books[i] = books[bookCount - 1];
            bookCount--;
            cout << "Deleted.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void saveBooks() {
    ofstream file("books.txt");
    for (int i = 0; i < bookCount; i++)
        file << books[i].title << "," << books[i].author << "," << books[i].ISBN << "," << books[i].quantity << endl;
    file.close();
}

void loadBooks() {
    ifstream file("books.txt");
    while (file && bookCount < MAX_ITEMS) {
        getline(file, books[bookCount].title, ',');
        getline(file, books[bookCount].author, ',');
        getline(file, books[bookCount].ISBN, ',');
        file >> books[bookCount].quantity;
        file.ignore();
        bookCount++;
    }
    file.close();
}

// Borrower 
void addBorrower() {
    if (borrowerCount >= MAX_ITEMS) return;
    cout << "Enter name: ";
    getline(cin >> ws, borrowers[borrowerCount].name);
    cout << "Enter ID: ";
    getline(cin, borrowers[borrowerCount].ID);
    cout << "Enter contact info: ";
    getline(cin, borrowers[borrowerCount].contactInfo);
    borrowerCount++;
    cout << "Borrower added!\n";
}

void displayBorrowers() {
    for (int i = 0; i < borrowerCount; i++) {
        cout << i+1 << ". " << borrowers[i].name << ", ID: " << borrowers[i].ID
             << ", Contact: " << borrowers[i].contactInfo << endl;
    }
}

void searchBorrower() {
    string input;
    cout << "Enter Name or ID: ";
    getline(cin >> ws, input);
    for (int i = 0; i < borrowerCount; i++) {
        if (borrowers[i].ID == input || borrowers[i].name == input) {
            cout << "Found: " << borrowers[i].name << ", Contact: " << borrowers[i].contactInfo << endl;
            return;
        }
    }
    cout << "Not found.\n";
}

void updateBorrower() {
    string id;
    cout << "Enter ID: ";
    getline(cin >> ws, id);
    for (int i = 0; i < borrowerCount; i++) {
        if (borrowers[i].ID == id) {
            cout << "Enter new contact info: ";
            getline(cin, borrowers[i].contactInfo);
            cout << "Updated.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void deleteBorrower() {
    string id;
    cout << "Enter ID: ";
    getline(cin >> ws, id);
    for (int i = 0; i < borrowerCount; i++) {
        if (borrowers[i].ID == id) {
            borrowers[i] = borrowers[borrowerCount - 1];
            borrowerCount--;
            cout << "Deleted.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void saveBorrowers() {
    ofstream file("borrowers.txt");
    for (int i = 0; i < borrowerCount; i++)
        file << borrowers[i].name << "," << borrowers[i].ID << "," << borrowers[i].contactInfo << endl;
    file.close();
}

void loadBorrowers() {
    ifstream file("borrowers.txt");
    while (file && borrowerCount < MAX_ITEMS) {
        getline(file, borrowers[borrowerCount].name, ',');
        getline(file, borrowers[borrowerCount].ID, ',');
        getline(file, borrowers[borrowerCount].contactInfo);
        borrowerCount++;
    }
    file.close();
}

// Transaction 
void borrowBook() {
    if (transactionCount >= MAX_ITEMS) return;
    string id, isbn;
    cout << "Enter Borrower ID: ";
    getline(cin >> ws, id);
    cout << "Enter Book ISBN: ";
    getline(cin, isbn);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].ISBN == isbn && books[i].quantity > 0) {
            books[i].quantity--;
            transactions[transactionCount].borrowerID = id;
            transactions[transactionCount].bookISBN = isbn;
            cout << "Enter Date Borrowed: ";
            getline(cin, transactions[transactionCount].dateBorrowed);
            transactions[transactionCount].dateReturned = "Not returned";
            transactionCount++;
            cout << "Book borrowed.\n";
            return;
        }
    }
    cout << "Book not available.\n";
}

void returnBook() {
    string id, isbn;
    cout << "Enter Borrower ID: ";
    getline(cin >> ws, id);
    cout << "Enter Book ISBN: ";
    getline(cin, isbn);
    for (int i = 0; i < transactionCount; i++) {
        if (transactions[i].borrowerID == id && transactions[i].bookISBN == isbn && transactions[i].dateReturned == "Not returned") {
            cout << "Enter Date Returned: ";
            getline(cin, transactions[i].dateReturned);
            for (int j = 0; j < bookCount; j++) {
                if (books[j].ISBN == isbn) {
                    books[j].quantity++;
                    break;
                }
            }
            cout << "Book returned.\n";
            return;
        }
    }
    cout << "Transaction not found.\n";
}

void displayTransactions() {
    for (int i = 0; i < transactionCount; i++) {
        cout << i+1 << ". Borrower ID: " << transactions[i].borrowerID
             << ", Book ISBN: " << transactions[i].bookISBN
             << ", Borrowed: " << transactions[i].dateBorrowed
             << ", Returned: " << transactions[i].dateReturned << endl;
    }
}

void saveTransactions() {
    ofstream file("transactions.txt");
    for (int i = 0; i < transactionCount; i++)
        file << transactions[i].borrowerID << "," << transactions[i].bookISBN << ","
             << transactions[i].dateBorrowed << "," << transactions[i].dateReturned << endl;
    file.close();
}

void loadTransactions() {
    ifstream file("transactions.txt");
    while (file && transactionCount < MAX_ITEMS) {
        getline(file, transactions[transactionCount].borrowerID, ',');
        getline(file, transactions[transactionCount].bookISBN, ',');
        getline(file, transactions[transactionCount].dateBorrowed, ',');
        getline(file, transactions[transactionCount].dateReturned);
        transactionCount++;
    }
    file.close();
}
