#include <iostream>
using namespace std;
class Base {
    int value;
    public:
        Base() : value(0) {
        }

        Base(int v)
            : value(v) {
                cout << "int Base Constructor" << endl;
            }
        
        Base(const Base &source)
            : value (source.value) {
                cout << "Copy Constructor" << endl;
            }

        Base &operator=(const Base &rhs) {
            cout << "Base operator= " << endl;
            if (this == &rhs)
                return *this;
            value = rhs.value;
            return *this;
        }

        ~Base() { cout << "Base Destructor Executed" << endl; }

};

class Derived : public Base {
    double doubled_value;
    public:
        Derived() : doubled_value(0){}

        Derived(double value)
            : Base(value), doubled_value(value*2) {
                cout << "Derived Constructor" << endl;
            }
        
        Derived(const Derived &source)
            : Base(source), doubled_value(source.doubled_value) {
                cout << "Derived Copy Constructor" << endl;
            }
        
        Derived &operator=(const Derived &rhs) {
            cout << "Derived operator= " << endl;
            if (this == &rhs)
                return *this;
            Base::operator=(rhs);
            doubled_value = rhs.doubled_value;
            return *this;
        }

        ~Derived() { cout << "Derived Destructor Executed" << endl; }
};
int main() {

    // Base obj(100);
    // Base obj1(obj);
    // obj = obj1;

    Derived obj(100);
    Derived obj1(obj);
    obj = obj1;


    return 0;
}