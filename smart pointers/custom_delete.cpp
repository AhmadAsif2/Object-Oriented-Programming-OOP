#include <iostream>
#include <memory>
using namespace std;

class Test {
    int data;
    public:
        Test(int data) {
            this->data = data;
        }
        ~Test() {
            cout << "Destructor executed" << endl;
        }
};

void my_deleter(Test *ptr) {
    cout << "Using my custom deleter function"<< endl;
    delete ptr;
}

int main() {
    /*
        When we use custome deleters we create memory on heap.
    */
    // shared_ptr<Test> (new Test(100), my_deleter);   

    shared_ptr<Test>(new Test(1000),[] (Test *ptr) {
        cout << "Using my custom deleter lambda expression" << endl;
        delete ptr;
    });      

    return 0;
}