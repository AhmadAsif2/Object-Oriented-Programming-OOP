#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int globalX = 1000;

void test1() {
  cout << "\n--Test1 ------------------" << endl;

  int localX = 100;

  // Capturing by value(copy)
  auto l = [localX] () {
    cout << localX << endl;
    cout << globalX << endl;
  };

  l();
}

void test2() {
  cout << "\n--Test2 ------------------" << endl;

  int x = 100;

  auto l = [x]() mutable {
    // locally increment the value(copy is incremented not actual value)
    x += 100;
    cout << x << endl;
  };

  l();
  cout << x << endl;

  l();
  cout << x << endl;
}

void test3() {
  cout << "\n--Test3 ------------------" << endl;

  int x = 100;

  // capturing by reference
  auto l = [&x]() mutable {
    x += 100;
    cout << x << endl; // 200
  };

  l();
  cout << x << endl; //200

}

void test4() {
  cout << "\n--Test4 ------------------" << endl;
  int x = 100;
  int y = 200;
  int z = 300;

  // Default Capture by value(copy)
  auto l = [=]() mutable {
    x += 100;
    y += 100;
    // The compiler deduced a warning because we are not using it in lambda
    cout << x << endl;
    cout << y << endl;
  };
  l();
  cout << "\n";
  cout << x << endl;
  cout << y << endl;
}

void test5() {
  cout << "\n--Test5 ------------------" << endl;
  int x = 100;
  int y = 200;
  int z = 300;

  // Default capture by reference
  auto l = [&] () mutable {
    x += 100; 
    y += 100; 
    z += 100;
    cout << x << endl; 
    cout << y << endl; 
    cout << z << endl; 
  };
  l();
  cout << "\n";
  cout << x << endl;
  cout << y << endl;
  cout << z << endl;
} 

void test6() {
  cout << "\n--Test6 ------------------" << endl;

  int x = 100;
  int y = 200;
  int z = 300;

  // Default capture by value(but one is reference) 
  auto l = [=, &y]() mutable {
    x+= 100;
    y+= 100;
    z+= 100;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
  };
    l();
    cout << "\n";
    cout << x << endl; //100
    cout << y << endl; //300
    cout << z << endl; //300
}

class Person {
  private:
    string name;
    int age;
    // Overloaded insertion operator
    friend std::ostream &operator<<(std::ostream &os, const Person &p) {
      os << "Person: " << p.name << ":" << p.age;
      return os;
    }
  public:
    Person() = default;
    Person(string name, int age)
      :name(name), age(age){}
    
    Person(const Person &p)
      :name(p.name), age(p.age){}
    
    ~Person() = default;

    void setName(string name) {
      this->name  = name;
    }

    string getName() {
      return name;
    }

    void setAge(int age) {
      this->age = age;
    }

    int getAge() {
      return age;
    }

    auto changePerson1() {
      return [this](string newName, int newAge){
        name = newName;
        age = newAge;
      };
    }
    auto changePerson2() {
      return [=](string newName, int newAge){
        name = newName;
        age = newAge;
      };
    }
    auto changePerson3() {
      return [&](string newName, int newAge){
        name = newName;
        age = newAge;
      };
    }
};

void test7() {
  cout << "\n--Test7 ------------------" << endl;
  Person person{"Larry", 18};
  cout << person << endl;

  auto changerPerson1 = person.changePerson1();
  changerPerson1("Moe", 30);
  cout << person << endl;
}

class Lambda {
  private:
    int y;
  public:
    Lambda(int y): y(y) {}

    void operator()(int x) {
      cout << x + y << endl;
    }
};

void test8() {
  cout << "\n--Test8 ------------------" << endl;
  int y =100;

  Lambda lambda1(y);
  auto lambda2 = [y] (int x) {
    cout << x + y << endl;
  };
  
  lambda1(100);
  lambda2(200);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  return 0;
}