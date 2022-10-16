#include <iostream>
#include <string>
using namespace std;
class Player {
    private:
        //attributes
        string name {"P1"};
        int health;
        int xp;
    public:
        //methods
        void talk(string text_to_say) {cout << name << " says " << text_to_say << endl;}
        bool is_dead();

};
int main () {

    Player player;
    // player.name = "P1";gives complier error because it is private
    player.talk("Hello there");
    
    return 0;
}