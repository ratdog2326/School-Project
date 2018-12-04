#ifndef __ROOM_HPP__
#define __ROOM_HPP__
#include <iostream>
#include "dummy.hpp"
#include "player.hpp"
#include "system.hpp"
#include "goblin.hpp"
#include "hobgoblin.hpp"
#include "bugbear.hpp"
#include "vampire.hpp"
#include "avorith.hpp"
using namespace std;
using namespace My_game;
//room hold the number of enemies present and run combat.

class Room
{
protected:
    int arrow_count;
    int hp_ptns;
    int mn_ptns;
    int dummy_count;
    int goblin_count;
    int hobgoblin_count;
    int bugbear_count;
    int vampire_count;
    int path_left;
    int path_right;
    bool deadend;
    int path_return;
    string description;
    bool holds_sword;
    bool holds_bow;
    bool holds_magmis;
    bool holds_holy_sword;
    bool holds_holy_bow;
    bool holds_holy_spell;
public:
    virtual int run_room(Player &plr);
    virtual void describe_room();
    int pick_path();
    void level_up(Player &plr);
    Actor make_dummy();
    Actor make_goblin();
    Actor make_hobgoblin();
    Actor make_bugbear();
    Actor make_vampire();

    Room(void);
};


#endif
