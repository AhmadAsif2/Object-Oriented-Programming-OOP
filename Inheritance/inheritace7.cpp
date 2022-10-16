#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
protected:
    friend std::ostream &operator<<(std::ostream &os, const Account &source);
    string name;
    double balance;
public:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    Account(string name = def_name, double balance = def_balance);
    
    bool deposit(double amount);
    bool withdraw(double amout);
    double get_balance() const;
};
Account::Account(string name, double balance)
    : name(name), balance(balance) {
    }
    
bool Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance - amount > 0)
        return true;
    return false;
}

double Account::get_balance() const {
    return balance;
}

std::ostream &operator<<(std::ostream &os, const Account &source) {
    os << "Account Name: " << source.name << "Current Balance: " << source.balance << endl;
    return os;
}

class Saving_Account : public Account {
    friend std::ostream &operator<<(std::ostream &os, const Saving_Account &source);
protected:
    double int_rate;
    static constexpr const char* def_name = "Unnamed Savings_Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
public:
    Saving_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit (double amount);
};

Saving_Account::Saving_Account(string name, double balance, double int_rate)
    : Account(name, balance), int_rate(int_rate) {
    }

bool Saving_Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        amount += amount * (int_rate / 100);
        return Account::deposit(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Saving_Account &source) {
    os << "Saving_Account: " << source.name << " Current Balance: " << source.balance << " Interest Rate: " << source.int_rate << endl;
    return os;
}


 void display(const vector <Account> &account);
 void deposit(vector <Account> &account, double amount);
 void withdraw(vector <Account> &account, double amount);
 
 void display(const vector <Saving_Account> &account);
 void deposit(vector <Saving_Account> &account, double amount);
 void withdraw(vector <Saving_Account> &account, double amount);
 

int main() {
    
    vector <Account> acc;
    acc.push_back(Account {});
    acc.push_back(Account {"Ahmad"});
    acc.push_back(Account {"Hamza", 1000});
    acc.push_back(Account {"Asif", 5000});
    
    display(acc);
    deposit(acc, 1000);
    withdraw(acc, 2000);
    
    vector <Saving_Account> sav_acc;
    sav_acc.push_back(Saving_Account {});
    sav_acc.push_back(Saving_Account {"Waleed"});
    sav_acc.push_back(Saving_Account {"Rayan", 2000});
    sav_acc.push_back(Saving_Account {"Bilal", 5000, 5.0});
    
    display(sav_acc);
    deposit(sav_acc, 1000);
    withdraw(sav_acc, 2000);
    
    return 0;
}

void display(const vector <Account> &account) {
    cout << "\n== Displaying Account=======================" << endl;
    for (const auto &vec : account) {
        cout << vec << endl;
    }
}

void deposit(vector <Account> &account, double amount) {
    cout << "\n===Depositing amount======================" << endl;
    for (auto &vec : account) {
        if (vec.deposit(amount)) {
            cout << "Deposited " << amount << " to " << vec << endl;
        } else {
            cout << "Failed deposit of " << amount << " to " << vec << endl;
        }
    }
}

void withdraw(vector <Account> &account , double amount) {
    cout << "\n===Withdrawing Amount=====================" << endl;
    for (auto &vec : account) {
        if (vec.withdraw(amount))
            cout << "Withdrawing " << amount << " from " << vec << endl;
        else 
            cout << "Failed to withdraw " << amount << " from " << vec << endl;
    }
}

void display(const vector <Saving_Account> &account) {
    cout << "\nDisplaying Saving_Account =======================" << endl;
    for (const auto &acc : account) {
        cout << acc << endl;
    }
}

void deposit(vector <Saving_Account> &account, double amount) {
    cout << "\n Depositing to savings account================== " << endl;
    for (auto &acc : account) {
        if (acc.deposit(amount))
            cout << "Deposited " << amount << " to " << acc << endl;
        else 
            cout << "Failed to deposit " << amount << "  to " << acc << endl;
    }
}

void withdraw(vector <Saving_Account> &account, double amount) {
    cout << "\n Withdrawing amount=====================" << endl;
    for (auto &acc : account) {
        if (acc.withdraw(amount)) 
            cout << "Withdrawing " << amount << " from " << acc << endl;
        else 
            cout << "Failed to withdraw " << amount << " from " << acc << endl;
    }
}
