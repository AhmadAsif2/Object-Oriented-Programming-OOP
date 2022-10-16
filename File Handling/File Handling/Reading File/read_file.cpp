#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
int main()
{
  string line;
  int num;
  double total;
  ifstream in_file;
  in_file.open("myfile.txt");

  if (!in_file.is_open())
  {
    cerr << "File not opened" << endl;
    return 1;
  }

  while (!in_file.eof())
  {
    in_file >> line >> num >> total;
    cout << setw(10) << left << line
         << setw(10) << left << num
         << setw(10) << left << total << endl;
  }

  in_file.close();

  return 0;
}