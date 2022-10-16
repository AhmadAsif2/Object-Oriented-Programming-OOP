#include <iostream>
#include <queue>

class Person {
  private:
    std::string name;
    int age;

    friend std::ostream &operator<<(std::ostream &os, const Person &obj) {
      os << obj.name << ":" << obj.age << " ";
      return os;
    }

  public:
    Person() = default;

    Person(std::string name, int age) 
      :name(name), age(age) { }

    bool operator<(const Person &rhs) const {
      return this->age < rhs.age;
    }

    bool operator==(const Person &rhs) const {
      return (this->name == rhs.name && this->age == rhs.age);
    }
};

template <typename T>
void display(std::priority_queue<T> pq) {
  std::cout << "[";
  while(!pq.empty()) {
    T elem = pq.top();
    pq.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  
  std::priority_queue<int> pq;

  for(int i: {33,4,55,78,99,1,3,5})
    pq.push(i);

  display(pq);

  std::cout << "Size: " << pq.size() << std::endl;
  std::cout << "Top: " << pq.top() << std::endl;

  pq.pop();
  display(pq);
}

void test2() {
  std::cout << std::endl;

  std::priority_queue<Person> pq;

  pq.push(Person{"A", 10});
  pq.push(Person{"B", 1});
  pq.push(Person{"C", 17});
  pq.push(Person{"D", 8});
  pq.push(Person{"E", 4});

  display(pq);
}
int main() {

  test1();
  test2();

  return 0;
}