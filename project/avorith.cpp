#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "avorith.hpp"

Avorith::Avorith(void)
{
    name = "Avorith, Thrall of Zelgos";
    ac = 16;
    max_hp = 150;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    hp_ptn_cnt = 0;
    str = 18;
    dex = 18;
    att = 18;
    is_undead = true;
    roll_stats(str, dex, att);
}

void Avorith::act(Actor &d)
{
    cout << name <<"'s turn..." << endl;
    int phase_thresh = max_hp/3;
    int crit_hp = max_hp/5; //critical health threshold
    int crit_mana = max_mana/4;
    int opp_hp = d.check_hp();  // enemy current hp
    int opp_mxhp = d.get_max_hp(); //enemy max hp
    int oc_hp = opp_mxhp/4;             //enemy crit hp threshold
    if (cur_hp < phase_thresh)
    {
        if (cur_hp <= crit_hp)
        {
            if (hp_ptn_cnt > 0)
            {
                drain(d);
            }
            else if (opp_hp <= oc_hp)
            {
                slash(d);
            }
            else if (cur_mana < (max_mana/4))
            {
                if (mana_ptn_cnt > 0)
                {
                    use_mn_ptn();
                }
            }
            else
            {
                slash(d);
            }

        }
        else if (opp_hp <= oc_hp)
        {
            slash(d);
        }

        else
        {
            slash(d);
        }
    }
    else
    {
        if (cur_mana > crit_mana)
        {
            int
            roll = rand() % 2;
            if(roll == 0)
            {
                use_sword(d);
            }
            else
            {
                cast_magmis(d);
            }
        }
    }
}
