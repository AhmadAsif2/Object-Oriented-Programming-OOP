#include <iostream>
#include <string>
using namespace std;

class Player{
    string name;
    int health;
    int xp;
    public:
        void set_name(string name) {
            this->name = name;
        }
        //Overloaded constructors
        Player(){
            cout << "No arguments constructor called" << endl;
        }
        Player (string name) {
            cout << "String arg constructor called " << endl;
        }
        Player (string name, int health, int xp) {
            cout << "Three arguments constructors called" << endl;
        }
        
        //Destructor called
        ~Player(){
            cout << "Destructor executed" << endl;
        }

};
using namespace std;
int main () {
    {
        Player ahmad("Ahmad");
        Player hero("Ahmad", 100, 22);
        Player player();
    
    }

    {
    Player *enemy = new Player ("Ahmad", 300, 34);
    enemy->set_name("drag");
    delete enemy;
    }




    return 0;
}