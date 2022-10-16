#include <iostream>
#include <string>

// Function Template
template <typename T>
T min(T a, T b) {
  return (a < b) ? a : b;
}

// Function Template
template <typename T1, typename T2>
void func(T1 a, T2 b) {
  std::cout << a << "  " << b << std::endl;
}

struct Person {
  std::string name;
  int age;
  bool operator<(const Person &rhs) const {
    return this->age < rhs.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &obj) {
  os << "Name: " << obj.name << "  "
     << " Age: " << obj.age << std::endl;
  return os;
}

template <typename T>
void mySwap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

int main() {

  // int x = 100;
  // int y = 200;
  std::string x = "Ahmad";
  std::string y = "Hamza";

  func(x, y);
  mySwap(x, y);
  func(x, y);

  std::cout << "===================" << std::endl;

  Person p1{"Ahmad", 19};
  Person p2{"Hamza", 17};

  Person p3 = min(p1, p2);
  std::cout << p3.name << " is younger" << std::endl;

  func(p1, p2);

  std::cout << min<int>(2, 4) << std::endl;
  std::cout << min(4, 3) << std::endl;
  std::cout << min('A', 'C') << std::endl;
  std::cout << min(12.5, 9.2) << std::endl;
  std::cout << min(2 + 2 * 2, 3 + 4 * 3) << std::endl;

  func<int, int>(4, 5);
  func(9.2, 4.2);
  func<char, double>('A', 12.9);
  func('A', 12.9);
  func(1000, "Testing");
  func(1000, std::string{"Ahmad"});

  return 0;
}