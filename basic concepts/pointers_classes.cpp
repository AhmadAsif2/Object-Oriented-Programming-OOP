#include <iostream>
using namespace std;

class Complex {
    int real, imaginary;
    public:
        void setData(int a, int b) {

            real = a;
            imaginary = b;
        }

        void getData() {

            cout << "The real part is " << real << endl;
            cout << "The imaginary part is " << imaginary << endl;
        }

};


int main ()
{

    // Complex* ptr = new Complex;
    Complex complex;
    Complex* ptr = &complex;

    ptr->setData(4, 5);
    ptr->getData();

    return 0;
}