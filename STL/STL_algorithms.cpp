#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using functors
struct squareFunctor {
  void operator()(int x) {
    cout << x * x << " ";
  }
  // Using functions
  void squareNumber(int x) {
  cout << x * x << " ";
  }
};

int main() {
  squareFunctor square;
  vector<int> vec {1, 2, 4, 5};
  
  auto loc = find(vec.begin(), vec.end(), 4); // In case elm is not found it returns vec.end()
  while(loc != vec.end()) {
    cout << *loc << endl;
    loc++;
  }

  for_each(vec.begin(), vec.end(), square);
  cout<<endl;
  // Using lambdas
  for_each(vec.begin(), vec.end(), [](int x) {
    cout << x * x << " ";
  });

  cout<<endl;
  return 0;
}