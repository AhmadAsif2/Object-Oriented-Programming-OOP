#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

template <typename T>
void display(stack<T> s) {
  cout << "[";
  while(!s.empty()) {
    T elem = s.top();
    s.pop();
    cout << elem << " ";
  }
  cout << "]" << endl;
}

int main() {

  stack<int> s;
  for(auto elm: {1,2,3,4,5}) {
    // pushing the element on the top of the stack
    s.push(elm);
  }

  display(s);

  s.push(100);
  display(s); 

  s.pop();
  s.pop();

  display(s);

  while(!s.empty()) {
    s.pop();
  } 

  display(s);
  s.push(10);
  display(s);

  s.top() = 100;
  display(s);

  return 0;
}