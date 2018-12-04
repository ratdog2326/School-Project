#include <iostream>
using namespace std;
#include "bugbear.hpp"

Bugbear::Bugbear(void)
{
    name = "Bugbear";
    ac = 14;
    max_hp = 50;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    hp_ptn_cnt = 2;
    str = 18;
    dex = 12;
    att = 0;
    roll_stats(str, dex, att);
}

void Bugbear::act(Actor &d)
{
    cout << name <<"'s turn..." << endl;
    int crit_hp = max_hp/4; //critical health threshold
    int opp_hp = d.check_hp();  // enemy current hp
    int opp_mxhp = d.get_max_hp(); //enemy max hp
    int oc_hp = opp_mxhp/4;             //enemy crit hp threshold
    if (cur_hp <= crit_hp)
    {
        if (hp_ptn_cnt > 0)
        {
            use_hp_ptn();
        }
        else if (opp_hp <= oc_hp)
        {
            smash(d);
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
            smash(d);
        }

    }
    else if (opp_hp <= oc_hp)
    {
        smash(d);
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
        smash(d);
    }
}
