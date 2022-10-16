#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

// Note that array is std::array
void display(array<int, 5> &arr) {
  cout << "[ ";
  for(const auto &i: arr) {
    cout << i << " ";
  }
  cout << "]" << endl;
} 

void testArray1() {

  cout << "\nTest 1 ===============================" << endl;
  array<int, 5> arr1 {1,2,3,4,5};
  array<int, 5> arr2;

  cout << "The size of array 1 is: " << arr1.size() << endl;
  cout << "The size of array 2 is: " << arr2.size() << endl;

  display(arr1);
  display(arr2);

  // arr2 = {1,2,3,4,5};
  arr2 = arr1;
  display(arr2);

  arr1[0] = 34; // No bounds checking
  arr1.at(1) = 38; // do bounds checking

  display(arr1);
  display(arr2);

  cout << "Front of array 1 is: " << arr1.front() << endl;
  cout << "Back of array 2 is: " << arr2.back() << endl;
}

void testArray2() {
  cout << "\nTest 2 ==========================" << endl; 
  array<int, 5> arr1 {1,2,3,4,5};
  array<int, 5> arr2 {10,20,30,40,50};

  display(arr1);
  display(arr2);

  arr1.fill(0);

  display(arr1);
  display(arr2);

  arr1.swap(arr2);
  display(arr1);
  display(arr2);
}

void testArray3() {
  cout << "\nTest 3 ===========================" << endl;
  array<int, 5> arr1{1,2,3,4,5};

  int *ptr = arr1.data();
  cout << ptr << endl;
  *ptr = 1000;
  display(arr1);
}

void testArray4() {
  cout << "\nTest 4 ===================" << endl;
  array<int, 5> arr1{2,1,4,5,3};

  display(arr1);
  sort(arr1.begin(), arr1.end());
  display(arr1);
}

void testArray5() {
  cout << "\nTest 5 ==================" << endl;
  
  array<int, 5> arr{1,2,3,4,5};
  auto minNum = min_element(arr.begin(), arr.end());
  auto maxNum = max_element(arr.begin(), arr.end());

  cout << "min: " << *minNum << endl;
  cout << "max: " << *maxNum << endl;
}

void testArray6() {
  cout << "\nTest 6 ======================" << endl;

  array<int, 5> arr{1,2,3,3,5};
  auto adjElm = adjacent_find(arr.begin(), arr.end());
  if (adjElm != arr.end())
    cout << "Adjacent element found with value: " << *adjElm << endl;
  else
    cout << "No adjacent element found" << endl;
}

void testArray7() {
  cout << "\nTest 7 ========================" << endl;
  array<int, 5> arr{1,2,3,4,5};

  int sumArray = accumulate(arr.begin(), arr.end(), 0);
  cout << "Sum of array is: " << sumArray << endl;
}

void testArray8() {
  cout << "\nTest 8 ===========================" << endl;
  array<int, 10> arr{1,2,3,6,3,3,3,3,8,9};
  int countElm = count(arr.begin(), arr.end(), 3);

  cout << "Found 3: " << countElm << " times" << endl;
}

void testArray9() {
  cout << "\nTest 9 ===========================" << endl;

  array<int, 10> arr{5,10,20,30,40,70,180,500,600,700};

  int count = count_if(arr.begin(), arr.end(),[](int x){
    return (x > 10 && x < 200);
  });

  cout << "Number of elements found: " << count << endl;
}

int main() {

  testArray1();
  testArray2();
  testArray3();
  testArray4();
  testArray5();
  testArray6();
  testArray7();
  testArray8();
  testArray9();

  cout << endl;
  system("pause");
  return 0;
}