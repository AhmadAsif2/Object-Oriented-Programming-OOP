#include <iostream>
using namespace std;

class A{
    int a;
    public:
        A & setData(int a) {
            this->a = a;
            return *this;
        }
        void getData(){
            cout << "The value of a is " << a << endl;
        }
};
int main ()
{
    //creating object for class A
    A a;

    //calling setters getters
    a.setData(4);
    a.getData();

    return 0;
}