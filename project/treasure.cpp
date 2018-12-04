#include "treasure.hpp"
#include <iostream>
using namespace std;

Treasure::Treasure(void)
{
    //room number 7
    dummy_count = 0;
    goblin_count = 0;
    hobgoblin_count = 0;
    bugbear_count = 0;
    arrow_count = 20;
    hp_ptns = 7;
    mn_ptns = 3;
    path_left = 0;
    path_right = 0;
    path_return = 6;
    deadend = true;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    //vampire_count = 0;
    description = "This is the room where the goblins have been holding their loot. Gold, silver, and artifacts are neatly stacked in piles, though much of this does not match the caravan invoices. The only way out is the way you came.";

}
