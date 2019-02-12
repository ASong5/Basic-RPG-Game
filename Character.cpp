#include <iostream>
#include <time.h>
#include "Character.h"
#include <unistd.h>
using namespace std;


bool User::Battle(Character Monster, short level) {
    srand(time(NULL));
    bool win = false;

    while (this->HP > 0 || Monster.HP > 0) {
        int option = 1;
        cout << "1) Attack\t2) Inventory\t3) Shop ";
        cin >> option;
        cout << endl;
        ///////////////////////////////////////////////////////

        if (option == 3){

            shop();
            continue;
        }

        else if (option == 2) {
            User::displayInventory();
            continue;

        } else if (option == 1) {

            ///////////////////////////////////////////////////////

            short damage = rand() % this->DAMAGE + 1;
            Monster.HP -= damage + Monster.ARMOR;
            cout << "You did " << damage + Monster.ARMOR << " damage!" << endl;
            if (damage == 0)
                cout << "You Missed Idiot." << endl;
           usleep(1000000);
            if (Monster.HP <= 0) {
                cout << "You have killed " << Monster.NAME << " " << level + 1 << "!" << endl
                     << endl;
                cout << "You have obtained a health potion!" << endl;
                bool obtained = editInventory("health potion");
                cout << "Get ready for the next monster. He will be tougher." << endl;
               usleep(100000);
                win = true;
                break;
            }

            damage = rand() % Monster.DAMAGE + 1;
            this->HP -= damage + this->ARMOR;
            cout << Monster.NAME << " " << level + 1 << " did " << damage + this->ARMOR << " damage!" << endl
                 << endl;
            if (damage == 0)
                cout << "LUL it missed!!!!!!!!! lulululululul!" << endl;
           usleep(1000000);
            if (this->HP <= 0) {
                cout << Monster.NAME << " " << level + 1 << " has killed you!" << endl
                     << endl;
              usleep(1000000);
                win = false;
                break;
            }

            if (this->HP <= 0) {
                cout << "Your HP: 0" << '\t' << Monster.NAME << " " << level + 1 << " HP: " << Monster.HP << "."
                     << endl;
                cout << "-------------------------------------------------------" << endl
                     << endl;
                break;
            } else if (Monster.HP <= 0) {
                cout << "Your HP: " << this->HP << '\t' << Monster.NAME << " " << level + 1 << " HP: 0." << endl;
                cout << "-------------------------------------------------------" << endl
                     << endl;
            } else {
                cout << "Your HP: " << this->HP << '\t' << Monster.NAME << " " << level + 1 << " HP: " << Monster.HP
                     << "." << endl;
                cout << "-------------------------------------------------------" << endl
                     << endl;
            }
           usleep(1000000);

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
                bool obtained = editInventory("health potion");
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

Character::Character() {
    this->NAME = "Monster";
    this->LVL = 1;
    this->HP = 100;
    this->DAMAGE = 200;
    this->ARMOR = 0;

}


Character::Character(short LVL) {

Character::Character(short LVL)
{

    this->NAME = "Stronger Monster";
    this->LVL = LVL;
    this->HP = 100;
    this->DAMAGE = 10 * LVL * .75;
    this->ARMOR = LVL;

}

User::User() {
    this->LVL = 0;
    this->GOLD = 0;
    this->GOLDCOLLECT = 0;
}

void User::displayInventory() {
    for (int item = 0; item < 4; item++)
        cout << this->INVENTORY[0][item] << "(" << this->INVENTORY[1][item] << ")" << endl
             << endl;
}

bool User::editInventory(string item) {
    if (this->INVENTORY[0][3].length() == 0)
        return false;

    bool match = false;
    for (int i = 0; i < 4; i++) {
        if (item == this->INVENTORY[0][i]) {
            short temp = stoi(this->INVENTORY[1][i]);
            this->INVENTORY[1][i] = to_string(++temp);
            match = true;
            break;
        }
    }
    if (!match) {
        if (this->INVENTORY[0][3].length() != 0)
            return false;
        for (int i = 0; i < 4; i++) {
            if (this->INVENTORY[0][i].length() == 0) {
                this->INVENTORY[0][i] = item;
                short temp = stoi(this->INVENTORY[1][i]);
                this->INVENTORY[1][i] = to_string(++temp);
            }
        }
    }
    cout << "*" << item << " has been added to your inventory*" << endl << endl;
    return true;
}

void User::prepareNextRound() {
    this->HP = 100 + this->Healthbonus;
    this->LVL++;
}

short User::retrievePlayerLevel() { return this->LVL; }

void User::afterBattle() {

    GOLDCOLLECT += LVL * 10;
    GOLD += GOLDCOLLECT;


    //for item drops



   // int healthDrop = rand() % 2;
 //   if (healthDrop == 1) {
  //      int stringtoint = stoi(INVENTORY[0][1]);
    //    stringtoint++;
    //    INVENTORY[0][0] = to_string(stringtoint);

 //   }
}



void User::shop(){
    int shopOption;

    cout << "Welcome to my shop young warrior!\nWhat are you looking for?" << endl;

    while (true) {
        cout << "[1] 20 HP increase\t" << healthbonus_ << " gold" << endl;
        cout << "[2] 20 DMG increase\t" << damagebonus_ << " gold" << endl;
        cout << "You currently have [" << GOLD <<  "] gold" << endl;
        cout << "press [0] to quit"<< endl;
        cin >> shopOption;
        if (shopOption == 0){
            break;
        }

        if (shopOption == 1) {
            if (GOLD >= healthbonus_) {
                cout << "health successfully increased" << endl;
                GOLD -= healthbonus_;
                this-> Healthbonus += healthbonus_;
                cout << "you currently have:" << this->Healthbonus + this->HP << " HP" << endl;
                this->HP += this->Healthbonus;
                healthbonus_ += 20;



            }
            else{

                cout << "you don't have enough gold" << endl;
            }



        }

        if (shopOption == 2){
            if (GOLDCOLLECT >= damagebonus_){

                this->DAMAGE += damagebonus_;
                cout << "You are now do " << this->DAMAGE << " damage!!"  << endl;
                GOLD -= damagebonus_;
                damagebonus_ += 20;

            }
            else{

                cout << "you don't have enough gold" << endl;
            }


        }
    }






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