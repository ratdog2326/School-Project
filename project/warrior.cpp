#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "warrior.hpp"

Warrior::Warrior(void)
{
    name = "You";
    ac = 16;
    max_hp = 50;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    str = 18;
    dex = 12;
    att = 8;
    hp_ptn_cnt = 5;
    mana_ptn_cnt = 0;
//    is_player = true;
    has_sword = true;
    has_dagger = false;
    has_bow = true;
    has_axe = true;
	has_holy_sword = false;
	has_holy_bow = false;
	has_holy_fury = false;
    has_magmis = false;
    has_fireball = false;
    arrows = 10;
    roll_stats(str, dex, att);
}
