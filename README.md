# OOPC-Project
Hello Guys,

This Project is refers Bank Management System.

This Program is created by Meet Radadiya(MR)(22AIML042), Ronak Kawar(22AIML017), Ansh Trivedi(22AIML056).

Here We have a C++ program that implements a simple banking management system using classes and vectors. The program provides a menu of options that allow users to perform various banking operations, such as creating an account, updating an account, deleting an account, depositing money, withdrawing money, viewing account details, and generating a report.

The program has two main classes: `Account` and `Bank`. The `Account` class represents a bank account and contains three data members: `accountNumber`, `accountHolderName`, and `balance`. It also has methods for depositing, withdrawing, and printing the account details.

The `Bank` class represents a bank and contains a vector of `Account` objects. It provides methods for creating, updating, deleting, and retrieving accounts, as well as depositing, withdrawing, and printing account details. It also has a method for generating a report of all the accounts.

In the main function, a `Bank` object is created, and a menu of options is displayed to the user using a do-while loop. The user can choose an option by entering a number, and the corresponding function is called using a switch statement. 

The `createAccount` function prompts the user for an account number, account holder name, and initial balance, creates an `Account` object with these values, and adds it to the vector of accounts.

The `updateAccount` function prompts the user for an account number, searches for the account in the vector, and updates its account holder name and balance if it is found.

The `deleteAccount` function prompts the user for an account number, searches for the account in the vector, and removes it if it is found.

The `deposit` function prompts the user for an account number and deposit amount, searches for the account in the vector, and calls the `deposit` method of the `Account` object if it is found.

The `withdraw` function prompts the user for an account number and withdrawal amount, searches for the account in the vector, and calls the `withdraw` method of the `Account` object if it is found.

The `printAccountDetails` function prompts the user for an account number, searches for the account in the vector, and calls the `printDetails` method of the `Account` object if it is found.

The `generateReport` function opens a file called "report.txt", writes the account details of all the accounts in the vector to the file in a formatted manner, and closes the file.

Finally, the program exits when the user selects the "Exit" option from the menu.
