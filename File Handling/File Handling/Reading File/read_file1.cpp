#include <iostream>
#include <fstream>
#include <string>

int main()
{

  std::ifstream in_file;
  in_file.open("test.txt");

  if (!in_file.is_open())
  {
    std::cerr << "Problem opening file" << std::endl;
    return 1;
  }

  // std::string line;
  // // Reading using C++ strings
  // while (std::getline(in_file, line))
  // {
  //   std::cout << line << std::endl;
  // }

  // Reading using C strings
  char c;
  while (in_file.get(c))
  {
    std::cout << c;
  }

  in_file.close();

  return 0;
}