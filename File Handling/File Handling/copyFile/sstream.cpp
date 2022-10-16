#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main()
{
  std::string name;
  int num;
  double total;

  std::string info{"Ahmad 100 1234.5"};
  // Reading from string stream
  std::istringstream iss{info};

  iss >> name >> num >> total;

  std::cout << std::setw(10) << std::left << name
            << std::setw(5) << num << std::setw(10) << total << std::endl;

  // Writing into string stream
  std::ostringstream oss{};
  oss << std::setw(10) << std::left << name
      << std::setw(5) << num << std::setw(10) << total << std::endl;

  std::cout << oss.str();

  // Data Validation using string streams
  int value = 0;
  std::string dataEntered;
  bool done = false;
  do
  {
    std::cout << "Enter the value: ";
    std::cin >> dataEntered;
    std::istringstream validator(dataEntered);

    if (validator >> value)
      done = true;
    else
      std::cout << "Sorry! that's not an integer" << std::endl;

    // discarding the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (!done);

  std::cout << "You entered the integer " << value << std::endl;

  return 0;
}