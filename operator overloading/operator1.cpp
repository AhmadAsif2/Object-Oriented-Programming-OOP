#include <iostream>
#include <cstring>
using namespace std;
class Mystring{
    char *str;
    public:
        Mystring();
        Mystring(const char *s);
        Mystring(const Mystring &source);
        ~Mystring();
        void display();
        int get_length();
        const char *get_str();

};

Mystring:: Mystring() {
    str = nullptr;
    str = new char[1];
    *str = '\0';
}

Mystring:: Mystring(const char *s) {
    if (s == nullptr) {
        str = nullptr;
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

Mystring ::Mystring(const Mystring &source) {
    str = nullptr;
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

Mystring ::~Mystring(){
    delete [] str;
}

void Mystring ::display() {
    cout << str << " : " << get_length() << endl; 
}

int Mystring ::get_length() {
    return strlen(str);
}

const char *Mystring:: get_str() {return str;}
int main(){

    Mystring empty;
    empty.display();

    Mystring obj("Ahmad Asif Bitf20m534");
    obj.display();

    Mystring stooge(obj);
    stooge.display();

    return 0;
}