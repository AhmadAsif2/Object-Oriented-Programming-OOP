#include <iostream>
#include "Account.h"
using namespace std;
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