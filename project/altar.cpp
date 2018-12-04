#include "altar.hpp"
#include <iostream>
using namespace std;

Altar::Altar(void)
{
    //room number 3
    dummy_count = 0;
    goblin_count = 0;
    hobgoblin_count = 0;
    bugbear_count = 0;
    arrow_count = 0;
    hp_ptns = 5;
    mn_ptns = 2;
    path_left = 0;
    path_right = 9;
    path_return = 4;
    holds_holy_bow = true;
    deadend = false;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    vampire_count = 1;
    description = "You stand in a bloodied altar room, used to worship and make sacrifices to the Archdemon Zelgos, father of Vampires. It doesn't take much effort to piece together what happened to the people in the caravans: A vampire clan has been paying goblins to raid caravans and bring the people back for sacrifices. There is a doorway on the right.";

}
