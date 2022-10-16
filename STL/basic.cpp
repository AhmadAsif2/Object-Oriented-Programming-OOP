#include <iostream>
#include <vector>
#include <algorithm>

// Using Macros in generic programming
#define MAX(a, b) ((a > b) ? a : b)
#define square(a) ((a) * (a)) // Parenthesis must be included otherwise wrong answer

int main()
{
  // STL container
  std::vector<int> v = {1, 5, 3};

  std::reverse(v.begin(), v.end()); // Iterator
  std::sort(v.begin(), v.end());

  for (auto vec : v)
  {
    std::cout << vec << " ";
  }

  std::cout << std::endl;
  int result = MAX(4, 2);

  std::cout << "Square of the number is: " << square(5) << std::endl;

  int answer = 100 / square(5); // 4
  std::cout << answer << std::endl;

  std::cout << "Max number: " << result << std::endl;

  return 0;
}