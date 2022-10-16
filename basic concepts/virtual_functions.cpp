#include <iostream>
using namespace std;

class Base{
    public:
        int a=1;
        virtual void display(){
            cout << "Displaying base class variable " << a << endl;
        }
};

class Derived : public Base{
    public:
        int b=2;
        void display(){
            cout << "Displaying base class variable " << a << endl;
            cout << "Displaying derived class variable " << b << endl;
        }
};
int main ()
{
    
    Base obj_base;
    Derived obj_derived;

    Base* bptr;
    bptr = &obj_derived;

    bptr->display();
    
    return 0;
}