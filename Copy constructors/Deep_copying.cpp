#include <iostream>
using namespace std;
class Deep{
    int *data;
    public:
        void set_data_value(int d) {*data = d;}
        Deep(int d) {
            data = new int;
            *data = d;
        }
        Deep(const Deep &obj) {
            data = new int;
            *data = *obj.data;
        }
        ~Deep(){
            delete data;
            cout << "Destructor exucuted" << endl;
        }
        int get_data_value(){
            return *data;
        }
        void display_data(Deep p) {
            cout << p.get_data_value() << endl;
        }
};
int main() {

    Deep obj(100);
    obj.get_data_value();

    Deep obj1(obj);
    obj1.display_data(obj);


    return 0;
}