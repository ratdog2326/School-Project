#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "player.hpp"
#include "system.hpp"
namespace My_game{
using namespace std;

int combat(Player &a, Actor &b)
{
    if (a.check_hp() <= 0)
    {
        return 0;
    }
    int init_a = a.roll_dex();
    cout << "Your initiative: " << init_a << endl;
    int init_b = b.roll_dex();
    cout << b.get_name() << "'s initiative: " << init_b << endl;

    if(init_a > init_b) //if a rolls higher in initiative, a goes 1st
    {
        while (a.check_hp() > 0 && b.check_hp() > 0)
        {
        a.act(b);
        if (b.check_hp() <= 0)
        {
            cout << "Victory!" << endl;
            return 0;
        }

        b.act(a);

        if (a.check_hp() <= 0)
        {
            cout << "YOU DIED" << endl;
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
            cout << "YOU DIED" << endl;
            return 0;
        }

        a.act(b);
        if (b.check_hp() <= 0)
        {
            cout << "Victory!" << endl;
            return 0;
        }
    }
    }
    return 0;
}

string ask_name()
{
    string getnm;
    cout << "What is your name?" << endl;
    cin >> getnm;
    return getnm;
}

void lock_stat1(Player &plr, int stat1)
{

    int strp;
    int dexp;
    int attp;
    int choice;
    int cnt = 1;
    cout << "Where would you like to apply your " << stat1 << endl;

    if (plr.get_str() <= 0)
    {
        cout << cnt << ". Strength" << endl;
        strp = cnt;
        cnt++;
    }

    if (plr.get_dex() <= 0)
    {
        cout << cnt << ". Dexterity" << endl;
        dexp = cnt;
        cnt++;
    }

    if (plr.get_att() <= 0)
    {
        cout << cnt << ". Attunement" << endl;
        attp = cnt;
        cnt++;
    }

    cin >> choice;

    if (choice == strp)
    {
        plr.set_str(stat1);
    }

    else if (choice == dexp)
    {
        plr.set_dex(stat1);
    }

    else if (choice == attp)
    {
        plr.set_dex(stat1);
    }

    else
    {
        lock_stat1(plr, stat1);
    }
}

void lock_stat2(Player &plr, int stat2)
{

    int strp;
    int dexp;
    int attp;
    int choice;
    int cnt = 1;
    cout << "Where would you like to apply your " << stat2 << endl;

    if (plr.get_str() <= 0)
    {
        cout << cnt << ". Strength" << endl;
        strp = cnt;
        cnt++;
    }

    if (plr.get_dex() <= 0)
    {
        cout << cnt << ". Dexterity" << endl;
        dexp = cnt;
        cnt++;
    }

    if (plr.get_att() <= 0)
    {
        cout << cnt << ". Attunement" << endl;
        attp = cnt;
        cnt++;
    }

    cin >> choice;

    if (choice == strp)
    {
        plr.set_str(stat2);
    }

    else if (choice == dexp)
    {
        plr.set_dex(stat2);
    }

    else if (choice == attp)
    {
        plr.set_dex(stat2);
    }

    else
    {
        lock_stat2(plr, stat2);
    }
}

void lock_stat3(Player &plr, int stat3)
{

    int strp;
    int dexp;
    int attp;
    int choice;
    int cnt = 1;
    cout << "Where would you like to apply your " << stat3 << endl;

    if (plr.get_str() <= 0)
    {
        cout << cnt << ". Strength" << endl;
        strp = cnt;
        cnt++;
    }

    if (plr.get_dex() <= 0)
    {
        cout << cnt << ". Dexterity" << endl;
        dexp = cnt;
        cnt++;
    }

    if (plr.get_att() <= 0)
    {
        cout << cnt << ". Attunement" << endl;
        attp = cnt;
        cnt++;
    }

    cin >> choice;

    if (choice == strp)
    {
        plr.set_str(stat3);
    }

    else if (choice == dexp)
    {
        plr.set_dex(stat3);
    }

    else if (choice == attp)
    {
        plr.set_dex(stat3);
    }

    else
    {
        lock_stat3(plr, stat3);
    }
}

void cust_class(Player &plr)
{
    int stat1;
    int stat2;
    int stat3;
    chrono::seconds dura( 1);
    this_thread::sleep_for( dura );
    srand (time(NULL));
    stat1 = rand() % 20 + 1;
    this_thread::sleep_for( dura );
    stat2 = rand() % 20 + 1;
    this_thread::sleep_for( dura );
    stat3 = rand() % 20 + 1;
    cout << "You rolled "<<stat1<<", "<<stat2<<", and "<<stat3<< endl;
    lock_stat1(plr, stat1);
    lock_stat2(plr, stat2);
    lock_stat3(plr, stat3);
}

void choose_class(Player &plr)
{
    Warrior war;
    Mage mag;
    Rogue rog;
    int class_choice;
    cout << "Now tell me. Are you a Warrior, Mage, Rogue, or something else?" << endl;
    cout << "1. Warrior - A brute who relies on strength and heavy weapons to dispatch foes." << endl;
    cout << "2. Mage - A magic user who can cast a variety of spells." << endl;
    cout << "3. Rogue - A nimble fighter gifted in the use of light weapons and bows." << endl;
    //cout << "4. Something Else (Custom Class)" << endl;
    cin >> class_choice;
    if (class_choice == 1)
    {
        //sets player to warrior stats
        plr = war;
    }

    else if (class_choice == 2)
    {
        //sets player to mage stats
        plr = mag;
    }

    else if (class_choice == 3)
    {
        //sets player to mage stats
        plr = rog;
    }

    /*else if (class_choice == 4)
    {
        string confirm;
        cout << "Creating a Custom Class is a gamble. Your stats could be high or low. Once rolled, there is no going back." << endl;
        cout << "Are you sure you want to create a Custom Class? Type 'I AM SURE' to confirm. Type anything else to choose a new class." << endl;
        cin >> confirm;
        if (confirm == "I AM SURE")
        {

        }
        else
        {
            choose_class(plr);
        }

    }*/

    else
    {
        throw "Invalid Input";
        //choose_class(plr);
    }
}

void create_character(Player &plr)
{
    string my_name;
    cout << "First things first..." << endl;
    my_name = ask_name();
    cout << "Welcome, " << my_name << "!" << endl;
    try
    {
        choose_class(plr);
    }catch (const char* msg)
    {
        cerr << msg << endl;
        choose_class(plr);
    }
    //choose_class(plr);
    plr.set_name(my_name);
    cout << "Okay, let's begin." << endl;
}
}
