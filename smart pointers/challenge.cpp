#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test {
    private:
        int data;
    public:
        Test(): data(0) {
            cout << "Test Constructor for data " << data << endl;
        }
        Test(int data): data(data){
        }
        int get_data() {
            return data;
        }

        ~Test() {
            cout << "Test Destructor for data: " << data << endl;
        }
};

std::unique_ptr<vector<shared_ptr<Test>>> make() {
    return make_unique<vector<shared_ptr<Test>>>();
} 

void fill(vector<shared_ptr<Test>> &vec, int num) {
    int temp;
    for (int i = 1; i <= num; i++) 
    {
        cout << "Enter data point " << i << ": ";
        cin >> temp;
        // shared_ptr<Test> ptr = make_shared<Test> (temp);
        // vec.push_back(ptr); 
        vec.push_back(make_shared<Test>(temp));
    }
}

void display(vector<shared_ptr<Test>> &vec) {
    cout << "\n==Displaying Vector===============" << endl;
    for (const auto &v: vec)
        cout << v->get_data() << endl;
    cout << "================================" << endl;
}

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    int num;
    cout << "Enter the element you want to enter: ";
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}