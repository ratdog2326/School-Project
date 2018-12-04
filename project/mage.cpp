#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "mage.hpp"

Mage::Mage(void)
{
    name = "You";
    ac = 12;
    max_hp = 25;
    cur_hp = max_hp;
    max_mana = 50;
    cur_mana = max_mana;
    str = 8;
    dex = 12;
    att = 18;
    hp_ptn_cnt = 1;
    mana_ptn_cnt = 4;
//    is_player = true;
    has_sword = false;
    has_dagger = true;
    has_bow = false;
    has_axe = false;
    has_magmis = true;
    has_fireball = true;
    has_heal = true;
    arrows = 0;
    roll_stats(str, dex, att);
}
