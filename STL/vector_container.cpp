#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Person {
  private:
    string name;
    int age;
    friend std::ostream &operator<<(std::ostream &os, Person &obj) {
      os << obj.name << ":" << obj.age;
      return os;
    }
  public:
    Person() = default;
    Person(string name, int age)
      : name(name), age(age) { }
    
    bool operator<(Person &rhs) {
      return this->age < rhs.age;
    }

    bool operator==(Person &rhs) {
      return ((this->name == rhs.name) && (this->age = rhs.age));
    }
};

void display(vector<int> &vec) {
  cout << "[";
  for_each(vec.begin(), vec.end(),[](int x){
    cout << x << " ";
  });
  cout << " ]" << endl;
}

template <typename T>
void display1(vector<T> &v) {
  cout << "[";
  for(auto &elm: v) {
    cout << elm << " ";
  }
  cout << "]" << endl;
}

void test1() {
  cout << "\nTest 1 ====================" << endl;
  vector<int> vec {1,2,3,4,5,6};

  display(vec);

  vec = {7,8,9,10};
  display1(vec);

  // Overloaded constructor of vector container
  vector<int> vec1(10, 100);
  display1(vec1);
}

void test2() {
  cout << "\nTest2 ====================" << endl;

  vector<int> vec{1,2,3,4,5};

  display1(vec);
  cout << "Vec size: " << vec.size() << endl;
  cout << "Vec Max Size: " << vec.max_size() << endl;
  cout << "Vec capacity: " << vec.capacity() << endl;

  vec.push_back(6);
  display1(vec);
  cout << "Vec size: " << vec.size() << endl;
  cout << "Vec Max Size: " << vec.max_size() << endl;
  cout << "Vec capacity: " << vec.capacity() << endl;

  vec.shrink_to_fit();
  display1(vec);
  cout << "Vec size: " << vec.size() << endl;
  cout << "Vec Max Size: " << vec.max_size() << endl;
  cout << "Vec capacity: " << vec.capacity() << endl;

  vec.reserve(100);
  display1(vec);
  cout << "Vec size: " << vec.size() << endl;
  cout << "Vec Max Size: " << vec.max_size() << endl;
  cout << "Vec capacity: " << vec.capacity() << endl; 
}

void test3() {
  cout << "\nTest3 ====================" << endl;
  vector<int> vec{1,2,3,4,5};
  display1(vec);
  vec.at(0)=100; // Do bounds checking
  vec[1]=200;
  display1(vec);
}

void test4() {
  cout << "\nTest4 =====================" << endl;
  vector<Person> stooges;

  Person p1("Larry", 18);
  display1(stooges);

  stooges.push_back(p1);
  display1(stooges);

  stooges.push_back(Person{"Moe", 19});
  display1(stooges);

  stooges.emplace_back("Curly", 20);
  display1(stooges);
}

void test5() {
  cout << "\nTest5 ======================" << endl;

  vector<Person> stooges {
    {"Larry", 18},
    {"Moe", 25},
    {"Curly", 28}
  };

  display1(stooges);

  cout << "\nFront: " << stooges.front() << endl;
  cout << "\nBack: " << stooges.back() << endl;

  stooges.pop_back(); // Removing last element from the vector
  display1(stooges);

}

void test6() {
  cout << "\nTest6 ========================" << endl;

  vector<int> vec{1,2,3,4,5};
  display1(vec);

  vec.clear();
  display1(vec);

  vec = {1,2,3,4,5,6,7,8,9,10};
  display1(vec);

  vec.erase(vec.begin(), vec.begin() + 2);
  display1(vec);

  vec = {1,2,3,4,5,6,7,8,9,10};
  auto it = vec.begin();

  while(it != vec.end()) {
    if(*it%2 == 0) {
      vec.erase(it);
    } else {
      it++;
    }
  }

  display1(vec);
}

void test7() {
  cout << "\nTest7 =======================" << endl;

  vector<int> vec1{1,2,3,4,5,6};
  vector<int> vec2{10,20,30,40};

  display1(vec1);
  display1(vec2);

  cout << "Swapping two vectors" << endl;
  vec1.swap(vec2);

  display1(vec1);
  display1(vec2);
  
}

void test8() {
  cout << "\nTest8 ====================" << endl;
  vector<int> vec{1,14,6,19,4,6,};
  display1(vec);

  sort(vec.begin(), vec.end());

  display1(vec);
}

void test9() {
  cout << "\nTest9 =====================" << endl;

  vector<int> vec1{1,2,3,4,5};
  vector<int> vec2{10,20};

  display1(vec1);
  display1(vec2);

  copy(vec1.begin(), vec1.end(), back_inserter(vec2));

  display1(vec1);
  display1(vec2);

  // Copy the element if it is even
  vec1 = {1,2,3,4,5,6,7,8,9,10};
  vec2 = {10,20};

  copy_if(vec1.begin(), vec1.end(),back_inserter(vec2), [](int x) { return x%2 == 0; });

  display1(vec1);
  display1(vec2);

}

void test10() {
  cout << "\nTest10 ======================" << endl;

  vector<int> vec1{1,2,3,4,5};
  vector<int> vec2{10,20,30,40,50};
  vector<int> vec3;

  transform(vec1.begin(), vec1.end(), vec2.begin(), back_inserter(vec3),
    [](int x, int y){return x*y;});
  
  display1(vec3);
}

void test11() {
  cout << "\nTest11 =======================" << endl;

  vector<int> vec1{1,2,3,5,6,7,8,9,10};
  vector<int> vec2{100,200,300,400};

  display1(vec1);
  display1(vec2);

  auto it = find(vec1.begin(), vec1.end(), 5);

  if(it != vec1.end()) {
    cout << "inserting..." << endl;
    vec1.insert(it, vec2.begin(), vec2.end());
  } else {
    cout << "Sorry, 5 not found" << endl;
  }

  display1(vec1);

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
  test9();
  test10();
  test11();

  return 0;
}