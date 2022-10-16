#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
class Mystring{
    char *str;
    public:
        Mystring();
        Mystring(const char *s);
        ~Mystring();
        Mystring(const Mystring &source);
        const char *get_str();
        Mystring &operator=(Mystring &&rhs);
        void display();
        int get_length();
        bool operator==(const Mystring &rhs) const;
        Mystring operator-() const;
        Mystring operator+(const Mystring &rhs) const;

};

//Default Constructor
Mystring::Mystring() {
    str = nullptr;
    str = new char[1];
    *str = '\0';
}

//Parametrized Constructor
Mystring::Mystring(const char *s) {
    if (s == nullptr) {
        str = nullptr;
        str = new char[1];
        *str = '\0';
    } else {
        str = nullptr;
        str = new char [strlen(s) + 1];
        strcpy(str, s);
    }
}

//Destructor
Mystring::~Mystring() {
    delete [] str;
}

//Copy constructor
Mystring::Mystring(const Mystring &source) {
    str = nullptr;
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

//Display function
void Mystring::display() {
    cout << str << ": " << get_length() << endl;
}

//Length 
int Mystring::get_length() {
    return strlen(str);
}

//Returning string
const char *Mystring:: get_str() {
    return str;
}

//Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
    cout << "Using move assignment" << endl;
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}  
//Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (strcmp(str, rhs.str));
}
//Making lowercase
Mystring Mystring::operator-() const {
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (int i = 0; i < strlen(buff); ++i) 
        buff[i] = tolower(buff[i]);
    Mystring temp = buff;
    delete [] buff;
    return temp;
}

//Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring temp = buff;
    delete [] buff;
    return temp;
}


int main(){

    cout << boolalpha << endl;
    Mystring larry = "LARRY";
    Mystring moe = "Moe";

    Mystring stooge = larry;
    larry.display();
    moe.display();

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    larry.display();
    Mystring larry2 = -larry;
    larry2.display();

    Mystring stooges = larry + "Moe";
    //Mystring stooges = "larry" + "Moe" compiler error

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();

    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();

    return 0;
}