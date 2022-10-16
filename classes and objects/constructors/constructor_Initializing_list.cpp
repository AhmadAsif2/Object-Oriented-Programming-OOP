#include <iostream>
#include <string>
using namespace std;
class Player{
    string name;
    int health;
    int xp;
    public:
        //Overloaded Constructors
        Player();
        Player(string name_val);
        Player(string name_val, int health_val, int xp_val);
        void getData() {
            cout << "\nName: " << name << endl;
            cout << "Health: " << health << endl;
            cout << "Xp: " << xp << endl;
        }

    ~Player(){}//Destructor
};

Player ::Player(): name {"Name"}, health{0}, xp{0} {

}


Player ::Player(string name_val): name{name_val}, health{0}, xp{0} {

}

Player ::Player(string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val} {
}
int main () {

    Player player;
    player.getData();

    Player player1("Ahmad");
    player1.getData();

    Player player2("Ahmad", 100, 22);
    player2.getData();

    return 0;
}