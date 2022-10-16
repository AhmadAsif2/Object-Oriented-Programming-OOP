#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
class Mystring
{
    friend std::ostream &operator<<(std::ostream &os,Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &obj);
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

// Default Constructor
Mystring::Mystring()
{
    str = nullptr;
    str = new char[1];
    *str = '\0';
}

// Parametrized Constructor
Mystring::Mystring(const char *s)
{
    if (s == nullptr)
    {
        str = nullptr;
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = nullptr;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Destructor
Mystring::~Mystring()
{
    delete[] str;
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
{
    str = nullptr;
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

// Display function
void Mystring::display()
{
    cout << str << ": " << get_length() << endl;
}

// Length
int Mystring::get_length()
{
    return strlen(str);
}

// Returning string
const char *Mystring::get_str()
{
    return str;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    cout << "Using move assignment" << endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}
// Equality
bool Mystring::operator==(const Mystring &rhs) const
{
    return (strcmp(str, rhs.str));
}
// Making lowercase
Mystring Mystring::operator-() const
{
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (int i = 0; i < strlen(buff); ++i)
        buff[i] = tolower(buff[i]);
    Mystring temp = buff;
    delete[] buff;
    return temp;
}

// Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring temp = buff;
    delete[] buff;
    return temp;
}

std::ostream &operator<<(std::ostream &os,Mystring &obj) {
    os << obj.str;
    return os;
}

std::istream &operator>>(std::istream &is,Mystring &obj) {
    char *buff = new char[1000];
    is >> buff;
    obj = Mystring {buff};
    delete [] buff;
    return is;
}

int main()
{

    Mystring larry = "Larry";
    Mystring moe = "Moe";
    Mystring curly;

    cout << "\n Enter the stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << " , " << curly << endl;

    cout << "\n Enter the three stooge's  name separated by spaces: ";
    cin >> larry >> moe >> curly;

    cout << "\n Three stooge's are :" << larry << ", " << moe << ", " << curly;

    return 0;
}