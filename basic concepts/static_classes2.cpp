#include <iostream>
using namespace std;
class car
{
    private:
    int carId;
    string car_name;

    public:
    static int static_member; 
    car()
    {
        static_member++;
    }

    void input()
    {
        cout << "Enter the car Id ";
        cin >> carId;
        cout << "Enter the car name ";
        cin >> car_name;
    }

    void display()
    {
        cout << "your car Id is "<< carId << endl;
        cout << "your car name is " << car_name << endl;
    }

     static void counter()
    {
        cout << "The number of objects created " << static_member;
    }
};

int car ::static_member=0;
int main ()
{   
    //creating objects for classes
    car obj1,obj2;

    obj1.input();
    obj2.input();
    obj1.display();
    obj2.display();
    car ::counter();
    return 0;
}
