#include <iostream>
#include <vector>
using namespace std;
int main() {

  const int n = 3;
  int arr[n] = {10,20,30};

  // Stateless Lambda expression
  auto sum = [](int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      sum += arr[i];
    }
    return sum;
  };

  cout << sum(arr, 3) << endl;

  int testScore1 = 77;
  int testScore2 = 80;

  // Passing by reference
  // No need to return value
  // auto bonus = [] (int &score1, int &score2, int bonusPoints) {
  //   score1 += bonusPoints;
  //   score2 += bonusPoints;
  // };

  // bonus(testScore1, testScore2, 5);
  // cout << "Test Score 1: " << testScore1 << endl;
  // cout << "Test Score 2: " << testScore2 << endl;

  // *********//////////**************/////////////
  // Using pointer parameter
  auto bonus = [](int *score1, int *score2, int bonusPoints) {
    *score1 += bonusPoints;
    *score2 += bonusPoints;
  };

  bonus(&testScore1, &testScore2, 4);
  cout << "Test Score 1: " << testScore1 << endl;
  cout << "Test Score 2: " << testScore2 << endl;
  

  // Using vector as parameter
  vector<int> vec{90,87,78,66};
  auto scores = [](vector<int> &score, int bonusScore) {
    for(auto &vec: score)
      vec += bonusScore;
  };

  scores(vec, 8); 

  for (int i = 0; i < vec.size(); ++i) {
    cout << vec[i] << endl;
  }

  int num1 = 20;
  float num2 = 34.78;

  auto l = [](auto num){ 
    cout << num << endl;
  };

  l(num1);
  l(num2);

  return 0;

}