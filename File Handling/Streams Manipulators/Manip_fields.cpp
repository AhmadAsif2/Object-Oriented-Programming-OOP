#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{

  // setw (fied width function)
  // setfill(fill the width)

  double num1 = 1234;
  double num2 = 1234.567;
  string name = "Hello";

  cout << "1234567890123456789012345678901234567890" << endl;
  cout << setw(10) << setfill('*') << left << num1
       << setw(10) << setfill('-') << right << num2 << setw(10)
       << setfill('#') << left << name << endl;

  return 0;
}