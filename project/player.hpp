
#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__


#include "actor.hpp"
/*
this class is to be used by
*/
//training dummy is derived from actor
class Player : public Actor
{
protected:
    bool has_sword;
    bool has_bow;
    bool has_axe;
    bool has_fireball;
    bool has_magmis;
    bool has_dagger;
    bool has_heal;
    bool has_holy_sword;
    bool has_holy_bow;
    bool has_holy_fury;
    int arrows;
public:
    Player(void);
    //Player(int s, int d, int a, int arr, bool swo, bool bow, bool dag, bool axe, bool fir, bool mag);
    void attack(Actor &c);
    void act(Actor &c);
    void use_item(Actor &c);
    void cast_spell(Actor &c);
    void add_hp_ptns(int p);
    void add_mn_ptns(int p);
    void add_arrows(int p);
    bool check_bow();
    bool check_axe();
    bool check_sword();
    void give_bow();
    void give_magmis();
    void give_sword();
    void give_holy_sword();
    void give_holy_bow();
    void give_holy_fury();
};



#endif
