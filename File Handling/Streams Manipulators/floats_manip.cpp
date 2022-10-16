#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  double num1 = 123456789.987654321;
  double num2 = 1234.5678;
  double num3 = 1234;

  cout << setprecision(8);
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout << "--------------------------" << endl;
  cout << setprecision(3) << fixed; // fixed (set the prescision after the point)
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  return 0;
}