#include <iostream>
using namespace std;
class y;//forward declaration
class x {
    friend void add(x o1,y o2);
    private:
        int data;
    public:
        void setValue(int value) {
            data = value;
        }
};

class y {
    friend void add(x o1,y o2);//declaring friend funtion
    private:
        int num;
    public:
        void setNum(int value) {
            num = value;
        }
};
//function definition
void add (x o1,y o2) {
    cout << "Summing up values " << o1.data + o2.num << endl;
}

int main () {
    x obj1;
    obj1.setValue(3);

    y obj2;
    obj2.setNum(5);

    add(obj1,obj2);
    
    return 0;
}