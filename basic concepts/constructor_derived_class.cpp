#include <iostream>
using namespace std;
class Base1 {
    int data1;
    public:
        Base1(int d) {
            data1 = d;
        }

        void printData1() {
            cout << "Constructor called for Base1 " << endl;
            cout << "The value of data 1 is " << data1 << endl;
        }
};

class Base2 {
    int data2;
    public:
        Base2(int d1) {
            data2 = d1;
        }

        void printdata2() {

            cout << "Conctructor called for Base2 " << endl;
            cout << "The value of data 2 is " << data2 << endl; 
        }
};
//constructor called for base class first
class Derived : public Base1, public Base2 {
    int data3, data4;
    public:
        Derived(int a, int b, int c, int d) : Base1(a), Base2(b) {
            data3 = c;
            data4 = d;
        }

        void show_data() {
            cout << "Derived class constructor called " << endl;
            cout << "The value of data 3 is " << data3 << endl;
            cout << "The value of data 4 is "  << data4 << endl;
        }
};
int main ()
{
    
    Derived derived(1, 2, 4 ,7);
    derived.printData1();
    derived.printdata2();
    derived.show_data();

    return 0;
}