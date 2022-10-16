#include <iostream>
using namespace std;
class complex {
    private:
        int a, b;
    public: 
        friend complex sumofcomplex(complex obj1, complex obj2);//friend function declaration
        void setData(int v1, int v2) {
            a = v1;
            b = v2;
        }

        void getData() {
            cout << "sum is " << a << " + " << b << "i" << endl;
        }
};

//friend function definition
complex sumofcomplex(complex obj1, complex obj2) {
    complex obj3;
    obj3.setData((obj1.a + obj2.a), (obj2.a + obj2.b));
    return obj3;
}

int main () {
    complex obj, obj1, obj2;

    obj.setData(3, 5);
    obj.getData();

    obj1.setData(5, 8);
    obj1.getData();

    // obj2.sumofcomplex(obj, obj1); cannot accessed because it is separate function outside the class
    obj2 = sumofcomplex(obj, obj1);//because this function is outside the class
    obj2.getData();

    return 0;
}