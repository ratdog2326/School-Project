#include "quarters.hpp"
#include <iostream>
using namespace std;

Quarters::Quarters(void)
{
    //room number 3
    dummy_count = 0;
    goblin_count = 2;
    hobgoblin_count = 2;
    bugbear_count = 1;
    arrow_count = 20;
    hp_ptns = 5;
    mn_ptns = 0;
    path_left = 7;
    path_right = 0;
    path_return = 5;
    holds_sword = true;
    deadend = false;
    //leads to tunnelone
    mn_ptns = 0;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    //vampire_count = 0;
    description = "This is the leader's personal quarters. Food and fine clothes adorn the walls and floor. It seems as if the Bugbear was using the goblins to rob caravans, but there is still no sign of the missing people. There is a small doorway to the left.";

}
