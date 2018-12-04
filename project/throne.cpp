#include "throne.hpp"
#include <iostream>
using namespace std;

Throne::Throne(void)
{
    //room number 3
    dummy_count = 0;
    goblin_count = 0;
    hobgoblin_count = 0;
    bugbear_count = 0;
    arrow_count = 0;
    hp_ptns = 0;
    mn_ptns = 0;
    path_left = 10;
    path_right = 0;
    path_return = 0;
    holds_holy_spell = false;
    deadend = false;
    //hobgoblin_count = 0;
    //bugbear_count = 0;
    vampire_count = 0;
    description = "";

}

int Throne::run_room(Player &plr)
{
    Avorith av;
    cout << "You step into what you believe to be the Crypt. The door swiftly shuts behind you as a large figure rises out of a marble coffin. The man stares almost through you and doesn't say a word before he lunges for you." << endl;
    combat(plr, av);
    if(plr.check_hp() > 0)
    {
        return 100;
    }
    else
    {
        return 99;
    }
}
