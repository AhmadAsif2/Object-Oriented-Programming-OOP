#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void test1() {
  cout << "\n--Test1 --------------------" << endl;

  vector<int> vec{10,20,30,40,50};
  for_each(vec.begin(), vec.end(), [](int num){
    cout <<num << " ";
  });
}

void test2() {
  cout << "\n--Test2 --------------------" << endl;

  struct Point
  {
    /* data */
    int x;
    int y;
  };

  Point pt1{1,2};
  Point pt2{4,3};
  Point pt3{3,5};
  Point pt4{3,1};

  vector<Point> triangle1{pt1,pt2,pt3};
  vector<Point> triangle2{pt2,pt3,pt1};
  vector<Point> triangle3{pt1,pt2,pt4};

  if(is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(),
  [](Point lhs, Point rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }))
    cout << "Triangle 1 and Triangle 2 are equilant" << endl;
  else  
    cout << "Triangle 1 and Triangle 2 are not equilant" << endl;

  if(is_permutation(triangle2.begin(), triangle2.end(), triangle3.begin(),
  [](Point lhs, Point rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }))
    cout << "Triangle 2 and Triangle 3 are equilant" << endl;
  else
    cout << "Triangle 2 and Triangle 3 are not equilant" << endl;
}

void test3() {
  cout << "\n--Test3 --------------------" << endl;

  vector<int> scores{95,78,67,88,90};

  int bonusPoints = 5;

  transform(scores.begin(), scores.end(), scores.begin(), [bonusPoints](int score){
    return score += bonusPoints;
  });

  for(int score: scores) {
    cout << score << " ";
  }
}

void test4() {
  cout << "\n--Test4 --------------------" << endl;
  vector<int> nums{1,2,3,4,5};

  nums.erase(remove_if(nums.begin(), nums.end(), [](int x){
    return x%2 == 0;
  }),nums.end());

  for(int num: nums) {
    cout << num << " ";
  }
}


class Person 
{
  private:
    string name;
    int age;
    friend std::ostream &operator<<(std::ostream &os, const Person &obj) {
      os << obj.name << ":" << obj.age << " ";
      return os;
    }

  public:
    Person() = default;
    Person(const Person &p)
      :name (p.name), age(p.age) { }
    Person(string name, int age)
      : name(name), age(age){}

    ~Person()= default;

    string getName() const { return name; }
    int getAge() const { return age; }

    void setName(string name) {
      this->name = name;
    }

    void setAge(int age) {
      this->age = age;
    }
};

void test5() {
  cout << "\n--Test5 --------------------" << endl;

  Person p1{"Larry", 19};
  Person p2{"Moe", 25};
  Person p3{"Curly", 29};

  vector<Person> people{p1,p2,p3};

  // Sorting by name
  sort(people.begin(), people.end(), [](Person lhs, Person rhs){
    return lhs.getName() < rhs.getName();
  });

  for(auto vec: people) {
    cout << vec << " ";
  }

  cout << endl;

  // Sorting by age
  sort(people.begin(), people.end(), [](Person lhs, Person rhs){
    return lhs.getAge() < rhs.getAge();
  });

  for(auto vec: people) {
    cout << vec << " ";
  }
}

// function that returns value in between the numbers
bool inBetween(vector<int> vec, int startValue, int endValue) {
  bool result = false;
  result = all_of(vec.begin(), vec.end(), [startValue, endValue](int num){
    return num>=startValue && num<=endValue;
  });
  return result;
}

void test6() {
  cout << "\n--Test6 --------------------" << endl;

  vector<int> nums(10);
  iota(nums.begin(), nums.end(), 1); // increment the value by 1

  cout << boolalpha;

  cout << inBetween(nums, 10, 20)<< endl;
  cout << inBetween(nums,1,10) <<endl;
  cout << inBetween(nums,20, 30) << endl;

}

class PasswordValidator1
{
  private:
    char invalidSymbol = '$';
  public:
    bool isValid(string password) {
      return all_of(password.begin(), password.end(),[this](char character){
        return character != invalidSymbol;
      });
    }
};

class PasswordValidator2
{
  private:
    vector<char> restrictedSymbol{'+','$','!'};
  public:
    bool isValid(string password) {
      return all_of(password.begin(), password.end(),[this](char character){
        return none_of(restrictedSymbol.begin(), restrictedSymbol.end(),[character](char symbol){
          return character == symbol;
        });
      });
    }
};

void test7() {
  cout << "\n--Test7 --------------------" << endl;
  PasswordValidator1 pw;
  string password = "Ahmad123";

  if(pw.isValid(password))
    cout << "The password " << password << " is valid" << endl;
  else
    cout << "The password " << password << " is not valid" << endl;

  password = "Ahmad123$";
  if(pw.isValid(password))
    cout << "The password " << password << " is valid" << endl;
  else
    cout << "The password " << password << " is not valid" << endl;

  PasswordValidator2 pw1;
  string password1 = "C++Rocks!";
  if(pw1.isValid(password1))
    cout << "The password " << password1 << " is valid" << endl;
  else
    cout << "The password " << password1 << " is not valid" << endl;
  
  password1 = "CPlusPlusRocks";
  if(pw1.isValid(password1))
    cout << "The password " << password1 << " is valid" << endl;
  else
    cout << "The password " << password1 << " is not valid" << endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  return 0;
}