#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

class Person {
  private:
    string name;
    int age;
  public:
    Person() = default;

    Person(string name, int age)
      : name(name), age(age) { }
    
    bool operator<(const Person &obj) {
      return this->age < obj.age;
    }

    bool operator==(const Person &rhs) {
      return (this->name == rhs.name && this->age == rhs.age);
    }
};

// find the specific element in the container
void findTest() {
  cout << "=======================" << endl;
  vector<int> vec {1, 2, 3, 4, 5};
  auto loc = find(begin(vec), end(vec), 1);

  if (loc != end(vec)) 
    cout << "Found the number " << *loc << endl;
  else 
    cout << "Number not found" << endl;
  

  list<Person> persons {
    {"Ahmad", 19},
    {"Hamza", 20}, 
    {"Moe", 24}
  };

  auto loc1 = find(persons.begin(), persons.end(), Person{"Ahmad", 19});
  if(loc1 != persons.end()) 
    cout << "Ahmad found" << endl;
  else  
    cout << "Ahmad not found" << endl;
}

// Count the number of elements in a container
void countTest() {
  cout << "======================" << endl;
  vector<int> vec {1, 2, 3, 4, 1, 4, 5, 1};

  int num = count(vec.begin(), vec.end(), 1);

  cout << num << " occurences found" << endl;
}

// Count if test -> count the number of elements if condition is true
void countifTest() {

  cout << "======================" << endl;
  vector<int> vec {1, 2, 3, 4, 5, 1, 100, 98};

  int num = count_if(begin(vec), end(vec),[](int x){
    return (x%2 == 0);
  });

  cout << num << " numbers are even" << endl;

  num = count_if(begin(vec), end(vec), [](int x){
    return (x%2 != 0);
  });

  cout << num << " numbers are odd" << endl;

  num = count_if(vec.begin(), vec.end(),[](int x){
    return (x > 5);
  });

  cout << num << " numbers are > 5" << endl;
}

// replace element with another element
void replaceElm() {
  cout << "=========================" << endl;
  vector<int> vec {1, 2, 7, 7, 1, 34, 1};

  for(auto &i: vec) {
    cout << i << " ";
  }

  cout <<endl;
  replace(begin(vec), end(vec), 1, 100);

  for(auto &i: vec) {
    cout << i << " ";
  }
}

// check all the elements
void allOfTest() {
  cout << "\n=====================" << endl;
  vector<int> vec {1, 2, 3, 5, 6, 19, 14};

  if (all_of(vec.begin(), vec.end(), [](int x){ return x > 20; }))
    cout << "All elements are greater than 20" << endl;
  else
    cout << "Not all elements are greater than 20" << endl;
  
  if (all_of(vec.begin(), vec.end(), [](int x){ return x < 20;}))
    cout << "All elements are less than 20" << endl;
  else
    cout << "Not all elements are less than 20" << endl;
  
}

// Transform the elements in the container(string in this case)
void stringTransforTest() {
  cout << "=========================" << endl;

  string s1 = "This is a test";

  cout << "Before transform: " << s1 << endl;
  transform(begin(s1), end(s1), s1.begin(), ::toupper);
  cout << "After transform: " << s1 <<endl;
}

int main() {

  findTest();
  countTest();
  countifTest();
  replaceElm();
  allOfTest();
  stringTransforTest();

  cout << endl;
  system("pause");
  exit(0);
  return 0;
}