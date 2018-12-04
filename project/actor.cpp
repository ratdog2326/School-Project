#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "actor.hpp"


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
    is_undead = false;
    mana_ptn_cnt = 0;
//    is_player = false;
    roll_stats(str, dex, att);
}


void Actor::set_str(int st)
{
    str = st;
}

void Actor::set_dex(int dx)
{
    dex = dx;
}

void Actor::set_att(int at)
{
    att = at;
}

int Actor::get_str()
{
    return str;
}

int Actor::get_dex()
{
    return dex;
}

int Actor::get_att()
{
    return att;
}

void Actor::heal(int amt)
{
    cur_hp += amt;
}

void Actor::damage(int amt)
{
    cur_hp -= amt;
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

    max_mana = att_mod;
    max_mana = max_mana*30;
    if (max_mana < 0)
    {
        max_mana = 0;
    }
    /*
    max_hp = ((str_mod*10)+(dex_mod*5));
    if(max_hp < 20)
    {
        max_hp = 15;
    }

    cur_hp = max_hp;
    */
    cur_mana = max_mana;

}

void Actor::use_axe(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + str_mod;
    cout << name << " used a battle axe and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 10 + 1;
        dmg = dmg+str_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg/4;
        }
        c.damage(dmg);
        cout << " hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::set_name(string nm)
{
    name = nm;
}

void Actor::use_dagger(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + dex_mod;
    cout << name << " used a dagger and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 4 + 1;
        dmg = dmg+dex_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg/4;
        }
        c.damage(dmg);
        cout << " hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}



void Actor::use_sword(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + dex_mod;
    cout << name << " used a sword and";
    if (atk < c.get_ac())
    {
        cout <<" missed!" << endl;
    }
    else
    {
        dmg = rand() % 6 + 1;
        dmg = dmg+str_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg/4;
        }
        c.damage(dmg);
        cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}
void Actor::use_holy_sword(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + dex_mod;
    cout << name << " used the Holy Blade and";
    if (atk < c.get_ac())
    {
        cout <<" missed!" << endl;
    }
    else
    {
        dmg = rand() % 6 + 1;
        dmg = dmg+str_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg*4;
        }
        c.damage(dmg);
        cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}


void Actor::use_bow(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + dex_mod;
    cout << name << " used a bow and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 12 + 1;
        dmg = dmg+dex_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg/4;
        }
        c.damage(dmg);
        cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::use_holy_bow(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + dex_mod;
    cout << name << " used the Sanctified Bow and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 12 + 1;
        dmg = dmg+dex_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg*4;
        }
        c.damage(dmg);
        cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::smash(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + str_mod;
    cout << name << " swings and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 10 + 1;
        dmg = dmg+str_mod;
        c.damage(dmg);
        cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::slash(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + dex_mod;
    cout << name << " swings its claws and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 12 + 1;
        dmg = dmg+dex_mod;
        c.damage(dmg);
        cout << " hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::drain(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + str_mod;
    cout << name << " bites at " << c.get_name() << " and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 10 + 1;
        dmg = dmg+att_mod;
        c.damage(dmg);
        heal(dmg);
        cout << " drains "<<c.get_name()<<" for " << dmg << " HP!" << endl;
    }
}

void Actor::cast_magmis(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + att_mod;
    cout << name << " cast magic missile and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 10 + 1;
        dmg = dmg+att_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg*2;
        }
        c.damage(dmg);
        cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::cast_holy_fury(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + att_mod;
    cout << name << " cast Divine Fury and";
    if (atk < c.get_ac())
    {
        cout << " missed!" << endl;
    }
    else
    {
        dmg = rand() % 12 + 1;
        dmg = dmg+att_mod;
        if (c.check_undead() == true)
        {
            dmg = dmg*4;
        }
        c.damage(dmg);
        cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
    }
}

void Actor::cast_heal(Actor &c)
{
    int regen;
    regen = rand() % 10 + 5;
    regen += att_mod;
    heal(regen);
    hp_ptn_cnt --;
    if (cur_hp > max_hp)
    {
        int diff = cur_hp - max_hp;
        regen = regen - diff;
        cur_hp = max_hp;
    }
    cout << name << " cast Heal and healed for " << regen << " HP!" << endl;
}

void Actor::cast_fireball(Actor &c)
{
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    int roll;
    int atk;
    int dmg;
    roll = rand() % 20 + 1;
    atk = roll + att_mod;
    dmg = rand() % 10 + 1;
    dmg = dmg+att_mod;
    cout << name << " cast fireball and";
    if (atk < ac)
    {
        cout << " was caught in the blast for " << dmg/2 << " damage!"<< endl;
        damage(dmg/4);
        cout << "They also";
    }
    if (c.check_undead() == true)
    {
        dmg = dmg*2;
    }
    c.damage(dmg);
    cout <<" hit "<<c.get_name()<<" for " << dmg << " damage!" << endl;
}

void Actor::use_hp_ptn()
{
    int regen;
    regen = rand() % 10 + 5;
    regen += att_mod;
    heal(regen);
    hp_ptn_cnt --;
    if (cur_hp > max_hp)
    {
        int diff = cur_hp - max_hp;
        regen = regen - diff;
        cur_hp = max_hp;
    }
    cout << name << " healed for " << regen << " HP!" << endl;
}


void Actor::use_mn_ptn()
{
    int regen;
    regen = rand() % 30 + 5;
    regen += att_mod;
    cur_mana += regen;
    mana_ptn_cnt --;
    if (cur_mana > max_mana)
    {
        int diff = cur_mana - max_mana;
        regen = regen - diff;
        cur_mana = max_mana;
    }
    cout << name << " attuned for " << regen << " mana!" << endl;
}

int Actor::get_max_hp()
{
    return max_hp;
}

void Actor::set_hp(int hp)
{
    cur_hp = hp;
}

void Actor::level_stats()
{
    max_hp += 10;
    max_mana += 10;
}

void Actor::act(Actor &d)
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
            use_dagger(d);
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
            use_dagger(d);
        }

    }
    else if (opp_hp <= oc_hp)
    {
        use_dagger(d);
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
        use_dagger(d);
    }

}

int Actor::roll_str()
{
    int roll;
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    roll = rand() % 20 + 1;
    roll += str_mod;
    return roll;
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

int Actor::roll_att()
{
    int roll;
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL)); //seeds random time
    roll = rand() % 20 + 1;
    roll += att_mod;
    return roll;
}

int Actor::check_hp()
{
    return cur_hp;
}

int Actor::get_ac()
{
    return ac;
}

string Actor::get_name()
{
    return name;
}

bool Actor::check_undead()
{
    return is_undead;
}
/*
bool Actor::check_plr()
{
    return is_player;
}
*/
