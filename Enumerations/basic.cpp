// Unscoped enumerations
#include <iostream>
#include <vector>
using namespace std;

enum Direction 
{
  North,
  South,
  East,
  West
};

string directiontoString(Direction direction) {
  string result;
  switch (direction)
  {
  case North:
    result = "North";
    break;
  case South:
    result = "South";
    break;
  case East:
    result = "East";
    break;
  case West:
    result = "West";
    break;
  default:
    cout << "Unknown direction" << endl;
    break;
  }
  return result;
}

void test1() {
  cout << "\nTest1 ----------------------" << endl;
  Direction direction{North};
  cout << "Direction: " << direction << endl;
  cout << directiontoString(direction) << endl;

  direction = South;
  cout << "Direction: " << direction << endl;
  cout << directiontoString(direction) << endl;

  direction = Direction(100);
  cout << "Direction: " << direction << endl;
  cout << directiontoString(direction) << endl;

}

enum GroceryItem
{
  Milk,
  Bread,
  Apple,
  Orange
};

std::ostream &operator<<(std::ostream &os, GroceryItem item) {
  switch(item) {
    case Milk:
      os << "Milk";
      break;
    case Bread:
      os << "Bread";
      break;
    case Apple:
      os << "Apple";
      break;
    case Orange:
      os << "Orange";
      break;
    default:
      cout << "Unknown Grocery Item";
      break;
  }
  return os;
}

bool isValidGroceryItem(GroceryItem groceryItem) {
  switch(groceryItem) {
    case Milk:
    case Bread:
    case Apple:
    case Orange:
      return true;
    default:
      return false;
  }
}

void displaygroceryList(const vector<GroceryItem> &groceryList) {
  cout << "Grocery list" << endl;

  int countvalidItem = 0;
  int countinvalidItem = 0;

  for(GroceryItem groceryItem: groceryList) {
    cout << groceryItem << endl;

    if(isValidGroceryItem(groceryItem))
      countvalidItem++;
    else
      countinvalidItem++;
  }

  cout << "=================================" << endl;
  cout << "Valid items: " << countvalidItem << endl;
  cout << "Invalid items: " << countinvalidItem << endl;
  cout << "Total items: " << countinvalidItem + countvalidItem << endl;
}

void test2() {
  vector<GroceryItem> shoppinglist;
  shoppinglist.push_back(Apple);
  shoppinglist.push_back(Apple);
  shoppinglist.push_back(Milk);
  shoppinglist.push_back(Orange);

  int helicopter = 100;

  shoppinglist.push_back(GroceryItem(helicopter));
  shoppinglist.push_back(GroceryItem(0)); // Will add milk

  displaygroceryList(shoppinglist);
}

enum State 
{
  EngineFailure,
  InclementWeather,
  Nominal,
  Unknown
};

enum Sequence
{
  Abbort,
  Hold,
  Launch
};

std::istream &operator>>(std::istream &is, State &state) {
  underlying_type_t<State> userInput;

  is >> userInput;

  switch (userInput)
  {
  case EngineFailure:
  case InclementWeather:
  case Nominal:
  case Unknown:
    state = State(userInput);
    break;
  
  default:
    cout << "User input is not a valid launch state" << endl;
    state = Unknown;
    break;
  }

  return is;
}

std::ostream &operator<<(std::ostream &os, Sequence &sequence) {
  switch (sequence)
  {
  case Abbort:
    os << "Abbort";
    break;
  case Hold:
    os << "Hold";
    break;
  case Launch:
    os << "Launch";
    break;
  }
  return os;
}

void initiate(Sequence sequence) {
  cout << "Initiate: " << sequence << " sequence!" << endl;
}

void test3() {
  cout << "\nTest3 ----------------------" << endl;
  State state;
  cout << "Launch Sate: ";
  cin >> state;

  switch(state) {
    case EngineFailure:
    case Unknown:
      initiate(Abbort);
      break;
    case InclementWeather:
      initiate(Hold);
      break;
    case Nominal:
      initiate(Launch);
      break;
  }
}

int main() {
  // test1();
  // test2();
  test3();
  return 0;
}


