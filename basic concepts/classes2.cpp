#include <iostream>
#include <string>

using namespace std;

class student
{
    private:
        string n1;
        string n2;
    public:
        string a1;//address
        string a2;
        int roll_no1;
        int roll_no2;
        int phone_number1;
        int phone_number2;
        void setData(string name, string name2);
        void getData();

};

void student :: setData(string name, string name2)
{
    n1 = name;
    n2 = name2;
}

void student :: getData()
{
    cout << "your name is " << n1 << endl;
    cout << "your addresss is " << a1 << endl;
    cout << "your phone number is " << phone_number1<< endl;
    cout << endl; 
    cout << "your name is " << n2 << endl;
    cout << "your addresss is " << a2 << endl;
    cout << "your phone number is " << phone_number2<< endl;
    cout << endl;

}

int main ()
{
    student s1;
    student s2;
    s1.a1 = "New york";
    s1.phone_number1 = 11111111;
    s1.roll_no1 = 33;

    s2.a2 = "New york";
    s2.phone_number2 = 11111111;
    s2.roll_no2 = 35;
 
    s1.setData("john", "Sam");
    s1.getData();
    s2.getData();


    return 0;
}