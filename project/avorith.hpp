#ifndef __AVORITH_HPP__
#define __AVORITH_HPP__


#include "actor.hpp"
class Avorith : public Actor
{
public:
    Avorith(void);
    void act(Actor &c);
};

#endif
