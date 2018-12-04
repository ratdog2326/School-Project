
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
    bool is_undead;
    int hp_ptn_cnt;
    int mana_ptn_cnt;
    string name; //name
//    bool is_player;
public:
    Actor(void);
    virtual void use_hp_ptn(); //use health potion
    virtual void use_mn_ptn(); //use mana potion
    virtual void act(Actor &d);
    void use_sword(Actor &d);
    void use_holy_sword(Actor &d);
    void use_axe(Actor &d);
    void cast_magmis(Actor &d);
    void cast_fireball(Actor &d);
    void cast_heal(Actor &d);
    void cast_holy_fury(Actor &d);
    void use_bow(Actor &d);
    void use_holy_bow(Actor &d);
    void use_dagger(Actor &d);
    void damage(int amt);
    void heal(int amt);
    void slash(Actor &d);
    void drain(Actor &d);
    void smash(Actor &d);
    void roll_stats(int s, int d, int a);
    int roll_str();
    int roll_dex();
    int roll_att();
    int check_hp();
    int get_ac();
    int get_max_hp();
    void set_str(int st);
    void set_dex(int dx);
    void set_att(int at);
    void set_hp(int hp);
    void level_stats();
    int get_str();
    int get_dex();
    int get_att();
    string get_name();
    void set_name(string nm);
    bool check_undead();
    bool check_plr();

};

#endif
