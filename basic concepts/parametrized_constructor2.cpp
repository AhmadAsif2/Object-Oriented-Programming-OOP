#include <iostream>
using namespace std;
class Point {
    private:
    int x, y;
    public:
    Point(int , int);//parametrized constructor
    void display() {
        cout << "Point is (" << x << " , " << y << ")" << endl;
    }
};

Point ::Point(int a, int b) {
    x = a;
    y = b;
}
int main () {

    Point obj(3, 5);//constructor calling
    obj.display();

    Point obj1 = Point(8, 9);
    obj1.display();

    return 0;
}