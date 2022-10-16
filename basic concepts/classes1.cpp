#include <iostream>
using namespace std;
class student
{

public:
    string n;
    int r;
    void setData(string name, int roll_no);
    void getData();
};
void student ::setData(string name, int roll_no)
{
    n = name;
    r = roll_no;
}

void student ::getData()
{
    cout << "Your name is " << n << endl;
    cout << "Your roll no is is " << r << endl;
}

int main()
{
    student s1;
    s1.n = "john";
    s1.r = 2;
    // s1.setData("john", 2);
    s1.getData();
    return 0;
}
