#ifndef __THRONE_HPP__
#define __THRONE_HPP__
#include <iostream>
#include "room.hpp"

class Throne : public Room
{
public:
    Throne(void);
    int run_room(Player &plr);
};

#endif
