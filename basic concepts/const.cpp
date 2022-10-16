#include <iostream>

class Entity {
    int m_X, m_Y;
    public:

        /* const is reserved keyword in C++
            It allows not to change any value in c++
        */


        // If we add const keyword after function definition then
        // it does not allow you to change any attribute in that function
        //Note that it works in the block of the function
        //While outside of the function it is changeable

        int get_value() const {
            // m_X = 34;throws error
            return m_X;
        }

        void set_X(int x) {
            m_X = x;
        }

       

        const int size = 34;
        // size = 45;throw errror

    

};

void print_entity( const Entity& e) {
    std::cout << e.get_value() << std::endl;
}

int main() {    

    const int size = 45;

    // const int *ptr = new int();
    // *ptr = 34; throws error

    // int *const ptr = new int();
    // ptr = (int*)&size; throws error

    
    // const int *const ptr = new int(5);

    // std::cout << *ptr << std::endl;

    Entity e;
    e.set_X(34);
    e.get_value();
    print_entity(e);

    std::cin.get();
    return 0;
}