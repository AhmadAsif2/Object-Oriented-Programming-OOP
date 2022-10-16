#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional> // std::functional

using namespace std;

// Using stateless Lambda expression

class Person 
{
  private:
    string name;
    int age;
    friend std::ostream &operator<<(std::ostream &os, const Person &obj) {
      os << obj.name << ":" << obj.age << " ";
      return os;
    }

  public:
    Person() = default;
    Person(const Person &p)
      :name (p.name), age(p.age) { }
    Person(string name, int age)
      : name(name), age(age){}

    ~Person()= default;

    string getName() const { return name; }
    int getAge() const { return age; }

    void setName(string name) {
      this->name = name;
    }

    void setAge(int age) {
      this->age = age;
    }
};

void test1() {
  cout << "\n--Test1 ------------------------------------" << endl;
  
  // Stateless Lambda expression
  []() {cout << "Hi" << endl;}();
  [](int x) {cout << x << endl;}(100);
  [](int x, int y) {cout << x + y << endl;}(100,200);
}

void test2() {
  cout <<"\n--Test2-------------------------------------" << endl;
  auto l1 = [](){cout << "Hi" << endl;};
  l1();

  int num1 = 100;
  int num2 = 100;

  auto l2 = [](int x, int y){
    cout << x + y << endl;
  };
  l2(num1, num2);

  auto l3 = [](int &x, int y) {
    cout <<"x: " << x << " y: " << y << endl;
    x = 1000;
    y = 2000;
  };
  l3(num1, num2);
  cout << num1 << " " << num2 << endl;
}

void test3() {
  cout << "\n--Test3-----------------------" << endl;

  Person stooge{"Larry", 18};
  cout << stooge << endl;

  auto l4 = [](Person p) { // Passing by value(Copy constructor called)
    cout << p << endl;
  };
  l4(stooge);

  auto l5 = [](const Person &p) { // Passing by reference(alias)
    cout << p << endl; // Overloaded insertion operator called
  };
  l5(stooge);

  auto l6 = [](Person &p) {
    p.setName("Ahmad");
    p.setAge(19);
    cout << p << endl;
  };
  l6(stooge);
  cout << stooge << endl;
}

void filterVector(const vector<int> &vec, function<bool(int)> func) {
  cout << "[ ";
  // Using function lambda expression
  for(int i: vec)
    if(func(i))
      cout << i << " ";
  
  cout << "]" << endl;
}

void test4() {
  cout << "\n--Test4 -------------------" << endl;
  vector<int> v{10,20,30,40,50,60,70,80,90,100};
  filterVector(v, [](int x){ return x > 50; });
  filterVector(v, [](int x){ return x<= 30; });
  filterVector(v, [](int x){ return x>=30 && x<=60; });
}

// Returning lambda from function
auto makeLambda() {
  return []() {
    cout << "this lambda made by make_lambda_function" << endl;
  };
}

void test5() {
  cout << "\n--Test5 -------------------" << endl;

  auto l7 = makeLambda();
  l7();
}

// Using auto lambda parameter list
void test6() {
  cout << "\n--test6 -------------------" << endl;
  
  auto l8 = [](auto x, auto y){
    cout << "X: " << x << " Y: " << y << endl;
  };

  l8(10,20);
  l8(10.9,30);
  l8(Person("Larry", 19), Person("Curly", 34));
}

void test7() {
  cout << "\n--Test7 -----------------------" << endl;
  vector<Person> stooges {
    {"Larry", 34},
    {"Moe", 45},
    {"Curly", 29}
  };

  // Sorting based on Name  
  sort(stooges.begin(), stooges.end(), [](const Person &p1, const Person &p2){
    return p1.getName() < p2.getName();
  });

  for_each(stooges.begin(), stooges.end(),[](const Person &p){
    cout << p << endl;
  });

  cout << endl;

  // Sorting based on Age
  sort(stooges.begin(), stooges.end(), [](const Person &p1, const Person &p2){
    return p1.getAge() < p2.getAge();
  });

  for_each(stooges.begin(), stooges.end(),[](const Person &p){
    cout << p << endl;
  });

}

int main() {

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  return 0;
}