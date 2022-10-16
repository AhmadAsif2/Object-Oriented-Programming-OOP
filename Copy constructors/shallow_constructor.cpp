#include <iostream>
using namespace std;
class Shallow{
    int *data;
    public:
        void set_data_value(int d) {*data = d;}
        void display_Shallow(Shallow p);
        //Constructor
        Shallow(int d);
        //Copy constructor
        Shallow(const Shallow &obj);
        //Destructor
        ~Shallow();
};
Shallow ::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow ::Shallow(const Shallow &obj) {
    data = obj.data;
    cout << "Copy constructor - Shallow Copy" << endl;
}

Shallow ::~Shallow(){
    delete data;
    cout << "Destructor executed" << endl;
}

int main() {

    Shallow obj1(100);
    /*
        -->In case of shallow copying obj 1 points to some memory allocated on heap
        When destructor called for this object it deletes the memory on heap
        as we delete the memory
        --> But when we create another object pass it 100 and another object and pass
        it value 1000 then both points same in case of copy constructor
        and thus causing errors in code.So rather than using shallow copy
        we are gonna use deep copying constructor in case of pointers...
    */


    return 0;
}