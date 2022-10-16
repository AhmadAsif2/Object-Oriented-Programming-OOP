#include <iostream>
using namespace std;
int main ()
{

    int* ptr = new int(40);
    cout << "The value is " << *(ptr) << endl;
    delete ptr;
    ptr = NULL;


    int* arr = new int[3];

    arr[0] = 45;
    arr[1] = 50;
    arr[2] = 44;

    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;

    delete []arr;
    arr = NULL;

    return 0;
}