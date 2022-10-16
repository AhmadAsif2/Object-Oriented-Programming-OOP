// Scoped Enumerations
#include <iostream>
#include <vector>

using namespace std;

enum class GroceryItem
{
  Milk = 250,
  Bread = 100,
  Apple = 200,
  Orange = 280
};

std::ostream &operator<<(std::ostream &os, GroceryItem groceryItem){
  underlying_type_t<GroceryItem> value = underlying_type_t<GroceryItem>(groceryItem);

  switch(groceryItem) {
    case GroceryItem::Apple:
      os << "Apple";
      break;

    case GroceryItem::Bread:
      os << "Bread";
      break;
    case GroceryItem::Milk:
      os << "Milk";
      break;
    case GroceryItem::Orange:
      os << "Orange";
      break;
    
    default:
      os << "Unknown Grocery Item";
      break;
  }

  os << ":" << value;
  return os;
}

bool isValidGroceryItem(GroceryItem groceryItem) {
  switch(groceryItem) {
    case GroceryItem::Apple:
    case GroceryItem::Bread:
    case GroceryItem::Milk:
    case GroceryItem::Orange:
      return true;
    default:
     return false;
  }
}


void displayGroceryList(vector<GroceryItem> &groceryList) {
  cout << "Grocery List" << endl;
  int validGroceryItem = 0;
  int invalidGroceryItem = 0;

  for(GroceryItem groceryItem: groceryList) {
    cout << groceryItem << endl;

    if(isValidGroceryItem(groceryItem))
      validGroceryItem++;
    else
      invalidGroceryItem++;
  } 

  cout << "============================" << endl;
  cout << "Valid Items: " << validGroceryItem << endl;
  cout << "Invalid items: " << invalidGroceryItem << endl;
  cout << "Total items: " << validGroceryItem + invalidGroceryItem << endl;  
}

void test1() {
  vector<GroceryItem> groceryItem;
  groceryItem.push_back(GroceryItem::Apple);
  groceryItem.push_back(GroceryItem::Orange);
  groceryItem.push_back(GroceryItem::Milk);

  int helicopter = 100;

  groceryItem.push_back(GroceryItem(helicopter));
  groceryItem.push_back(GroceryItem(280));

  displayGroceryList(groceryItem);
}

int main()
{
  test1();
  return 0;
}