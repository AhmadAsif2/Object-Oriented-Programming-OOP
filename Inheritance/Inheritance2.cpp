#include <iostream>
using namespace std;

class Base {
    public:
        int a;
        void display() {
            cout << a << ", " << b << ", " << c << endl;
        }
    protected:
        int b = 0;
    private:
        int c = 0;

};

class Derived:public Base {
    public: 
        void access_base_members() {
            a = 100;
            b = 200;
            // c = 300; Not accessible
        }
};
int main() {

    Base base;
    base.a = 100;
    // base.b = 200;both give compiler error not accessible in main
    // base.c = 300;
    base.display();

    Derived d;
    d.a = 300;
    // d.b = 200; Not accesible
    // d.c = 300; 
    d.access_base_members();
    d.display();

    return 0;
}