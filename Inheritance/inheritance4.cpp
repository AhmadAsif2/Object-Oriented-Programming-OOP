#include <iostream>
using namespace std;

class Base {
    int value;
    public:
        Base():value(0) {
            cout << "Base No args constructor called" << endl;
        }
        Base(int v):value(v) {
            cout << "Base (int) overloaded constructor called" << endl;
        }
        ~Base() {
            cout << "Base Destructor Executed" << endl;
        }
};

class Derived:public Base {
    double double_value;
    public:
        Derived():double_value(0) {
            cout << "Derived no args constructor executed" << endl;
        }
        Derived(double d):Base(d), double_value(d*2) {
            cout << "Derived Constructor executed" << endl;
        }
        ~Derived() {
            cout << "Derived Destructor executed" << endl;
        }
};

int main() {

    Derived obj(100);

    return 0;
}