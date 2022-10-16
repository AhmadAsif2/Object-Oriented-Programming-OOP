#include <iostream>
#include <string>
using namespace std;
class Player{
    string name;
    static int num_players;
    int health;
    int xp;
    public:
        Player(){cout << "Active Players: " << num_players << endl;}
        Player(string n, int h, int x){
            name = n;
            health = h;
            xp = x;
        }
        void display_active_players(){
            ++num_players;
            cout << "Active Players: " << num_players << endl;
        }

        ~Player(){
            cout << --num_players << endl;
        }
        
};
int Player::num_players = 0;


int main (){

    Player empty;

    Player obj1("Ahmad", 100, 34);
    obj1.display_active_players();
    Player obj2("Ahmad", 100, 24);
    obj2.display_active_players();
    

    return 0;
}