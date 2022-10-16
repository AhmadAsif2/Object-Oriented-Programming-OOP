#include <iostream>
#include <set>
#include <map>

void display(std::map<std::string, std::set<int>> &m) {
  std::cout << "[ ";
  for(const auto &elem: m) {
    std::cout << elem.first << ":[ ";
    for(const auto &setElm: elem.second) {
      std::cout << setElm << " ";
    }
    std::cout << "]";
  }
  std::cout << "] " << std::endl;
}

template <typename T1, typename T2>
void display(std::map<T1, T2> &l) {
  std::cout << "[ ";
  for(const auto &elem: l) {
    std::cout << elem.first << ":" << elem.second << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "\ntest1 ==========================" << std::endl;
  // string is key & int is a value
  // In map sorting is done by key
  // Map
  std::map<std::string, int> m {
    {"Larry", 3},
    {"Moe", 1},
    {"Curly", 2}
  };

  display(m);

  m.insert(std::pair<std::string,int>("Ahmad", 3));
  display(m);

  m.insert(std::make_pair("Joe", 5));
  display(m);

  // Inserting key by subscript
  m["Frank"] = 18;
  display(m);

  m["Frank"] += 10;
  display(m);

  m.erase("Frank");
  display(m);

  std::cout << "Count for Joe " << m.count("Joe") << std::endl;
  std::cout << "Count for Frank " << m.count("Frank") << std::endl;

  // using iterator
  auto it = m.find("Larry");
  if(it != m.end()) {
    std::cout << "Larry " << it->first << ":" << it->second << std::endl;
  }

  m.clear();
  display(m);
}

void test2() {
  std::cout << "\ntest2 =========================" << std::endl;
  std::map<std::string, std::set<int>> grades {
    {"Larry", {80}},
    {"Moe", {90, 98}},
    {"Curly", {85, 99, 100}}
  };

  display(grades);

  grades["Larry"].insert(95);
  display(grades);

  auto it = grades.find("Moe");

  if(it != grades.end()) {
    it->second.insert(100);
  }

  display(grades);
}

int main() {

  test1();
  test2();
  return 0;
}