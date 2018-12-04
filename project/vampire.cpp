#include <iostream>
using namespace std;
#include "vampire.hpp"

Vampire::Vampire(void)
{
    name = "Vampire";
    ac = 14;
    max_hp = 50;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    hp_ptn_cnt = 0;
    str = 12;
    dex = 18;
    att = 14;
    is_undead = true;
    roll_stats(str, dex, att);
}

void Vampire::act(Actor &d)
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
