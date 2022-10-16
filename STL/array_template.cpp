// Array template
#include <iostream>
#include <string>

template<typename T, int N>
class Array {
  private:
    int size = N; // The N needs to be known at compile time
    T values[N];

    // Overloaded insertion operator
    friend std::ostream &operator<<(std::ostream& os, Array<T, N> &arr) {
      os << "[ ";
      for(const auto &val: arr.values) {
        os << val << " ";
      }
      os << " ]";
      return os;
    }

  public:
    // Default Constructor
    Array() = default;

    // Overloaded Constructor
    Array(T initValue) {
      for(auto &items: values) {
        items = initValue;
      }
    }

    // functions that fills values in the array
    void fill(T val) {
      for(auto &item: values) {
        item = val;
      }
    }

    // returning the size of the array template
    int getSize() const {
      return size;
    }

    // Overloaded subscript operator
    T &operator[](int index) {
      return values[index];
    }
};

int main() {
  // Using generic array template
  Array<int, 10> arr(10);
  std::cout << "Size of array is: " << arr.getSize() << std::endl;
  std::cout << arr << std::endl;


  Array<std::string, 10>arr1;
  arr1.fill(std::string{"Ahmad"});
  std::cout << arr1 << std::endl;

  arr1[0] = 'X';
  arr1[3] = 'X';

  std::cout << arr1 << std::endl;
  arr1.fill(std::string{"X"});
  std::cout << arr1 << std::endl;

  return 0;
}