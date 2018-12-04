#include <iostream>
using namespace std;
#include "goblin.hpp"

Goblin::Goblin(void)
{
    name = "Goblin";
    ac = 8;
    max_hp = 12;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    hp_ptn_cnt = 0;
    str = 8;
    dex = 12;
    att = 0;
    roll_stats(str, dex, att);
}
