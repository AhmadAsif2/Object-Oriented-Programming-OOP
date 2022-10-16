#include <iostream>
using namespace std;
class Account {
    friend std::ostream &operator<<(ostream &os,const  Account &source);
    public:
        double balance;
        Account(){}
        Account(double bal)
            : balance(bal) {
            }        
        void deposit(int amount);
        void withdraw(int amount);
        ~Account(){}
};

void Account::deposit(int amount) {
    balance +=  amount;
}

void Account::withdraw(int amount) {
    if(amount < balance)
        balance -= amount;
    else 
        cout << "Insufficient funds: " << endl;
}

std::ostream &operator<<(ostream &os, const Account &source) {
    os << "Current Balance is: " << source.balance << endl;
    return os;
}

class Savings_account : public Account {
    friend std::ostream &operator<<(ostream &os, const Savings_account &source);
    protected:
        double int_rate;
    public:
        Savings_account(){}
        Savings_account(double balance, double int_rate);
        void deposit(double amount);

};

Savings_account::Savings_account(double balance, double int_rate)
    : Account(balance), int_rate(int_rate) {
}

void Savings_account::deposit(double amount) {
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);
}

std::ostream &operator<<(ostream &os, const Savings_account &source) {
    os << "Saving account Balance: " << source.balance << " Interest Rate: " << source.int_rate << endl;
    return os;
}

int main() {

    Account a1(1000);
    cout << a1 << endl;

    a1.deposit(500);
    cout << a1 << endl;

    a1.withdraw(1000);
    cout << a1 << endl;

    cout << "=======================" <<endl;
    Savings_account s1(1000, 5.0);
    cout << s1 << endl;
    
    s1.deposit(2000);
    cout << s1<< endl;

    s1.withdraw(1000);
    cout << s1 << endl;

    cout << endl;


    return 0;
}