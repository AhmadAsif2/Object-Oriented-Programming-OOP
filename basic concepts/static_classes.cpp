#include <iostream>

using namespace std;

class Employee
{
private:
    int id;
    static int count; // static is used because each object access the same count
    // in case if static is not used then each object have different count which is initially zero

public:
    void setData()
    {
        cout << "Enter the id " << endl;
        cin >> id;
        count++;
    }
    void getData()
    {
        cout << "The employee id is " << id << " and this is employee number " << count << endl;
    }

    //static member function
    static void getCount(void)
    {
        //cout << id; throws error because it is not static type
        cout << "The value of count " << count << endl;
    }
};
int Employee ::count = 645; // static variable msut declare outside the class
int main()
{
    Employee obj1, obj2;
    obj1.setData();
    obj1.getData();
    //calling static member function
    Employee ::getCount();

    obj2.setData();
    obj2.getData();
    Employee ::getCount();

    return 0;
}