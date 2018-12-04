//#include "room.hpp"
#include "entrance.hpp"
#include <iostream>
using namespace std;

Entrance::Entrance(void)
{
    //room number 1
    dummy_count = 0;
    goblin_count = 3;
    arrow_count = 10;
    hp_ptns = 2;
    path_left = 2;
    path_right = 0;
    path_return = 0;
    deadend = false;
    //leads to tunnelone
    mn_ptns = 0;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    //vampire_count = 0;
    description = "You are standing in the entrance of a cave. Supplies from robbed caravans litter the floor and line the walls. The cave continues onward to the left.";

}
