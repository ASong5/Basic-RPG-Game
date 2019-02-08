#include <string>
using namespace std;

class Character
{
    string NAME;
    short LVL;
    float HP;
    float ARMOR;
    short DAMAGE;

    public:
        bool Battle(Character);
        Character();
        Character(short);
        string inventory[4][4]= {"health potion", "damage boost potion", " shield potion", "instakill potion",0,0,0,0};

};

class User : public Character
{
    short EXP;
    short KILLS;

    public:
        User();
};
