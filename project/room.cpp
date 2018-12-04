#include "room.hpp"
#include <iostream>
using namespace std;
using namespace My_game;

Room::Room(void)
{
    hp_ptns = 0;
    mn_ptns = 0;
    arrow_count = 0;
    dummy_count = 2;
    goblin_count = 0;
    hobgoblin_count = 0;
    path_left = 0;
    path_right = 0;
    path_return = 0;
    deadend = false;
    holds_sword = false;
    holds_bow = false;
    holds_magmis = false;
    holds_holy_sword = false;
    holds_holy_bow = false;
    holds_holy_spell = false;
    bugbear_count = 0;
    vampire_count = 0;
    description = "You are in an empty room. You can find no exits.";
}

int Room::run_room(Player &plr)
{
    Actor opnt;
    if (dummy_count > 0) //if dummies exist, run combat for each while they exist
    {
        cout << "There are " << dummy_count << " dummies in the room!" << endl;
        while (dummy_count > 0)
        {
            opnt = make_dummy();
            combat(plr, opnt);
            dummy_count--;
            if (dummy_count > 0)
            {
                cout << "Dummies remaining: " << dummy_count << endl;
            }
            else
            {
                cout << "All dummies defeated!" << endl;
            }
        }
    }
    if(goblin_count > 0)
    {
        cout << "Goblins in area: " << goblin_count << endl;
    }

    if(hobgoblin_count > 0)
    {
        cout << "Hobgoblins in area: " << hobgoblin_count << endl;
    }

    if(bugbear_count > 0)
    {
        cout << "Bugbears in area: " << bugbear_count << endl;
    }

    if(vampire_count > 0)
    {
        cout << "Vampires in area: " << hobgoblin_count << endl;
    }
    if(goblin_count > 0)
    {
        while (goblin_count > 0)
        {
            opnt = make_goblin();
            combat(plr, opnt);
            goblin_count--;
            if (goblin_count > 0)
            {
                cout << "Goblins remaining: " << goblin_count << endl;
            }
            else
            {
                cout << "All goblins defeated!" << endl;
            }
        }
    }

    if(hobgoblin_count > 0)
    {
        while (hobgoblin_count > 0)
        {
            opnt = make_hobgoblin();
            combat(plr, opnt);
            hobgoblin_count--;
            if (hobgoblin_count > 0)
            {
                cout << "Hobgoblins remaining: " << hobgoblin_count << endl;
            }
            else
            {
                cout << "All hobgoblins defeated!" << endl;
            }
        }
    }

    if(bugbear_count > 0)
    {
        while (bugbear_count > 0)
        {
            opnt = make_bugbear();
            combat(plr, opnt);
            bugbear_count--;
            if (bugbear_count > 0)
            {
                cout << "Bugbears remaining: " << goblin_count << endl;
            }
            else
            {
                cout << "All bugbears defeated!" << endl;
            }
        }
    }

    if(vampire_count > 0)
    {
        while (vampire_count > 0)
        {
            opnt = make_vampire();
            combat(plr, opnt);
            goblin_count--;
            if (vampire_count > 0)
            {
                cout << "Vampires remaining: " << goblin_count << endl;
            }
            else
            {
                cout << "All vampires defeated!" << endl;
            }
        }
    }
    if(plr.check_hp() > 0)
    {
        describe_room();
        cout << "While searching, you found..." << endl;
        if (((hp_ptns == 0) && (mn_ptns == 0)) && (arrow_count == 0))
        {
            cout << "Nothing of value." << endl;
        }
        if (hp_ptns > 0)
        {
            cout << hp_ptns << " Health Potions" << endl;
            plr.add_hp_ptns(hp_ptns);
            hp_ptns = 0;
        }
        if (mn_ptns > 0)
        {
            cout << mn_ptns << " Mana Potions" << endl;
            plr.add_mn_ptns(mn_ptns);
            mn_ptns = 0;
        }
        if (arrow_count > 0)
        {
            cout << arrow_count << " Arrows" << endl;
            plr.add_arrows(arrow_count);
            arrow_count = 0;
        }

        if(holds_sword == true)
        {
            plr.give_sword();
            holds_sword = false;
        }

        if(holds_bow == true)
        {
            plr.give_bow();
            holds_bow = false;
        }

        if(holds_magmis == true)
        {
            plr.give_magmis();
            holds_magmis = false;
        }

        if(holds_holy_sword == true)
        {
            plr.give_holy_sword();
            holds_holy_sword = false;
        }

        if(holds_holy_bow == true)
        {
            plr.give_holy_bow();
            holds_holy_bow = false;
        }

        if(holds_holy_spell == true)
        {
            plr.give_holy_fury();
            holds_holy_spell = false;
        }

        level_up(plr);
        deadend = false;

        int path = pick_path();
        return path;
    }
    else
    {
        return 99;
    }

}

void Room::level_up(Player &plr)
{
    if (deadend == true)
    {
        int attribute;
        cout << "LEVEL UP!" << endl;
        cout << "Choose an attribute to increase" << endl;
        cout << "1. Strength" << endl;
        cout << "2. Dexterity" << endl;
        cout << "3. Attunement" << endl;
        cin >> attribute;
        if (attribute == 1)
        {
            int increase = plr.get_str();
            increase += 2;
            plr.set_str(increase);
            plr.roll_stats(plr.get_str(), plr.get_dex(), plr.get_att());
            plr.level_stats();
        }

        else if (attribute == 2)
        {
            int increase = plr.get_dex();
            increase += 2;
            plr.set_dex(increase);
            plr.roll_stats(plr.get_str(), plr.get_dex(), plr.get_att());
            plr.level_stats();
        }

        if (attribute == 3)
        {
            int increase = plr.get_att();
            increase += 2;
            plr.set_att(increase);
            plr.roll_stats(plr.get_str(), plr.get_dex(), plr.get_att());
            plr.level_stats();
        }

        else
        {
            cout << "Invalid Input" << endl;
            level_up(plr);
        }

    }
}

int Room::pick_path()
{
    cout << "Which way would you like to go?" << endl;
    int choose_left;
    int choose_right;
    int choose_return;
    int direction;
    int cnt = 1;
    if (path_left != 0)
    {
        cout << cnt << ". Left" << endl;
        choose_left = cnt;
        cnt++;
    }
    if (path_right != 0)
    {
        cout << cnt << ". Right" << endl;
        choose_right = cnt;
        cnt++;
    }
    if (path_return != 0)
    {
        cout << cnt << ". Preceeding Area" << endl;
        choose_return = cnt;
        cnt++;
    }
    cin >> direction;
    cin.ignore();
    if (direction == choose_left)
    {
        return path_left;
    }

    else if (direction == choose_right)
    {
        return path_right;
    }

    else if (direction == choose_return)
    {
        return path_return;
    }

    else
    {
        pick_path();
        return 0;
    }
}

void Room::describe_room()
{
    cout << description << endl;
}

Actor Room::make_dummy()
{
    Dummy dum;
    return dum;
}

Actor Room::make_goblin()
{
    Goblin gob;
    return gob;
}

Actor Room::make_hobgoblin()
{
    Hobgoblin hob;
    return hob;
}

Actor Room::make_bugbear()
{
    Bugbear bug;
    return bug;
}

Actor Room::make_vampire()
{
    Vampire vam;
    return vam;
}
