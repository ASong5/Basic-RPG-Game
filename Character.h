#include <string>
using namespace std;


class Character
{
  protected:

    string NAME;
    short LVL;
    float HP;
    float ARMOR;
    short DAMAGE;


public:

  public:

    Character();
    Character(short);
    friend class User;
};


class User : public Character
{
    short KILLS;
    string INVENTORY[4][4] = {{"Health Potion", "Damage Boost Potion", "Shield Potion", "Instakill Potion"}, {"0", "0", "0", "0"}};

  public:
    User();
    bool Battle(Character, short);
    void displayInventory();
    bool editInventory(string); 
    void prepareNextRound();
    short retrievePlayerLevel();

    

};
//test
