#include <iostream>
using namespace std;
#include "hobgoblin.hpp"

Hobgoblin::Hobgoblin(void)
{
    name = "Hobgoblin";
    ac = 12;
    max_hp = 25;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    str = 12;
    dex = 16;
    att = 0;
    roll_stats(str, dex, att);
}
