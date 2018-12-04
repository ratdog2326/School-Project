#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include <iostream>
#include "player.hpp"
#include "warrior.hpp"
#include "mage.hpp"
#include "rogue.hpp"
#include "dummy.hpp"

using namespace std;
namespace My_game{
//#include "room.hpp"
//#include "entrance.hpp"
//#include "initiative.hpp"

void cust_class(Player &plr);

void lock_stat1(Player &plr, int stat1);

void lock_stat2(Player &plr, int stat2);

void lock_stat3(Player &plr, int stat3);

int combat(Player &a, Actor &b);

void create_character(Player &plr);

void choose_class(Player &plr);

string ask_name();
}
#endif
