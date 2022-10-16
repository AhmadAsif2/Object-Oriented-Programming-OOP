#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  ifstream inFile("romeoandjuliet.txt");
  ofstream outFile("challenge.txt");

  if (!inFile.is_open())
  {
    cerr << "Error opening file" << endl;
    return 1;
  }

  if (!outFile)
  {
    cerr << "Error creating file" << endl;
    return 1;
  }

  string line;
  int numOfLines = 0;

  while (getline(inFile, line))
  {
    if (line == "")
    {
      outFile << endl;
    }
    else
    {
      outFile << setw(10) << left << ++numOfLines << line << endl;
    }
  }

  cout << "File copied successfully" << endl;

  inFile.close();
  outFile.close();

  return 0;
}