#include <iostream>
#include <string>
using namespace std;

class Player {
    string name;
    int health;
    int xp;
    public:
        void setData(string name) {
            this->name = name;
        }

        //Default constructor
        Player () {
            cout << "Default constructor called" << endl;
            name = "None";
            health = 100;
            xp = 20;
        }

        //parametrized constructor
        Player(string name, int health, int xp) {
            this->name = name;
            this->health = health;
            this->xp = xp;
        }


};
int main () {
    //Default constructor called
    Player player;//automaticaly set's values to constructors
    player.setData("Ahmad");//set default constructor name to Ahmad


    return 0;
}