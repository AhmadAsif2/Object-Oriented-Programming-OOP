#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

template <typename T>
void display(deque<T> &deq) {
  cout << "[ ";
  for(auto &elem: deq)
    cout << elem << " ";
  cout << "]" << endl;
}

void test1() {
  cout << "\nTest1 ========================" << endl;
  deque<int> d{1,2,3,4,5,6};
  display(d);

  d = {2,4,5,6,8};
  display(d);

  deque<int> d1(10,100);
  display(d1);

  d[0] = 100;
  d.at(1) = 200;

  display(d);
}

void test2() {
  cout << "\nTest2 ==========================" << endl;

  deque<int> d{0,0,0};
  display(d);

  d.push_back(10);
  d.push_back(20);

  display(d);

  d.push_front(100);
  d.push_front(200);

  display(d);

  cout << "Front: " << d.front() << endl;
  cout << "BacK: " << d.back() << endl;
  cout << "Size: " << d.size() << endl;

  d.pop_back();
  d.pop_front();

  display(d);
}

void test3() {
  cout << "\nTest3 ======================" << endl;

  vector<int> vec{1,2,3,4,5,6,7,8,9,10};
  deque<int> d;

  display(d);

  for(auto &v: vec) {
    if(v%2 == 0)
      d.push_back(v);
    else  
      d.push_front(v);
  }

  display(d);
}

void test4() {
  cout << "\ntest4 ======================" << endl;

  vector<int> vec{1,2,3,4,5,6,7,8,9,10};
  deque<int> d;

  for(const auto &elem: vec) 
    d.push_front(elem);
  
  display(d);

  d.clear();

  for(const auto &elem: vec)
    d.push_back(elem);
  
  display(d);
}

void test5() {
  cout << "\ntest5 ====================" << endl;

  vector<int> vec{1,2,3,4,5,6,7,8,9,10};
  deque<int> d;

  copy(vec.begin(), vec.end(), front_inserter(d));

  display(d);

  d.clear();

  copy(vec.begin(), vec.end(), back_inserter(d));

  display(d);
}

int main() {

  test1();
  test2();
  test3();
  test4();
  test5();

  return 0;
}