#include <iostream>
using namespace std;
#include "dummy.hpp"
//#include "actor.cpp"

Dummy::Dummy(void)
{
    name = "Dummy";
    ac = 10;
    max_hp = 30;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    str = 10;
    dex = 10;
    att = 10;
    roll_stats(str, dex, att);
}
