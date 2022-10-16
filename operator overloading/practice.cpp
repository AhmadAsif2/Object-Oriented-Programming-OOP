#include <iostream>
using namespace std;

class IncreDecre {
    int a, b;
    public:
        void Show() {
            cout << "Enter the number 1: ";
            cin >> a;
            cout << "Enter the number 2: ";
            cin >> b;
        }      
        void operator++() {
            a++;
            b++;
        }
        void operator--() {
            a--;
            b--;
        }
        void display() {
            cout << "Value a: " << a << endl;
            cout << "Value b: " << b << endl;
        }
};
int main() {

    IncreDecre id;
    id.Show();
    cout << "\n After Decrementing: " << endl;
    --id;
    id.display();  

    cout << "\n After Incrementing: " << endl;
    ++id;
    ++id;
    id.display();
    return 0;
}