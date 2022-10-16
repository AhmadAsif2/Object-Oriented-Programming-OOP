#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool findSubstring(const string &wordtoFind, const string &target)
{
  size_t found = target.find(wordtoFind);
  if (found == string::npos)
  {
    return false;
  }
  return true;
}

int main()
{
  string wordtoFound;
  string wordRead;
  int matchCount = 0;
  int wordCount = 0;

  ifstream inFile;
  inFile.open("romeoandjuliet.txt");

  if (!inFile)
    cerr << "Problem opening file" << endl;
  else
  {
    cout << "Enter the substring to searched for: ";
    cin >> wordtoFound;
    while (inFile >> wordRead)
    {
      ++wordCount;
      if (findSubstring(wordtoFound, wordRead))
      {
        ++matchCount;
        cout << wordRead << " ";
      }
    }
  }
  inFile.close();

  cout << wordCount << " words were searched..." << endl;
  cout << "The substring " << wordtoFound << " was found " << matchCount << " times" << endl;

  return 0;
}