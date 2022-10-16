#include <iostream>
#include <vector>

// Class template
template <typename T>
class Item
{
private:
  std::string name;
  T value;

public:
  Item(std::string name, T value)
      : name(name), value(value) { }
      
  std::string getName() {
    return name;
  }

  T getValue() {
    return value;
  }
};

// Note that template is a blue print
template <typename T1, typename T2>
struct My_Pair {
  T1 first;
  T2 second;
};

int main()
{
  Item<int> item1{"Ahmad", 19};
  std::cout << item1.getName() << "  " << item1.getValue() << std::endl;
  
  Item<std::string> item2{"Ahmad", "Asif"};
  std::cout << item2.getName() << "  " << item2.getValue() << std::endl;

  Item<Item<std::string>> item3{"Ahmad", {"C++", "Ahmad"}};
  std::cout << item3.getName() << "  " << item3.getValue().getName() << "  " 
            << item3.getValue().getValue() << std::endl;

  std::cout << "==================================" << std::endl;
  // Vector of template
  std::vector<Item<double>> vec{};
  vec.push_back(Item<double>("Ahmad", 100.0));
  vec.push_back(Item<double>("Hamza", 200.0));
  vec.push_back(Item<double>("Asif", 300.0));
  // printing values of vector
  for(auto &v: vec) {
    std::cout << v.getName() << " " << v.getValue() << std::endl;
  } 

  std::cout << "==================================" << std::endl;
  // Template of structure with typename(class)
  My_Pair<std::string, double> p1{"Ahmad", 12.4};
  My_Pair<int, double> p2{12, 4.4};

  std::cout << p1.first << "   " << p1.second << std::endl;
  std::cout << p2.first << "   " << p2.second << std::endl;

  return 0;
}