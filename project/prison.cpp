#include "prison.hpp"
#include <iostream>
using namespace std;

Prison::Prison(void)
{
    //room number 3
    dummy_count = 0;
    goblin_count = 2;
    hobgoblin_count = 2;
    arrow_count = 20;
    hp_ptns = 5;
    mn_ptns = 0;
    path_left = 0;
    path_right = 0;
    path_return = 2;
    deadend = true;
    //leads to tunnelone
    mn_ptns = 0;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    //vampire_count = 0;
    description = "You find yourself in a small room with makeshift prison cells. No one is in any of the cells, but they appear to have been used recently. The only exit is the way you came.";

}
