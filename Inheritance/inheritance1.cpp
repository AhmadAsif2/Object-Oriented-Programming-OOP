#include <iostream>
#include <string>
using namespace std;
//Base Class
class Account {
    public:
        double balance;
        string name;
        Account();
        ~Account();
        void deposit(int amount);
        void withdraw(int amount);
};

Account::Account()
    : balance(0), name("An Account") {
}

Account::~Account(){}

void Account::deposit(int amount) {
    cout << "Amount deposit called with " << amount << endl;
}

void Account::withdraw(int amount) {
    cout << "Amount withdraw called with " << amount << endl;
}

//Derived class (sub class)
class Saving_Account : public Account {
    public:
        int interest_rate;
        Saving_Account();
        ~Saving_Account();
        void deposit(int amount);
        void withdraw(int amount);
};

Saving_Account::Saving_Account()
    : interest_rate (0) {

}

Saving_Account::~Saving_Account() {}

void Saving_Account::deposit(int amount) {
    cout << "Saving account amount deposit called with " << amount << endl;
}

void Saving_Account::withdraw(int amount) {
    cout << "Saving account amount withdraw called with " << amount << endl; 
}

int main() {
    
    cout <<"\n=======Account Details=======" << endl;
    Account acc;
    acc.deposit(2000);
    acc.withdraw(500);

    Account *p_acc = new Account;
    p_acc->deposit(4000);
    p_acc->withdraw(1000);

    cout << "========Saving Account Details=======" << endl;
    Saving_Account sav_acc;
    sav_acc.deposit(3000);
    sav_acc.withdraw(500);

    Saving_Account *p_sav_acc = new Saving_Account;
    p_sav_acc->deposit(5000);
    p_sav_acc->withdraw(500);

    cout << endl;

    return 0;
}
