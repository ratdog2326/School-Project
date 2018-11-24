
#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__


#include "actor.hpp"
/*
this class is to be used by
*/
//training dummy is derived from actor
class Player : public Actor
{
public:
    Player(void);
    void act(Actor &d);
};



#endif
