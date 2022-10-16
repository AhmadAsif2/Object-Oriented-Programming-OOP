#include <iostream>
using namespace std;
class Data {
    private:
        int a, b, c;
    public:
        // Data(){
            
        // }
        Data(int x, int y = 9, int z = 10) {
            a = x;
            b = y;
            c = z;
        }
        void getData() {
            cout << "the values are " << a <<"," << b <<" and "<< c << endl;
        }
};
int  main() {

    Data obj(3, 10, 12);
    obj.getData();

    return 0;
}
