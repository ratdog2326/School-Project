
#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__

#include <iostream>
using namespace std;


/*
this is the actor class. it is to be used as the base class from which the
player and NPC class will be derived.
*/

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
    virtual void attack(Actor &c); //used to select target
    virtual void use_hp_ptn(); //use health potion
    virtual void use_mn_ptn(); //use mana potion
    virtual void act(Actor &d);
    void roll_stats(int s, int d, int a);
    int roll_dex();
    int check_hp();
};

#endif
