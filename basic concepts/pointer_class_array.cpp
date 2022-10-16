#include <iostream>
using namespace std;

class ShopItem {
    int id;
    float price;
    public:
        void setData(int a, float b) {

            id = a;
            price = b;
        }

        void getData() {
            
            cout << "Item Id is " << id << endl;
            cout << "Item price is " << price << endl;
        }
};
int main ()
{

    const int size = 3;
    ShopItem* ptr = new ShopItem[size];
    ShopItem* ptr1 = ptr;

    int p;
    float q;

    for (int i = 0; i < size; i++) {
        cout << "Enter item id and price for item number " << i + 1 << endl;
        cin >> p >> q;
        ptr->setData(p, q);
        ptr++;
    }

    for (int i = 0; i < size; i++) {
        cout << "price and item id for item " << i + 1 << endl;
        ptr1->getData();
        ptr1++;
    }

    
    return 0;
}