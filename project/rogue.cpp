#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "rogue.hpp"

Rogue::Rogue(void)
{
    name = "You";
    ac = 14;
    max_hp = 30;
    cur_hp = max_hp;
    max_mana = 15;
    cur_mana = max_mana;
    str = 8;
    dex = 18;
    att = 12;
    hp_ptn_cnt = 3;
    mana_ptn_cnt = 2;
//    is_player = true;
    has_sword = true;
    has_dagger = true;
    has_bow = true;
    has_axe = false;
    has_magmis = false;
    has_fireball = false;
	has_holy_sword = false;
	has_holy_bow = false;
	has_holy_fury = false;
    has_heal = true;
    arrows = 30;
    roll_stats(str, dex, att);
}
