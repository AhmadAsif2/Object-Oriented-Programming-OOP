#include <iostream>
using namespace std;

class Account {
    public:
        virtual void withdraw(double amount) const {
            cout << "Account::Withdraw" << endl;
        }
};

class Savings:public Account {
    public:
        virtual void withdraw(double amount) const override {
            cout << "Savings::Withdraw" << endl;
        }
};

class Trust:public Account {
    public:
        virtual void withdraw(double amount) const override {
            cout << "Trust::Withdraw" << endl;
        }
};

class Test:public Account {
    public:
        virtual void withdraw(double amount) const override {
            cout << "Test::Withdraw" << endl;
        }
};

void test_withdraw(Account &obj, double amount){
    obj.withdraw(amount);
}

int main() {

    //Using Base Class References (Dynamic Binding)
    Account a;
    Account &ref = a;
    ref.withdraw(100);

    Test t;
    Test &ref1 = t;
    ref1.withdraw(100);

    Account a1;
    Savings a2;
    Trust a3;
    Test a4;

    //Dynamically Binding
    test_withdraw(a1, 100);
    test_withdraw(a2, 100);
    test_withdraw(a3, 100);
    test_withdraw(a4, 100);

    return 0;
}