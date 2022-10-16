#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
  ofstream outFile("copy1.txt");
  ifstream inFile("test.txt");

  if (!outFile)
  {
    cerr << "Error creating file" << endl;
    return 1;
  }

  if (!inFile)
  {
    cerr << "Problem opening file" << endl;
    return 1;
  }

  string line;
  while (getline(inFile, line))
  {
    outFile << line << endl;
  }

  cout << "File copied" << endl;

  inFile.close();
  outFile.close();

  return 0;
}