#include <iostream>
using namespace std;
class complex {
    private:
        int a, b;
    public:
        complex(int, int);//parametrized constructor
        void display();
};

complex ::complex(int x, int y) {
    a = x;
    b = y;
}

void complex ::display() {
    cout << "Summing up " << a << " + " << b << "i" << endl;
}

int main () {
    //implicit calling
    complex obj(4, 5);
    obj.display();
    //explicit calling
    complex obj1 = complex(4, 5);
    obj1.display();
    return 0;
}