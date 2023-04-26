//Banking management system
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Account class representing a single bank account
class Account
{
public:
    int accountNumber;          // Account number
    string accountHolderName;   // Account holder name
    double balance;             // Account balance

    // Default constructor
    Account() {}

    // Constructor with parameters
    Account(int accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    // Method to deposit funds into the account
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited $" << amount << " into account number " << accountNumber << endl;
        cout << "New balance: $" << balance << endl;
    }

    // Method to withdraw funds from the account
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account number " << accountNumber << endl;
            cout << "New balance: $" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in account number " << accountNumber << endl;
        }
    }

    // Method to print the account details
    void printDetails()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Bank class representing the collection of accounts
class Bank
{
public:
    vector<Account> accounts;   // Vector of accounts

    // Method to create a new account
    void createAccount(int accountNumber, string accountHolderName, double balance)
    {
        Account account(accountNumber, accountHolderName, balance);
        accounts.push_back(account);
        cout << "Account created successfully!" << endl;
    }

    // Method to update an existing account
    void updateAccount(int accountNumber, string accountHolderName, double balance)
    {
        Account *account = getAccount(accountNumber);
        if (account == NULL)
        {
            cout << "Account not found!" << endl;
        }
        else
        {
            account->accountHolderName = accountHolderName;
            account->balance = balance;
            cout << "Account details updated successfully!" << endl;
        }
    }

    // Method to delete an account
     void deleteAccount(int accountNumber)
    {
        // Find the account with the given account number and remove it from the vector
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].accountNumber == accountNumber)
            {
                accounts.erase(accounts.begin() + i);
                cout << "Account deleted successfully!" << endl;
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

     // Define a public function to get an account object with a given account number
    Account *getAccount(int accountNumber)
    {
        // Find the account with the given account number and return a pointer to it
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].accountNumber == accountNumber)
            {
                return &accounts[i];
            }
        }
        // Return NULL if the account is not found
        return NULL;
    }

    // Define a public function to deposit money into an account
    void deposit(int accountNumber, double amount)
    {
        // Get the account object with the given account number
        Account *account = getAccount(accountNumber);
        // If the account is found, deposit the money into it
        if (account == NULL)
        {
            cout << "Account not found!" << endl;
        }
        else
        {
            account->deposit(amount);
        }
    }

    // Define a public function to withdraw money from an account
    void withdraw(int accountNumber, double amount)
    {
        // Get the account object with the given account number   
        Account *account = getAccount(accountNumber);
        // If the account is found, withdraw the money from it
        if (account == NULL)
        {
            cout << "Account not found!" << endl;
        }
        else
        {
            account->withdraw(amount);
        }
    }
     // Define a public function to print the details of an account
    void printAccountDetails(int accountNumber)
    {
        // Get the account object with the given account number
        Account *account = getAccount(accountNumber);
        // If the account is found, print its details
        if (account == NULL)
        {
            cout << "Account not found!" << endl;
        }
        else
        {
            account->printDetails();
        }
    }
    // Define a public function to generate a report
    void generateReport()
    {
        ofstream outfile("report.txt");
        outfile << left << setw(20) << "Account Number"
                << left << setw(20) << "Account Holder Name"
                << left << setw(10) << "Balance"
                << endl;

        for (int i = 0; i < accounts.size(); i++)
        {
            outfile << left << setw(20) << accounts[i].accountNumber
                    << left << setw(20) << accounts[i].accountHolderName
                    << left << setw(10) << accounts[i].balance
                    << endl;
        }
        outfile.close();
        cout << "Report generated successfully!" << endl;
    }
};

int main()
{
    Bank bank; // create an instance of the Bank class
    int choice;

    // display the menu and get the user's choice
    do
    {
        // display the menu options
        cout<<"...................................."<<endl;
        cout << "::::   Bank Management System   ::::" << endl;
        cout<<"...................................."<<endl;
        cout << "1. Create Account" << endl;
        cout << "2. Update Account" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. View Account Details" << endl;
        cout << "7. Generate Report" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // perform the selected operation based on the user's choice
        switch (choice)
        {
        case 1: // create a new account
        {
            int accountNumber;
            string accountHolderName;
            double balance;
            system("cls");
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            cout << "Enter balance: ";
            cin >> balance;
            bank.createAccount(accountNumber, accountHolderName, balance);
            break;
        }
        case 2: // update an existing account
        {
            int accountNumber;
            string accountHolderName;
            double balance;
            system("cls");
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            cout << "Enter balance: ";
            cin >> balance;
            bank.updateAccount(accountNumber, accountHolderName, balance);
            break;
        }
        case 3: // delete an existing account
        {
            int accountNumber;
            system("cls");
            cout << "Enter account number: ";
            cin >> accountNumber;
            bank.deleteAccount(accountNumber);
            break;
        }
        case 4: // deposit money into an account
        {
            int accountNumber;
            double amount;
            system("cls");
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount: ";
            cin >> amount;
            bank.deposit(accountNumber, amount);
            break;
        }
        case 5: // withdraw money from an account
        {
            int accountNumber;
            double amount;
            system("cls");
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount: ";
            cin >> amount;
            bank.withdraw(accountNumber, amount);
            break;
        }
        case 6: // display the details of an account
        {
            int accountNumber;
            system("cls");
            cout << "Enter account number: ";
            cin >> accountNumber;
            bank.printAccountDetails(accountNumber);
            break;
        }
        case 7: // generate a report of all accounts
        {
            bank.generateReport();
            break;
        }
        case 8: // exit the program
        {
            system("cls");
            cout << "Exiting program..." << endl;
            break;
        }
        default: // invalid choice
        {
            system("cls");
            cout << "Invalid choice! Please enter a valid choice." << endl;
            break;
        }
        }

    } while (choice != 8);

    return 0;

}

