#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

  int num;
  cout << "Enter the number: ";
  cin >> num;

  // Setting manipulators
  cout.setf(ios::showpos);
  cout.setf(ios::uppercase);
  cout.setf(ios::showbase);

  // Alternaive way
  // cout << showbase;
  // cout << showpos;
  // cout << uppercase;
  // cout << "Decimal: " << dec << num << endl;
  // cout << "Hexadecimal: " << hex << num << endl;
  // cout << "Octal: " << oct << num << endl;

  cout << "Decimal: " << dec << num << endl;
  cout << "hexadecimal: " << hex << num << endl;
  cout << "Octal: " << oct << num << endl;

  return 0;
}