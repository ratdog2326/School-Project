#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "player.hpp"
//#include "actor.cpp"

Player::Player(void)
{
    /*
    name = "You";
    ac = 10;
    max_hp = 30;
    cur_hp = max_hp;
    max_mana = 0;
    cur_mana = max_mana;
    str = 0;
    dex = 0;
    att = 0;
    hp_ptn_cnt = 3;
    mana_ptn_cnt = 0;
//    is_player = true;
    has_sword = false;
    has_dagger = false;
    has_bow = false;
    has_axe = false;
    has_magmis = false;
    has_fireball = false;
    arrows = 0;
    roll_stats(str, dex, att);*/
}


//Player::Player(int s, int d, int a, int arr, bool swo, bool bow, bool dag, bool axe, bool fir, bool mag)



void Player::attack(Actor &c)
{
    int choice;
    int cnt = 1;
    int sword_pick;
    int bow_pick;
    int holy_sword_pick;
    int holy_bow_pick;
    int dagger_pick;
    int axe_pick;
    cout << "Attack with what?" << endl;
    cout << "0. Previous menu" << endl;
    //lists weapons
    if (has_sword == true)
    {
        cout << cnt << ". Sword" << endl;
        sword_pick = cnt;
        cnt++;
    }

    if (has_bow == true)
    {
        cout << cnt << ". Bow - Arrows remaining: " << arrows << endl;
        bow_pick = cnt;
        cnt++;
    }

    if (has_dagger == true)
    {
        cout << cnt << ". Dagger" << endl;
        dagger_pick = cnt;
        cnt++;
    }

    if (has_axe == true)
    {
        cout << cnt << ". Battle Axe" << endl;
        axe_pick = cnt;
        cnt++;
    }

    if (has_holy_sword == true)
    {
        cout << cnt << ". Holy Blade" << endl;
        holy_sword_pick = cnt;
        cnt++;
    }

    if (has_holy_bow == true)
    {
        cout << cnt << ". Sanctified Bow - Arrows remaining: " << arrows << endl;
        holy_bow_pick = cnt;
        cnt++;
    }

    //lets players choose
    cin >> choice;
    if (choice == 0)
    {
        act(c);
    }
    else if (choice == sword_pick)
    {
        use_sword(c);
    }
    else if (choice == bow_pick)
    {
        if(arrows > 0)
        {
            use_bow(c);
            arrows--;
        }
        else
        {
            cout << "You have no arrows!" << endl;
            attack(c);
        }
    }

    else if (choice == holy_bow_pick)
    {
        if(arrows > 0)
        {
            use_holy_bow(c);
            arrows--;
        }
        else
        {
            cout << "You have no arrows!" << endl;
            attack(c);
        }
    }

    else if (choice == dagger_pick)
    {
        use_dagger(c);
    }

    else if (choice == axe_pick)
    {
        use_axe(c);
    }

    else if (choice == holy_sword_pick)
    {
        use_holy_sword(c);
    }

    else
    {
        cout << "Invalid Input" << endl;
        attack(c);
    }

}

void Player::add_hp_ptns(int p)
{
    hp_ptn_cnt += p;
}

void Player::add_mn_ptns(int p)
{
    mana_ptn_cnt += p;
}

void Player::add_arrows(int p)
{
    arrows += p;
}

void Player::give_holy_sword()
{
    if(has_holy_sword == false)
    {
        has_holy_sword = true;
        cout << "You have found Avorith's Holy Blade!" << endl;
    }
}

void Player::give_sword()
{
    if(has_sword == false)
    {
        has_sword = true;
        cout << "You have picked up a sword!" << endl;
    }
}

void Player::give_holy_bow()
{
    if(has_holy_bow == false)
    {
        has_holy_bow = true;
        cout << "You have found Avorith's Holy Bow!" << endl;
    }
}

void Player::give_bow()
{
    if(has_bow == false)
    {
        has_bow = true;
        cout << "You have picked up a bow!" << endl;
    }
}

void Player::give_holy_fury()
{
    if(has_holy_fury == false)
    {
        has_holy_fury = true;
        cout << "You have found Avorith's Divine Tome and learned Divine Fury!" << endl;
    }
}

void Player::give_magmis()
{
    if(has_magmis == false)
    {
        has_magmis = true;
        cout << "You have found an Arcane Tome and learned Magic Missile!" << endl;
    }
}

void Player::use_item(Actor &c)
{
    int choice;
    int cnt = 1;
    int hp_pick;
    int mn_pick;
    cout << "Use what item?" << endl;

    cout << "0. Previous menu" << endl;

    if (hp_ptn_cnt > 0)
    {
        cout << cnt << ". Health Potion - " << hp_ptn_cnt << " remaining" << endl;
        hp_pick = cnt;
        cnt++;
    }

    if (mana_ptn_cnt > 0)
    {
        cout << cnt << ". Mana Potion - " << mana_ptn_cnt  << " remaining"<< endl;
        mn_pick = cnt;
        cnt++;
    }

    cin >> choice;

    if (choice == 0)
    {
        act(c);
    }

    else if (choice == hp_pick)
    {
        use_hp_ptn();
    }

    else if (choice == mn_pick)
    {
        use_mn_ptn();
    }


}

void Player::cast_spell(Actor &c)
{
    int choice;
    int cnt = 1;
    int mm_pick;
    int fb_pick;
    int hl_pick;
    int df_pick;
    cout << "Cast what spell?" << endl;
    cout << "Mana: " << cur_mana << "/" << max_mana << endl;
    cout << "0. Previous menu" << endl;
    //lists weapons
    if (has_magmis == true)
    {
        cout << cnt << ". Magic Missile - Cost: 5 Mana" << endl;
        mm_pick = cnt;
        cnt++;
    }

    if (has_fireball == true)
    {
        cout << cnt << ". Fireball - Cost: 15 Mana " << endl;
        fb_pick = cnt;
        cnt++;
    }

    if (has_heal == true)
    {
        cout << cnt << ". Heal - Cost: 8 Mana " << endl;
        hl_pick = cnt;
        cnt++;
    }

    if (has_holy_fury == true)
    {
        cout << cnt << ". Divine Fury - Cost: 20 Mana" << endl;
        df_pick = cnt;
        cnt++;
    }

    //lets players choose
    cin >> choice;
    if (choice == 0)
    {
        act(c);
    }
    else if (choice == mm_pick)
    {
        if(cur_mana >= 5)
        {
            cast_magmis(c);
            cur_mana = cur_mana - 5;
        }
        else
        {
            cout << "Not enough Mana!" << endl;
            cast_spell(c);
        }
    }
    else if (choice == fb_pick)
    {
        if(cur_mana >= 15)
        {
            cast_fireball(c);
            cur_mana = cur_mana - 15;
        }
        else
        {
            cout << "Not enough Mana!" << endl;
            cast_spell(c);
        }
    }

    else if (choice == hl_pick)
    {
        if(cur_mana >= 8)
        {
            cast_heal(c);
            cur_mana = cur_mana - 8;
        }
        else
        {
            cout << "Not enough Mana!" << endl;
            cast_spell(c);
        }
    }

    else if (choice == df_pick)
    {
        if(cur_mana >= 20)
        {
            cast_heal(c);
            cur_mana = cur_mana - 20;
        }
        else
        {
            cout << "Not enough Mana!" << endl;
            cast_spell(c);
        }
    }

    else
    {
        cout << "Invalid Input" << endl;
        attack(c);
    }
}

bool Player::check_sword()
{
    return has_sword;
}

bool Player::check_axe()
{
    return has_axe;
}

bool Player::check_bow()
{
    return has_bow;
}

void Player::act(Actor &c)
{
    int input;
    cout << "It's your turn..." << endl;
    cout << "Your HP: " << cur_hp << "/" << max_hp << endl;
    cout << "Enemy HP: " << c.check_hp() << "/" << c.get_max_hp() << endl;
    cout << "1. Attack" << endl;
    cout << "2. Use Item" << endl;
    cout << "3. Cast Spell" << endl;
    cin >> input;
    if (input == 1)
    {
        attack(c);
    }
    else if (input == 2)
    {
        use_item(c);
    }
    else if (input == 3)
    {
        cast_spell(c);
    }
    else
    {
        cout << "Invalid input" << endl;
        act(c);
        //todo: change this to error handling
    }
}
