#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// Functor
struct Square_Functor
{
  /* data */
  // Function call operator
  int operator()(int x) {
    std::cout << x * x << " ";
  }
};

// Functor
template <typename T>
struct Displayer
{
  /* data */
  // Function call operator
  std::string operator() (const T &data) {
    std::cout << data << " ";
  }
};

class Multiplier {
  private:
    int num;
  public:
    Multiplier(int n) : num(n) {}
    int operator()(int n) const {
      return n *num;
    }
};

int main() {

  std::cout << "\nTest1 =====================" << std::endl;
  Square_Functor square;
  // square operator()(4)
  square(4); // Instantiating function object

  Displayer<int> d1;
  Displayer<std::string> d2;

  // Instantiating function objects
  d1(100); // displays 100
  d2("Ahmad"); // display Ahmad


  std::cout << "\nTest2 =====================" << std::endl;

  std::vector<int> vec{1,2,3,4,5};
  std::vector<std::string> vec1{"Larry", "Moe", "Curly"};

  std::for_each(vec.begin(), vec.end(), square); // displays square of number
  std::cout << std::endl;

  std::for_each(vec.begin(), vec.end(), Displayer<int>());
  std::cout << std::endl;
  std::for_each(vec.begin(), vec.end(), d1);
  std::cout << std::endl;

  std::for_each(vec1.begin(), vec1.end(), Displayer<std::string>());
  std::cout << std::endl;
  std::for_each(vec1.begin(), vec1.end(), d2);
  std::cout << std::endl;

  std::cout << "\nTest3 ==========================" << std::endl;

  // Using Lambdas expression instead of functors(function objects)
  std::for_each(vec.begin(), vec.end(), [](int x){
    std::cout << x*x << " ";
  });
  std::cout << std::endl;

  std::for_each(vec.begin(), vec.end(),[](int x){
    std::cout << x*10 << " ";
  });
  std::cout << std::endl;

  std::for_each(vec.begin(),vec.end(),[](int x){
    std::cout << x << " ";
  });
  std::cout << std::endl;

  std::for_each(vec1.begin(), vec1.end(),[](std::string s){
    std::cout << s << " ";
  });
  std::cout << std::endl;

  std::cout << "\nTest4 ====================" << std::endl;
  Multiplier mult(100);
  vec = {1,2,3,4};

  std::transform(vec.begin(), vec.end(), vec.begin(), mult);
  std::for_each(vec.begin(), vec.end(), d1);
  std::cout << std::endl;

  vec = {1,2,3,4};
  // Using lambda expression
  std::transform(vec.begin(), vec.end(), vec.begin(), [](int x){
    return x * 100;
  });

  std::for_each(vec.begin(), vec.end(), d1);

  return 0;
}
