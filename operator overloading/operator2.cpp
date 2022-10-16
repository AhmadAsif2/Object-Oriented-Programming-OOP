#include <iostream>
#include <cstring>
using namespace std;
class Mystring{
    char *str;
    public:
        Mystring() {
            str = nullptr;
            str = new char[1];
            *str = '\0';
        }

        Mystring(const char *s) {
            if (s == nullptr) {
                str = nullptr;
                str = new char[1];
                *str = '\0';
            } else {
                str = new char[strlen(s) + 1];
                strcpy(str, s);
            }
        }

        Mystring(const Mystring &source) {
            str = nullptr;
            str = new char[strlen(source.str) + 1];
            strcpy(str, source.str);
        }

        ~Mystring() {
           
            delete [] str;
        }

        Mystring &operator=(const Mystring &rhs) {
            cout << "Copy assignment" << endl;
            if (this == &rhs)
                return *this;
            delete [] this->str;
            str = new char[strlen(rhs.str) + 1];   
            strcpy(this->str, rhs.str);
            return *this;
        }

        void display() {
            cout << str << " : " << get_length() << endl;
        }

        char *get_str() {
            return str;
        }

        int get_length() {
            return strlen(str);
        }
};
int main(){

    Mystring a = "Hello";
    Mystring b;
    b = a;
    b = "This is a test";
    a.display();
    b.display();

    return 0;
}