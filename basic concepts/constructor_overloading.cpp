// #include <iostream>
// using namespace std;
// class complex {
//     private:
//         int x, y;
//     public:
//         complex(int a, int b) {//constructor overloading
//             x = a;
//             y = b;
//         }
//         complex(int a) {
//             x = a;
//             y = 0;
//         }
//         complex () {
//             x = 0;
//             y = 0;
//         }

//         void getData() {
//             cout << "Point is (" << x << "," << y <<")" << endl;
//         }
// };
// int main () {
//     complex obj1(5);
//     obj1.getData();

//     complex obj2(5, 7);
//     obj2.getData();

//     complex obj3;
//     obj3.getData();

//     return 0;
// }
#include <iostream>
using namespace std;
class Data {
    int a, b, c;
    public:
        Data(int a) {
            this->a = a;
            b = 0;
            c = 0;
        }
        Data(int a, int b) {
            this->a = a;
            this->b = b;
            c = 0;
        }
        Data(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        void display() {
            cout << "\n==============================" << endl;
            cout << a << "\n" << b << "\n" << c << endl;
        }
};
int main() {
    Data obj(1);
    obj.display();

    Data obj1(12, 14);
    obj1.display();

    Data obj2(12, 34, 77);
    obj2.display();


    return 0;
}