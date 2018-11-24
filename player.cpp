#include <iostream>
using namespace std;
#include "player.hpp"
//#include "actor.cpp"

Player::Player(void)
{
    name = "You";
    ac = 10;
    max_hp = 30;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    str = 10;
    dex = 10;
    att = 10;
    hp_ptn_cnt = 3;
    mana_ptn_cnt = 0;
    roll_stats(str, dex, att);
}

void Player::act(Actor &d)
{
    int input;
    cout << "It's your turn..." << endl;
    cout << "HP: " << cur_hp << "/" << max_hp << endl;
    cout << "1. Attack" << endl;
    cout << "2. Drink health potion (" << hp_ptn_cnt << " remaining)" <<endl;
    cin >> input;
    if (input == 1)
    {
        attack(d);
    }
    else if (input == 2)
    {
        if (hp_ptn_cnt > 0)
        {
            use_hp_ptn();
        }
        else
        {
            cout << "You have no health potions." << endl;
            act(d);
        }
    }
    else
    {
        cout << "Invalid input" << endl;
        act(d);
        //todo: change this to error handling
    }
}
