#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test {
    private:
        int data;
    public:
        Test(): data(0) { }
        Test(int data) {
            this->data = data;
        }
        ~Test() {
            cout << "Destructor executed for: " << data << endl;
        }
        void display() {
            cout << "Data: " << data << endl;
        }
};

int main() {
    {
        shared_ptr<Test> p1 = make_shared<Test>(30);
        p1->display();
        cout << "Use Count: " << p1.use_count() << endl; //1

        shared_ptr<Test> p2;
        p2 = p1;

        cout << "Use count: " << p1.use_count() << endl; //2
        p2->display();

        p2.reset(); //delete the pointer
        cout << "Use Count: " << p1.use_count() << endl; //1
        {
            shared_ptr<Test> ptr1 = make_shared<Test>(100);
            shared_ptr<Test> ptr2 = make_shared<Test>(200);
            shared_ptr<Test> ptr3 = make_shared<Test>(300);

            cout << "===========VECTORS=========" << endl;
            vector<shared_ptr<Test>> vec;

            vec.push_back(ptr1);
            vec.push_back(ptr2);
            vec.push_back(ptr3);

            for (auto v:vec) {
                v->display();
                cout << "Use Count: " << v.use_count() << endl;
            }
        }
    }

    return 0;
}