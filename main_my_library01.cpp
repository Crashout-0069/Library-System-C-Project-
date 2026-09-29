// MAIN_MY_LIBRARY - Leng Panhaleap
#include <iostream>
#include "my_library01.hpp"
using namespace std;

int main() {
    int choice;
    loadBooks();
    loadBorrowers();
    loadTransactions();
    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Update Book\n5. Delete Book\n";
        cout << "6. Add Borrower\n7. Display Borrowers\n8. Search Borrower\n9. Update Borrower\n10. Delete Borrower\n";
        cout << "11. Borrow Book\n12. Return Book\n13. Display Transactions\n14. Save Data\n15. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); 
            break;
            case 2: displayBooks(); 
            break;
            case 3: searchBook(); 
            break;
            case 4: updateBook(); 
            break;
            case 5: deleteBook(); 
            break;
            case 6: addBorrower(); 
            break;
            case 7: displayBorrowers(); 
            break;
            case 8: searchBorrower(); 
            break;
            case 9: updateBorrower(); 
            break;
            case 10: deleteBorrower(); 
            break;
            case 11: borrowBook(); 
            break;
            case 12: returnBook(); 
            break;
            case 13: displayTransactions(); 
            break;
            case 14: saveBooks(); saveBorrowers(); saveTransactions(); 
            break;
            case 15: cout << "Goodbye!\n"; 
            break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 15);
    return 0;
}
