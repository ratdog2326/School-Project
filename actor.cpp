#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "actor.hpp"

/*
for reference
class Actor
{
protected:
    int ac; //armor class - attack must be greater to than this to hit
    int cur_hp; //current health
    int max_hp; //maximum health
    int cur_mana; //current mana - used to cast magic
    int max_mana; //maximum mana
    int str; //strength
    int str_mod; //strength modifier
    int dex; //dexterity
    int dex_mod;
    int att; //attunement
    int att_mod;
    int hp_ptn_cnt;
    int mana_ptn_cnt;
    string name; //name
public:
    Actor(void);
    virtual void attack(Actor c); //used to select target
    virtual void use_hp_ptn(); //use health potion
    virtual void use_mn_ptn(); //use mana potion
    virtual void act(Actor d);
    void dodge();
    void roll_stats();
};
*/

//default constructor
Actor::Actor(void)
{
    name = "guy";
    ac = 15;
    max_hp = 30;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    str = 10;
    dex = 10;
    att = 10;
    hp_ptn_cnt = 1;
    mana_ptn_cnt = 0;
    roll_stats(str, dex, att);
}

void Actor::roll_stats(int s, int d, int a)
{
    double i;
    i = s/2;
    i -= 4.5;
    str_mod = i;

    i = d/2;
    i -= 4.5;
    dex_mod = i;

    i = a/2;
    i -= 4.5;
    att_mod = i;
}

void Actor::attack(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + str_mod;
    cout << name << " rolled " << roll << " + " << dex_mod;
    cout << " for a total of " << atk << endl;
    if (atk < c.ac)
    {
        cout << name << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 10 + 1;
        dmg = dmg+str_mod;
        c.cur_hp = c.cur_hp - dmg;
        cout << name << " hit "<<c.name<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::use_hp_ptn()
{
    int regen;
    regen = rand() % 6 + 1;
    regen += att_mod;
    cur_hp += regen;
    hp_ptn_cnt --;
    if (cur_hp > max_hp)
    {
        regen = cur_hp - max_hp;
        cur_hp = max_hp;
    }
    cout << name << "healed for " << regen << " HP!" << endl;
}

void Actor::use_mn_ptn()
{
    int regen;
    regen = rand() % 10 + 1;
    regen += att_mod;
    cur_mana += regen;
    mana_ptn_cnt --;
    if (cur_mana > max_mana)
    {
        regen = cur_mana - max_mana;
        cur_mana = max_mana;
    }
    cout << name << "attuned for " << regen << " mana!" << endl;
}


void Actor::act(Actor &d)
{
    cout << name <<"'s turn..." << endl;
    int crit_hp = max_hp/4; //critical health threshold
    int opp_hp = d.cur_hp;  // enemy current hp
    int opp_mxhp = d.max_hp; //enemy max hp
    int oc_hp = opp_mxhp/4;             //enemy crit hp threshold
    if (cur_hp <= crit_hp)
    {
        if (hp_ptn_cnt > 0)
        {
            use_hp_ptn();
        }
        else if (opp_hp <= oc_hp)
        {
            attack(d);
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
            attack(d);
        }

    }
    else if (opp_hp <= oc_hp)
    {
        attack(d);
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
        attack(d);
    }

}

int Actor::roll_dex()
{
    int roll;
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    roll = rand() % 20 + 1;
    roll += dex_mod;
    return roll;
}

int Actor::check_hp()
{
    return cur_hp;
}
