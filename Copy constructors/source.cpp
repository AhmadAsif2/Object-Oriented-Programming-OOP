#include <iostream>
using namespace std;
class Player{
    string name;
    int health;
    int xp;
    public:
        string get_name() {return name;}
        int get_health() {return health;}
        int get_xp() {return xp;}
        Player(string name_val = "None", int health_val = 0, int xp_val = 0);
        void display_player(Player p);

        //copy constructor
        Player(const Player &source);

        //Destructor
        ~Player(){cout << "Destructor is being called for " << name << endl;}
};
//Definition of constructor
Player ::Player(string name_val, int health_val, int xp_val) {
    name = name_val;
    health = health_val;
    xp = xp_val;
}
//copy constructor
Player::Player (const Player &source) {
    name = source.name;
    health = source.health;
    xp = source.xp;
    cout << "Copy constructor executed " << source.name << endl;
}
void display_player(Player p) {
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "Xp: " << p.get_xp() << endl;
}

int main() {

    Player empty("colin", 100, 50);
    Player my_new_object(empty);

    // display_player(empty);

    Player obj1("Ahmad");
    Player obj2("Hero", 100);
    Player obj3("Villian", 100, 45);
    // Player obj4(obj3);

    return 0;
}