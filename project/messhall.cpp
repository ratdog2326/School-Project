#include "messhall.hpp"
#include <iostream>
using namespace std;

Messhall::Messhall(void)
{
    //room number 3
    dummy_count = 0;
    goblin_count = 0;
    hobgoblin_count = 4;
    arrow_count = 20;
    hp_ptns = 3;
    mn_ptns = 2;
    path_left = 0;
    path_right = 6;
    path_return = 4;
    deadend = false;
    holds_sword = true;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    //vampire_count = 0;
    description = "You find yourself in the room the goblins' mess hall. Dirty and broken dishes litter the ground. There is a hidden passage in the right hand side of the room.";

}
