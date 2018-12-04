//#include "room.hpp"
#include "tunnelone.hpp"
#include <iostream>
using namespace std;

Tunnelone::Tunnelone(void)
{
    dummy_count = 0;
    goblin_count = 5;
    arrow_count = 15;
    hp_ptns = 2;
    mn_ptns = 1;
    path_left = 4;
    //leads to prison
    path_right = 3;
    //leads to tunneltwo
    path_return = 1;
    //leads to entrance
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    //vampire_count = 0;
    description = "More stolen supplies are stored here. The cave descends downward and splits into two paths. Do you go left, right, or go back?";

}
