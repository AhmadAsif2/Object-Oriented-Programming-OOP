#include <iostream>
#include <string>
using namespace std;

class Player {
    public:
        //class attributes
        string name;
        int health;
        int xp;
        

        //class methods
        void talk(string name);
        bool isDead();
        void destroy(string player);
};
int main () {
    //creating object
    Player player;

    //->Accessing class attributes and methods through dot. operator
    player.name = "Ahmad";
    player.health = 100;
    player.xp = 12;

    //does not perform anything because the method does not declare yet.We have to declare it..

    // player.talk("Ahmad");

    //we can also access class attributes and methods through pointers
    Player *enemy = new Player();
    

    // (*enemy).destroy("xp");

    //another way
    // enemy->destroy("xp");
    //Both are correct but arrow operator is much more readable so we can use that

    //delete enemy; must ensure to deallaocate the memory

    return 0;
}