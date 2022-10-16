// #include <iostream>
// using namespace std;

// class I_printable { //Abstract class as Interface
//     friend std::ostream& operator<<(std::ostream& os,const I_printable& obj);
// public:
//     virtual void print(ostream &os) const = 0;
// };

// std::ostream& operator<<(std::ostream& os,const I_printable& obj) {
//     obj.print(os);
// }

// class Account:public I_printable {
//     public:
//         virtual void withdraw() {
//             cout << "Account::Withdraw"<< endl;
//         }
//         virtual void print(std::ostream &os)const  override {
//             os << "Account Display";
//         }
//         virtual ~Account() { }
// };

// class Savings_account:public Account {
// public:
//     virtual void withdraw() {
//         cout << "Savings Account::Withdraw" << endl;
//     }
//     virtual void print(std::ostream& os) const override {
//         os << "Savings Account Display";
//     }
//     virtual ~Savings_account() { }
// };

// class Dog:public I_printable {
// public:
//     virtual void print(ostream &os)const override {
//         os << "Woof Woof";
//     }
// };

// void print(const I_printable& obj) {
//     cout << obj << endl;
// }

// int main() {
//     // Account* ptr = new Account();
//     // Account *ptr1 = new Savings_account();

//     // ptr->withdraw();
//     // ptr1->withdraw();

//     Account* ptr = new Account();
//     // cout << *ptr << endl;

//     Account* ptr1 = new Savings_account();
//     // cout << *ptr1 << endl;

//     Dog* ptr2 = new Dog();
//     // cout << *ptr2 << endl;

//     print(*ptr);
//     print(*ptr1);
//     print(*ptr2);

//     delete ptr;
//     delete ptr1;
//     delete ptr2;

//     return 0;
// }

// Abstract class as interface
#include <iostream>
using namespace std;

class I_Printable{
    friend ostream &operator<<(ostream &os, const I_Printable &obj){
        obj.print(os);
    }
public:
    // Pure Virtual function
    virtual void print(ostream &os) const = 0;
    virtual ~I_Printable(){}
};

class Account:public I_Printable{
    public:
        virtual void withdraw(){
            cout << "Account::Withdraw" << endl;
        }

        virtual void print(ostream &os)const override{
            os << "Account::Display" << endl;
        }

        virtual ~Account(){}
};

class SavingsAccount:public Account{
    public:
        virtual void withdraw(){
            cout << "Savings Account::Withdraw" << endl;
        }

        // Overriding the abstract class function
        virtual void print(ostream &os)const override{
            os << "Savings Account::Display" << endl;
        }

        virtual ~SavingsAccount(){}
};

class TrustAccount:public Account{
    public:
        virtual void withdraw(){
            cout << "Trust Account::Withdraw" << endl;
        }

        virtual void print(ostream &os)const override{
            os << "Trust Account::Display" << endl;
        }

        virtual ~TrustAccount(){}
};

void print(I_Printable &obj){
    cout << obj << endl;
}

int main(){

    Account *ptr1 = new Account();
    // ptr1->withdraw();
    // cout << *ptr1 << endl;
    Account *ptr2 = new SavingsAccount();
    Account *ptr3 = new TrustAccount();

    ptr1->withdraw();
    ptr2->withdraw();
    ptr3->withdraw();
    
    print(*ptr1);
    print(*ptr2);
    print(*ptr3);

    delete ptr1;
    delete ptr2;
    delete ptr3;
    return 0;
}
