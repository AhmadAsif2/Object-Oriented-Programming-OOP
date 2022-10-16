#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <forward_list>
#include <string>
using namespace std;

class Person {
  private:
    string name;
    int age;

    // Overloaded insertion operator
    friend std::ostream &operator<<(std::ostream &os, const Person &obj) {
      os << obj.name << ":" << obj.age;
      return os;
    }

  public:
    Person() {
      name = "Unknown";
      age = 0;
    }

    Person(string name, int age) {
      this->name = name;
      this->age = age;
    }

    bool operator<(Person &rhs) {
      return this->age < rhs.age;
    }

    bool operator==(Person &rhs) {
      return (this->name == rhs.name) && (this->age == rhs.age);
    }
};

template <typename T>
void display(list<T> l) {
  cout << "[";
  for(const auto &elm: l) {
    cout << elm << " ";
  }
  cout << "]" << endl;
}

void test1() {
  cout << "\nTest1 =========================" << endl;
  list<int> l1{1,2,3,4,5};
  display(l1);

  list<string> l2;
  l2.push_back("Back");
  l2.push_front("Front"); 
  display(l2);

  list<int> l3;
  l3 = {1,2,3,4,5};
  display(l3);

  list<int> l4(10,100);
  display(l4);
}

void test2() {
  cout << "\nTest2 =====================" << endl;

  list<int> l{1,2,3,4,5,6,7,8,9,10};
  display(l);

  cout << "Size: " << l.size() << endl;

  cout << "Front: " << l.front() << endl;
  cout << "back: " << l.back() << endl;

  l.clear();
  display(l);
}

void test3() {
  cout << "\nTest3 ==========================" << endl;
  
  list<int> l{1,2,3,4,5,6,7,8,9,10};
  display(l);

  l.resize(5);
  display(l);

  l.resize(10);
  display(l);

  list<Person> persons;
  persons.resize(5);
  display(persons);
}

void test4() {
  cout << "\nTest4 ========================" << endl;

  list<int> l1{1,2,3,4,5,6,7,8,9,10};
  auto it = find(l1.begin(), l1.end(), 5);

  if(it != l1.end()) {
    l1.insert(it, 100);
  }
  display(l1);

  list<int> l2{1000,2000,3000};
  l1.insert(it, l2.begin(), l2.end());
  display(l1);

  advance(it, -4);
  cout << *it << endl;

  l1.erase(it);
  display(l1);

}

void test5() {
  cout << "\nTest5 ======================" << endl;

  list<Person> stooges {
    {"Larry", 10},
    {"Moe", 20},
    {"Curly", 30}
  };

  display(stooges);

  string name;
  int age;

  cout << "Enter the name: ";
  getline(cin, name);
  cin.clear();
  cout << "Enter the age";
  cin >> age;

  stooges.emplace_back(name, age);
  display(stooges);

  auto it = find(stooges.begin(), stooges.end(), Person("Moe", 20));
  if(it != stooges.end()) {
    stooges.emplace(it, "Frank", 45);
  }
  display(stooges);
}

void test6() {
  list<Person> stooges {
    {"Larry", 18},
    {"Moe", 25},
    {"Curly", 10}
  };

  display(stooges);
  stooges.sort();
  display(stooges);
}

int main() {

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  return 0;
}