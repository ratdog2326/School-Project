
#include "system.hpp"
using namespace std;


void combat()
{
    Initiative ooc;

}





































/*
int combat(Actor &a, Actor &b)
{
    int init_a = a.roll_dex();
    cout << "Player initiative: " << init_a << endl;
    int init_b = b.roll_dex();
    cout << "Dummy initiative: " << init_b << endl;

    if(init_a > init_b) //if a rolls higher in initiative, a goes 1st
    {
        while (a.check_hp() > 0 && b.check_hp() > 0)
        {
        a.act(b);
        if (b.check_hp() <= 0)
        {
            cout << "You win!" << endl;
            cout << "GAME OVER" << endl;
            return 0;
        }

        b.act(a);

        if (a.check_hp() <= 0)
        {
            cout << "You lose." << endl;
            cout << "GAME OVER" << endl;
            return 0;
        }
        }
    }

    else //if b rolls higher in initiative, a goes last
    {
        while(a.check_hp() > 0 && b.check_hp() > 0)
        {
        b.act(a);

        if (a.check_hp() <= 0)
        {
            cout << "You lose." << endl;
            cout << "GAME OVER" << endl;
            return 0;
        }

        a.act(b);
        if (b.check_hp() <= 0)
        {
            cout << "You win!" << endl;
            cout << "GAME OVER" << endl;
            return 0;
        }
    }
    }
    return 0;
}
*/
