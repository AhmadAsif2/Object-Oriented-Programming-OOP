#include <iostream>
using namespace std;
class num {
    public:
        static int count;
        num() {
            count++;
            cout << "Constructor called for obj" << count << endl;
        }
        ~num() {
            cout << "Destructor called for obj" << count << endl;
            count--;
        }
};
int num ::count = 0;
int main () {
    num n1;
    {
        num n2, n3;
    }
    return 0;
}