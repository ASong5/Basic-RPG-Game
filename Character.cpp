#include <iostream>
#include <time.h>
#include "Character.h"
#include "Windows.h"
using namespace std;


bool Character::Battle(Character Monster, short level)
{
    srand(time(NULL));
    bool win = false;

    int aori = 1;
    cout << "press 1 to attack: ";
    cin >> aori;


    while (this->HP > 0 || Monster.HP > 0)
    {
///////////////////////////////////////////////////////
        while (true){
            if( aori == 1){
                aori = 0;
                break;
            }

            else if ( aori == 2){

                cout << inventory[1][0]<< inventory[1][1];
            }
            aori = 0;
            cout << "press 1 to attack";
            cin >> aori;


        }
///////////////////////////////////////////////////////

        short damage = rand() % this->DAMAGE + 1;
        Monster.HP -= damage + Monster.ARMOR;
        cout << "You did " << damage + Monster.ARMOR << " damage!" << endl;
        if (damage == 0)
            cout << "You Missed Idiot." << endl;
        Sleep(1000);
        if (Monster.HP <= 0)
        {
            cout << "You have killed " << Monster.NAME << " " << level + 1 << "!" << endl << endl;
            Sleep(1000);
            win = true;
            break;
        }

        damage = rand() % Monster.DAMAGE + 1;
        this->HP -= damage + this->ARMOR;
        cout << Monster.NAME << " " << level + 1 << " did " << damage + this->ARMOR << " damage!" << endl;
        if (damage == 0)
            cout << "LUL it missed!!!!!!!!! lulululululul!" << endl;
        Sleep(1000);
        if (this->HP <= 0)
        {
            cout << endl << Monster.NAME << " " << level + 1 << " has killed you!" << endl
                 << endl;
            Sleep(1000);
            win = false;
            break;
        }

        if (this->HP <= 0)
        {
            cout << "Your HP: 0" << '\t' << Monster.NAME << " " << level + 1 <<" HP: " << Monster.HP << "." << endl;
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
        Sleep(1000);
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
Character::Character(short playerLVL)
{
    this->NAME = "Stronger Monster";
    this->LVL = playerLVL;
    this->HP = 100;
    this->DAMAGE = 10 * playerLVL * .75;
    this->ARMOR = playerLVL;
}

User::User() {
    this->EXP = 0;
}
