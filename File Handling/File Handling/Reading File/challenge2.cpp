// Automated Grader
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// function that prints the header
void printHead()
{
  cout << setw(15) << left << "Student" << setw(5) << right << "Score" << endl;
  cout << setw(20) << setfill('-') << "" << endl;
  // Reset setfill
  cout << setfill(' ');
}

// function that returns the score of the student
int printScore(string resultKey, string studentResponse)
{
  int score = 0;
  for (size_t i = 0; i < resultKey.length(); ++i)
  {
    if (resultKey.at(i) == studentResponse.at(i))
      score++;
  }
  return score;
}

// function that prints student's name and score
void printStudent(string studentName, int score)
{
  cout << setw(15) << left << studentName << setw(5) << right << score << endl;
}

// function that prints the footer
void printFooter(double averageScore)
{
  cout << setw(20) << setfill('-') << "" << endl;
  cout << setfill(' '); // Resetting fill
  cout << setw(15) << left << "Average Score: " << setw(5) << right << averageScore << endl;
}

// Main function
int main()
{
  double resultSum = 0;
  double averageScore = 0;
  int totalStudents = 0;
  string resultKey, studentName, studentResponse;

  // Creating the file stream obj that reads the file
  ifstream inFile;

  // Opening the file
  inFile.open("challenge2.txt");

  // Reading only first line of file
  inFile >> resultKey;

  // Checking file is opened successfully or not
  if (!inFile.is_open())
  {
    cerr << "File not opened" << endl;
    exit(1);
  }
  else
  {
    // Logic Section
    printHead();
    while (inFile >> studentName >> studentResponse)
    {
      ++totalStudents;
      int score = printScore(resultKey, studentResponse);
      printStudent(studentName, score);
      resultSum += score;
    }
    averageScore = static_cast<double>(resultSum) / totalStudents;
    printFooter(averageScore);
  }

  // Closing the file
  inFile.close();

  cout << endl;

  return 0;
}