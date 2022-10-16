#include <queue>
#include <iostream>

using namespace std;

template <typename T>
void display(queue<T> q) // Passing the copy of the value because we don't want to destroy it
{
  cout << "[";
  while(!q.empty()) {
    T elem = q.front();
    q.pop();
    cout << elem << " ";
  }
  cout << "]" << endl;
}

int main() {

  queue<int> q; // deque
  for(int i: {1,2,3,4,5})
    q.push(i);
  
  display(q);
  cout << "Front: " << q.front() << endl;
  cout << "Back: " << q.back() << endl;

  q.push(100);
  display(q);

  q.pop();
  q.pop();

  display(q);

  while(!q.empty()) {
    q.pop();
  }
  display(q);

  cout << "Size of queue: " << q.size() <<endl;

  q.push(10);
  q.push(20);
  q.push(30);

  display(q);

  q.front() = 100;
  q.back() = 200;

  display(q);

  cout << q.front() << endl;
  cout << q.back() << endl;

  return 0;
}