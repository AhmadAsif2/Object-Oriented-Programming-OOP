#include <iostream>
using namespace std;
class employee
{
    private:
        int a, b ,c;//private data members(not directly accessed in main function)
    public:
        int d, e;
        void setData(int a1, int b2, int c3);//declaration
        void getData(void)
        {
            cout << "The value of a is " << a << endl;
            cout << "The value of b is " << b << endl;
            cout << "The value of c is " << c << endl;
            cout << "The value of d is " << d << endl;
            cout << "The value of e is " << e << endl;
        }
};
//function dedfinition
void employee :: setData(int a1 , int b2, int c3)
{
    a = a1;
    b = b2;
    c = c3;
}

int main ()
{

    employee ahmad;
    // ahmad.a = 56;throw error because it is private data member
    ahmad.d = 45;
    ahmad.e = 77;
    ahmad.setData(5,6,7);
    ahmad.getData();
    
    return 0;
}
