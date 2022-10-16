#include <iostream>
using namespace std;
class Employee
{
public:
    int employeeId;
    void setData();
    void getData();
};

void Employee ::setData()
{
    cout << "Enter the id of the employee " << endl;
    cin >> employeeId;
}

void Employee ::getData()
{
    cout << "The employee id is " << employeeId << endl;
}

int main()
{

    Employee obj[5]{};
    for (int i = 0; i < 5; i++)
    {
        obj[i].setData();
        obj[i].getData();
    }
    return 0;
}