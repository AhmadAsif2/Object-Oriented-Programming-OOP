#include <iostream>
using namespace std;
class Account {
    //attributes
    string name;
    double balance;

    public:
        //methods
        void set_balance(double bal) {balance = bal;}
        double get_balance() {return balance;}

        //methods can be declared outside of the class
        void set_name(string n);
        string get_name();

        bool deposit(double amount);
        bool withdraw(double amount);
};

void Account ::set_name(string n) {
    name = n;
}

string Account ::get_name() {
    return name;
}

bool Account ::deposit(double amount) {
    balance += amount;
    return true;
}

bool Account ::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    } else{
        return false;
    }
}

int main() {

    Account ahmad_account;
    ahmad_account.set_name("Ahmad");
    ahmad_account.set_balance(1000.0);

    if (ahmad_account.deposit(200)) {
        cout << "Desposit Ok" << endl;
    } else {
        cout << "Deposit not allowed" << endl;
    }

    if (ahmad_account.withdraw(500)) {
        cout << "Withdraw Ok" << endl;
    } else {
        cout << "Withdraw not allowed";
    }

    if (ahmad_account.withdraw(1500)) {
        cout << "Withdraw Ok" << endl;
    } else {
        cout << "Insufficient funds" << endl;
    }

    return 0;
}