#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string line;
  ofstream outFile("output.txt", ios::app); // By default truncation mode
  // We need to append the file

  if (!outFile)
  {
    cerr << "Error creating file" << endl;
    exit(1);
  }

  cout << "Enter something to write to the file: ";
  getline(cin, line);

  outFile << line << endl;

  outFile.close();

  return 0;
}