// Writing to file using char
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
  ifstream inFile("test.txt");
  ofstream outFile("copy2.txt");

  if (!inFile)
  {
    cerr << "Error opening file" << endl;
    return 1;
  }

  if (!outFile)
  {
    cerr << "Error creating file" << endl;
    return 1;
  }

  char c;

  // Writing character by character
  while (inFile.get(c))
    outFile.put(c);

  cout << "File copied" << endl;

  inFile.close();
  outFile.close();

  return 0;
}