#include <iostream>
using namespace std;

class A {
    public:
        void greet() {
            cout << "HELLO" << endl;
        }
};

class B {
    public:
        void greet() {
            cout << "How are you?" << endl;
        }
};

class C : public A, public B {
    public:
        void greet() {
            A ::greet();
        } 
};

int main ()
{

    C obj;
    obj.greet();//prints class A greet function
    
    return 0;
}