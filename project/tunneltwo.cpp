//#include "room.hpp"
#include "tunneltwo.hpp"
#include <iostream>
using namespace std;
//room number 4
Tunneltwo::Tunneltwo(void)
{
    dummy_count = 0;
    goblin_count = 2;
    arrow_count = 3;
    hp_ptns = 0;
    mn_ptns = 3;
    path_left = 5;
    //leads to prison
    path_right = 8;
    //leads to tunneltwo
    path_return = 2;
    //leads to entrance
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    //vampire_count = 0;
    description = "The tunnel branches off into two directions, with tracks leading down the path to the right. Do you go left, right, or go back?";

}
