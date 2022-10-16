#include <iostream>
using namespace std;
class c2;//forward declaration
class c1 {
    friend void swap(c1 &obj1,c2 &obj2);
    private:
        int data;
    public:
        void setData(int value) {
            data = value;
        }

        void display() {
            cout << data << endl;
        }

};

class c2 {
    friend void swap(c1 &obj1, c2 &obj2);
    private:
        int value;
    public:
        void setData(int data) {
            value = data;
        }
        void display() {
            cout << value << endl;
        }
};

void swap(c1 &obj1, c2 &obj2) {
    int temp = obj1.data;
    obj1.data = obj2.value;
    obj2.value = temp; 
}
int main ()
{
    c1 obj1;
    c2 obj2;

    obj1.setData(35);
    obj2.setData(88);

    swap(obj1, obj2);

    cout << "The values after swapping obj1 is ";
    obj1.display();
    cout << "The value after swapping obj2 is ";
    obj2.display();

    return 0;
}