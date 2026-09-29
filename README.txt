This program is a Library Management System that helps users handle books, borrowers, 
and transactions easily. It features a simple menu that allows you to:
- Add, display, search, update, and delete books.
- Add, display, search, update, and delete borrowers.
- Manage transactions like borrowing and returning books.
The system can load and save data for books, borrowers, and transactions from text files. 
It also includes error handling to manage invalid inputs and to ensure books aren’t borrowed 
if they’re out of stock.

Features
Book Management:
-Add a new book (Title, Author, ISBN, Quantity).
-Display all books.
-Search for a book by ISBN or Title.
-Update book details (e.g., quantity).
-Delete a book.

Borrower Management:
-Add a new borrower (Name, ID, Contact Info).
-Display all borrowers.
-Search for a borrower by ID or Name.
-Update borrower details.
-Delete a borrower.

Transaction Management:
-Borrow a book (link a borrower to a book, reduce quantity).
-Return a book (increase quantity, mark as returned).
-Display all transactions.

File Handling:
-Load data from books.txt, borrowers.txt, and transactions.txt when the program starts.
-Save data back to the same files after updates.

Error Handling:
-Handle invalid inputs like negative quantities, invalid ISBNs, etc.
-Prevent borrowing of books if the quantity is zero.

Sorting & Searching:
-Books can be sorted by title, author, or ISBN.
-Books are searched using binary search (sorted by ISBN).

How to Compile and Run the Program:
-what you require to run: C++ Compiler and Code editor like VS Code
step 1: make sure that all files are in the same folder.
step 2: (for Visual Studio Code) look for the 3 dots, press it and click terminal -> new terminal 
step 3: copy "./main_my_library01.exe" and paste it into the terminal you just openned and it should run.

How to Use the Program:
Once the program is running, you will be presented with a menu. Here are the options available:

1. Add Book: Add a new book with title, author, ISBN, and quantity.
2. Display Books: View all the books in the library.
3. Search Book: Search for a book by ISBN or title.
4. Update Book: Update the quantity of a book.
5. Delete Book: Delete a book from the system.
6. Add Borrower: Add a new borrower with name, ID, and contact information.
7. Display Borrowers: View all borrowers.
8. Search Borrower: Search for a borrower by ID or name.
9. Update Borrower: Update borrower details.
10. Delete Borrower: Delete a borrower from the system.
11. Borrow Book: Link a borrower to a book and reduce the book's quantity.
12. Return Book: Mark a book as returned and increase its quantity.
13. Display Transactions: View all book transactions (borrowed/returned books).
14. Save Data: Save all current book, borrower, and transaction data to their respective files.
15. Exit: Exit the program.

The program will load the data from books.txt, borrowers.txt, and transactions.txt files when it starts.
All changes made during the session will be saved to the files when you select the "Save Data" option.