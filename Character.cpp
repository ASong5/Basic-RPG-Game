#include <iostream>
#include <time.h>
#include "Character.h"
#include "Windows.h"
using namespace std;

bool User::Battle(Character Monster, short level)
{
    srand(time(NULL));
    bool win = false;

    while (this->HP > 0 || Monster.HP > 0)
    {
        int option = 1;
        cout << "1) Attack\t2) Inventory ";
        cin >> option;
        cout << endl;
        ///////////////////////////////////////////////////////

        if (option == 2)
        {
            User::displayInventory();
            continue;
        }

        else if (option == 1)
        {

            ///////////////////////////////////////////////////////

            short damage = rand() % this->DAMAGE + 1;
            Monster.HP -= damage + Monster.ARMOR;
            cout << "You did " << damage + Monster.ARMOR << " damage!" << endl;
            if (damage == 0)
                cout << "You Missed Idiot." << endl;
            //Sleep(1000);
            if (Monster.HP <= 0)
            {
                cout << "You have killed " << Monster.NAME << " " << level + 1 << "!" << endl
                     << endl;
                cout << "You have obtained a health potion!" << endl;
                bool obtained = editInventory("Health Potion");
                cout << "Get ready for the next monster. He will be tougher." << endl;
                //Sleep(1000);
                win = true;
                break;
            }

            damage = rand() % Monster.DAMAGE + 1;
            this->HP -= damage + this->ARMOR;
            cout << Monster.NAME << " " << level + 1 << " did " << damage + this->ARMOR << " damage!" << endl
                 << endl;
            if (damage == 0)
                cout << "LUL it missed!!!!!!!!! lulululululul!" << endl;
            //Sleep(1000);
            if (this->HP <= 0)
            {
                cout << Monster.NAME << " " << level + 1 << " has killed you!" << endl
                    << endl;
                //Sleep(1000);
                win = false;
                break;
            }

            if (this->HP <= 0)
            {
                cout << "Your HP: 0" << '\t' << Monster.NAME << " " << level + 1 << " HP: " << Monster.HP << "." << endl;
                cout << "-------------------------------------------------------" << endl
                     << endl;
                break;
            }
            else if (Monster.HP <= 0)
            {
                cout << "Your HP: " << this->HP << '\t' << Monster.NAME << " " << level + 1 << " HP: 0." << endl;
                cout << "-------------------------------------------------------" << endl
                     << endl;
            }
            else
            {
                cout << "Your HP: " << this->HP << '\t' << Monster.NAME << " " << level + 1 << " HP: " << Monster.HP << "." << endl;
                cout << "-------------------------------------------------------" << endl
                     << endl;
            }
            //Sleep(1000);
        }
    }

    return win;
}

Character::Character()
{
    this->NAME = "Monster";
    this->LVL = 1;
    this->HP = 100;
    this->DAMAGE = 10;
    this->ARMOR = 0;
}
Character::Character(short LVL)
{
    this->NAME = "Stronger Monster";
    this->LVL = LVL;
    this->HP = 100;
    this->DAMAGE = 10 * LVL * .75;
    this->ARMOR = LVL;
}

User::User()
{
    this->LVL = 0;
}

void User::displayInventory()
{
    for (int item = 0; item < 4; item++)
        cout << this->INVENTORY[0][item] << "(" << this->INVENTORY[1][item] << ")" << endl
             << endl;
}

bool User::editInventory(string item)
{
    if (this->INVENTORY[0][3].length() == 0)
        return false;

    bool match = false;
    for(int i = 0; i < 4; i++)
    {
        if(item == this->INVENTORY[0][i])
        {
            short temp = stoi(this->INVENTORY[1][i]);
            this->INVENTORY[1][i] = to_string(++temp);
            match = true;
            break;
        }
    }
    if(!match)
    {
        if(this->INVENTORY[0][3].length() != 0)
            return false;
        for(int i = 0; i < 4; i++)
        {
            if(this->INVENTORY[0][i].length() == 0)
            {
                this->INVENTORY[0][i] = item;
                short temp = stoi(this->INVENTORY[1][i]);
                this->INVENTORY[1][i] = to_string(++temp);
            }
        }
    }
        cout << "*" << item << " has been added to your inventory*" << endl << endl;
        return true;
}

void User::prepareNextRound() 
{
    this->HP = 100;
    this->LVL++;
}

short User::retrievePlayerLevel() {return this->LVL;}
