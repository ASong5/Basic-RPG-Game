#include <iostream>
#include <string>
#include <unistd.h>
#include "Character.h"
using namespace std;
//
int main() {
    bool win = true;
    User Player;
    Character Monster;


    cout << endl
         << "Battle " << Player.retrievePlayerLevel() + 1 << endl
         << "-----------------" << endl
         << endl;
    usleep(2000000);
    win = Player.Battle(Monster, Player.retrievePlayerLevel());

    while (true) {
        if (win) {
            Player.afterBattle();
            cout << "You got " << Player.GOLDCOLLECT << " gold from winning the battle!\nYou have a total of: " << Player.GOLD << " Gold!"
                 << endl;


    cout << endl
         << "Battle " << Player.retrievePlayerLevel() + 1 << endl
         << "-----------------" << endl
         << endl;
    Sleep(2000);
    win = Player.Battle(Monster, Player.retrievePlayerLevel());

    while (true)
    {
        if (win)
        {

            Player.prepareNextRound();
            Character Monster(Player.retrievePlayerLevel());
            cout << endl
                 << "Battle " << Player.retrievePlayerLevel() + 1 << endl
                 << "-----------------" << endl;

           usleep(2000000);
            win = Player.Battle(Monster, Player.retrievePlayerLevel());
        } else {

            Sleep(2000);
            win = Player.Battle(Monster, Player.retrievePlayerLevel());
        }
        else
        {

            win = false;
            cout << "You LOSE!" << endl;
            cout << "Kills: " << Player.retrievePlayerLevel();
            break;
        }
    }
}
//
