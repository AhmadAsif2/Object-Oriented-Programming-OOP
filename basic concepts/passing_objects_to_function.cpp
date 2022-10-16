#include <iostream>
using namespace std;
class complex {
    public:
        int a, b;
        void setData(int v1, int v2) {
            a = v1;
            b = v2;
        }
        //passing objects to function of class compplex
        void setDatabySum(complex o1, complex o2) {
            a = o1.a + o2.a;
            b = o2.a + o2.b;
        }

        void display() {
            cout << "The sum is " << a << " + " << b << "i" << endl;
        }
};
int main () {
    complex c1, c2, c3;

    c1.setData(3, 5);
    c1.display();

    c2.setData(4, 8);
    c2.display();

    c3.setDatabySum(c1, c2);
    c3.display();

    return 0;
}