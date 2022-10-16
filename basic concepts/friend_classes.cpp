#include <iostream>
using namespace std;

class complex;//forward declaration
class calculator {
    public:

    // int add(int a, int b) {
    //     return (a + b);
    // }

    int SumRealComplex(complex o1, complex o2);//function declaration
    int SumCompComplex(complex o1, complex o2);
};

class complex {
    private:
        int a, b;
        // friend int calculator ::SumRealComplex(complex, complex);//declaring class friend fucntion
        // friend int calculator ::SumCompComplex(complex, complex);
        friend class  calculator;//make whole class friend
    public:
        void setData(int v1, int v2) {
            a = v1;
            b = v2;
        }

        void getData() {
            cout << "Your number is " << a << " + " << b << "i" << endl;
        }
};
//function definition
int calculator ::SumRealComplex(complex o1, complex o2) {
    return o1.a + o2.a;
}

int calculator ::SumCompComplex(complex o1, complex o2) {
    return o1.b + o2.b;
}

int main () {
    complex obj1, obj2;
    obj1.setData(3, 5);
    obj2.setData(5, 8);

    calculator obj3;
    int result = obj3.SumRealComplex(obj1, obj2);
    cout << "The sum of real part is " << result << endl;
    int resultc = obj3.SumCompComplex(obj1, obj2);
    cout << "The sum of complex part is " << resultc <<"i"<< endl;

    return 0;
}