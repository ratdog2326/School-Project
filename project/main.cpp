//Adam Arnold
#include <iostream>
#include "system.hpp"
#include "room.hpp"
#include "entrance.hpp"
#include "tunnelone.hpp"
#include "tunneltwo.hpp"
#include "prison.hpp"
#include "messhall.hpp"
#include "quarters.hpp"
#include "treasure.hpp"
#include "altar.hpp"
#include "library.hpp"
#include "throne.hpp"
using namespace std;
using namespace My_game;

int main()
{
    cout << "Beginning Tomb of Avorith..." << endl;
    Player plr;
    create_character(plr);
    int room = 1;
    Entrance en;
    Tunnelone t1;
    Tunneltwo t2;
    Prison pr;
    Messhall mh;
    Quarters qa;
    Treasure tr;
    Library li;
    Altar al;
    Throne th;
    cout << "You are an adventurer hired by Belfare Transportation to investigate the disappearance of several caravans. After searching in the area, you find a cave that you suspect to be the hideout of a goblin clan responsible for the disappearances and enter." << endl;
while((room != 99) || (room != 100))
{
    switch(room)
    {
    case 1:
        {
            room = en.run_room(plr);
        }
        break;
    case 2:
        {
            room = t1.run_room(plr);
        }
        break;
    case 3:
        {
            room = pr.run_room(plr);
        }
        break;
    case 4:
        {
            room = t2.run_room(plr);
        }
        break;
    case 5:
        {
            room = mh.run_room(plr);
        }
        break;
    case 6:
        {
            room = qa.run_room(plr);
        }
        break;
    case 7:
        {
            room = tr.run_room(plr);
        }
        break;
    case 8:
        {
            room = al.run_room(plr);
        }
        break;
    case 9:
        {
            room = li.run_room(plr);
        }
        break;
    case 10:
        {
            room = th.run_room(plr);
        }
        break;
    case 99:
        {
            cout << "Unfortunately, you have fallen in your journey and the tale of " << plr.get_name() << "ends here. Forever resting in the Lost Tomb of Avorith." << endl;
            return 0;
        }
        break;
    case 100:
        {
            cout << "After a grueling fight against the thing formerly known as Avorith, Bane of Zelgos, you make your way back through the cave and mount your horse. You tell the merchants at Belfare of what happened and you are handsomely compensated. Word of your deeds spread far and many, many years pass before people forget the name " << plr.get_name() << "." << endl;
            return 0;
        }
        break;
    default:
        {
            cout << "GAME OVER" << endl;
        }
    }
}



    return 0;
}
