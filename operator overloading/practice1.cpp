#include <iostream>
using namespace std;
class Complex {
    int a, b;
    public:
        Complex (){}

        Complex(int a1, int b1) {
            a = a1;
            b = b1;
        }

        void display() {
            cout << a << " + " << b << "i" << endl;
        }

        Complex operator+(Complex source) {
            Complex obj;
            obj.a = a + source.a;
            obj.b = b + source.b;
            return obj;
        }
};
int main() {

    Complex obj1(3, 4);
    obj1.display();
    Complex obj2(4, 8);
    obj2.display();
    Complex obj3(5, 8);
    obj3.display();
    Complex obj4 = obj1 + obj2 + obj3;
    obj4.display();
    
    return 0;
}