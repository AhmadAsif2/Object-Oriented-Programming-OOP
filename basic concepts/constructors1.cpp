#include <iostream>
using namespace std;
class complex {
    public:
        int a, b;
        complex(void);
        void display() {
            cout << "Sum of complex number is " << a << " + " << b << "i";
        }
};
complex ::complex(void) {
    a = 0;
    b = 0;
}
int main () {
    complex obj;
    obj.display();
    return 0;
}