#ifndef __VAMPIRE_HPP__
#define __VAMPIRE_HPP__


#include "actor.hpp"
class Vampire : public Actor
{
public:
    Vampire(void);
    void act(Actor &c);
};

#endif
