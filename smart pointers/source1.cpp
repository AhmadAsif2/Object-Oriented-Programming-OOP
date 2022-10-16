#include <iostream>
#include <memory>
#include <vector>
class Test {
    private:
        int data;
    public:
        Test() : data(0) { std::cout << "Data is empty " << std::endl; }
        Test(int data): data(data) { std::cout << "data: " << data << std::endl; }
        ~Test() {std::cout << "Destructor executed for " << data << std::endl; } 
        void show_data() {
            std::cout << "Data: " << data <<" ";
        }
};

int main() {

    // // std::unique_ptr<Test> ptr (new Test(100));
    // std::unique_ptr<Test> ptr = std::make_unique<Test>(100);
    // //Destructor Automatically called for unique pointers when pointers are destroyed
    // //No need to delete memory
    // std::unique_ptr<Test> ptr1 = std::make_unique<Test>(1000);
    // std::unique_ptr<Test> ptr2;
    // ptr2 = std::move(ptr1);//Now ptr1 becomes null because we can't make copies of unique pointers


    std::vector<std::unique_ptr<Test>> vec;

    vec.push_back(std::make_unique<Test>(2000));
    vec.push_back(std::make_unique<Test>(3000));
    vec.push_back(std::make_unique<Test>(4000));
    vec.push_back(std::make_unique<Test>(5000));

    for(const auto &v: vec)
        v->show_data();
        

    return 0;
}