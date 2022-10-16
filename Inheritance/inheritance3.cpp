#include <iostream>
using namespace std;

class Base {
    int value;
    public:
        Base(): value(0) {
            cout << "Base No args constructor" << endl;
        }
        Base(int v): value(v) {
            cout << "Base Constructor called" << endl;
        } 
        ~Base() {
            cout << "Base Destructuor executed" << endl;
        }
};

class Derived:public Base {
    int double_value;
    public:
        using Base::Base;
        Derived():double_value(0) {
            cout << "Derived no args constructor" << endl;
        }
        Derived(int d):double_value(d *2) {
            cout << "Derived Contructor called: "<<double_value << endl;
        }
        ~Derived(){
            cout << "Derived Destructor executed" << endl;
        }
};

int main() {

    // Base b;
    // Base b(1000);

    // Derived d;
    Derived d(1000);


    return 0;
}