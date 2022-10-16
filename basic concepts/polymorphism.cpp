#include <iostream>
using namespace std;

class Base{
    public:
        int a;
        void getData(){
            cout << "Displaying base class variable " << a << endl;
        }
};

class Derived : public Base{
    public:
        int b;
        void getData(){
            cout << "Displaying Base class variable " << a << endl;
            cout << "Displaying Derived class variable " << b << endl;
        }
};

int main ()
{
    
    Base* bptr;
    Base obj_base;
    Derived obj_derived;
    bptr = &obj_derived;

    bptr->a = 45;
    bptr->getData();
    //late binding points to only base class

    // bptr->b = 455;
    // bptr->getData();throws an error because it points to only base class pointer

    //creating derived class pointer
    Derived* dptr;
    
    dptr = &obj_derived;
    dptr->a = 55;
    dptr->b = 88;
    dptr->getData();


    // Derived *dptr = new Derived;
    // dptr->a = 45;
    // dptr->b = 56;
    // dptr->getData();

    return 0;
}