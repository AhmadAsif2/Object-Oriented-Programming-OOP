#include <iostream>
using namespace std;
class Number {
    private:
        int num;
    public:
        //default constructor
        Number() {
            num = 0;
        }
        Number (int n) {
            num = n;
        }
        //copy constructor
        Number (Number &obj) {
            cout << "Copy constructor called!!" << endl;
            num = obj.num;
        }

        void display() {
            cout << "The value of this number is " << num << endl;
        }
};
int main () {
    // Number obj1, obj2, obj3;

    // obj1 = Number(4);
    // obj1.display();

    // obj2 = Number();
    // obj2.display();

    // obj3 = Number(obj1);
    // obj3.display();

    // Number obj4 = obj3;
    // obj4.display();

    Number obj1(4);
    obj1.display();

    Number obj2(obj1);
    obj2.display();

    Number obj3;
    obj3 = obj2;
    obj3.display();//copy constructor not called

    Number obj4(obj3);
    obj4.display();
    
    return 0;
}
