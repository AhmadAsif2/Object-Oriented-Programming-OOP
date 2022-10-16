#include <iostream>
using namespace std;
class rectangle
{
    public:
    int area(int length, int breadth)
    {
        return length*breadth;
    }
};
int main ()
{
    rectangle a1,a2;
    cout << a1.area(4,5) << endl;
    cout << a2.area(5,8) << endl;
    return 0;
}