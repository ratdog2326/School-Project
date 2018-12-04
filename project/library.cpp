#include "library.hpp"
#include <iostream>
using namespace std;

Library::Library(void)
{
    //room number 3
    dummy_count = 0;
    goblin_count = 0;
    hobgoblin_count = 0;
    bugbear_count = 0;
    arrow_count = 0;
    hp_ptns = 5;
    mn_ptns = 4;
    path_left = 10;
    path_right = 0;
    path_return = 8;
    holds_holy_spell = true;
    deadend = true;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    vampire_count = 2;
    description = "This is the Tomb's library. You find that it houses records of the ancient hero, Avorith, a paladin who dedicated his life to fighting Zelgos. This tome states that Avorith fell in battle and his body was interred in this tomb. With enough reading, you learn that Zelgos can be temporarily summoned into this realm with enough sacrifices. His last summoning centuries ago brought the scourge of Vampirism. There is a doorway to the left. Your gut tells you to make sure you are prepared before you walk through.";

}
