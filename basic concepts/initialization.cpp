#include <iostream>
using namespace std;

class Test {

    int a, b;
    public:
        /*
            initializtion list for constructor is used for complex constrcutors arguments
        */
        // Test(int i, int j) : a(i), b(j)
        // Test(int i, int j) : a(i), b(a + j)
        Test(int i, int j) : a(i), b(a * j)
        {

            cout << "Constructor called" << endl;
            cout << "The value of a is " << a << endl;
            cout << "The value of b is " << b << endl;
        }
};

int main ()
{
    
    Test test(4, 8);

    return 0;
}