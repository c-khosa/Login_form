#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include<vector>
using namespace std;
class BankAccount
{
    
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
static int nextAccountNumber;
    BankAccount( string accHolder, double initialBalance)
    {
        accountNumber = to_string(nextAccountNumber++);
        accountHolderName = accHolder;
        balance = initialBalance;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        }
        else
        {
            cout << "Insufficient funds!" << endl;
        }
    }

    void  displayAccountInfo() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << fixed << setprecision(2);
        cout << "Balance: " << balance << endl;
    }
    string getaccountNumber(){
        return accountNumber;
    }
};
BankAccount* findAccount(vector<BankAccount>& accounts, const string& accNum)
{
    for (auto& acc : accounts)
    {
        if (acc.getaccountNumber() == accNum)
        {
            return &acc;   
        }
    }
    return nullptr;       
}

int BankAccount::nextAccountNumber = 1001; 

int main()
{

    cout << "Welcome to the Bank Account Management System!" << endl;
    cout << "Enter Account Details:" << endl;
    vector<BankAccount> account;
    int choice;
    do
    {
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display One Account" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            string  accHolder;
            double initialBalance;
           
            cout << "Account Holder Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getline(cin, accHolder);
            cout << "Initial Balance: ";
            while (!(cin >> initialBalance) || initialBalance < 0)
            {
                cout << "Enter a valid non-negative amount: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            account.push_back(BankAccount(accHolder, initialBalance));
            cout << "Account created successfully!" << endl;
            cout<<"Account number"<<account.back().getaccountNumber()<<endl<<endl;
        }
        else if (choice == 2)
        {
            if (account.empty())
            {
                cout << "No accounts available. Create an account first." << endl;
                continue;
            }

            string accNum;
            cout << "Enter Account Number for deposit: ";
            cin >> accNum;
            BankAccount* acc = findAccount(account, accNum);
            if (acc == nullptr)
            {
                cout << "Account not found!" << endl;
            }
            else
            {
                double amount;
                cout << "Enter amount to deposit: ";
                while (!(cin >> amount) || amount <= 0)
                {
                    cout << "Enter a valid positive amount: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                acc->deposit(amount);
            }
        }
        else if (choice == 3)
        {
            if (account.empty())
            {
                cout << "No accounts available. Create an account first." << endl;
                continue;
            }

            string accNum;
            cout << "Enter Account Number for withdrawal: ";
            cin >> accNum;

            BankAccount* acc = findAccount(account, accNum);
            if (acc == nullptr)
            {
                cout << "Account not found!" << endl;
            }
            else
            {
                double amount;
                cout << "Enter amount to withdraw: ";
                while (!(cin >> amount) || amount <= 0)
                {
                    cout << "Enter a valid positive amount: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                acc->withdraw(amount);
            }
        }
        else if (choice == 4)
        {
            if (account.empty())
            {
                cout << "No accounts available." << endl;
                continue;
            }

            string accNum;
            cout << "Enter Account Number to display: ";
            cin >> accNum;

            BankAccount* acc = findAccount(account, accNum);
            if (acc == nullptr)
            {
                cout << "Account not found!" << endl;
            }
            else
            {
                acc->displayAccountInfo();
            }
        }
                else if (choice == 5)
        {
            if (account.empty())
            {
                cout << "No accounts available." << endl;
            }
            else
            {
                cout << "\nAll Accounts:" << endl;
                for (const auto& acc : account)
                {
                    acc.displayAccountInfo();
                }
            }
        }



        else if (choice == 6)
        {
            cout << "Exiting the system. Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
   

    
