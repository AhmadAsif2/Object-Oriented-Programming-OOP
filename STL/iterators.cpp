#include <iostream>
#include <vector>

int main() {

  std::vector<int> vec {1, 2, 3};

  // Reverse iterator
  std::vector <int>::reverse_iterator it = vec.rbegin();

  while(it != vec.rend()) {
    std::cout << *it << "  ";
    it++;
  }

  // Using range based for loops
  for(auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << "  ";
  }

  return 0;
}