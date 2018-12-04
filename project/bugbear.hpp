#ifndef __BUGBEAR_HPP__
#define __BUGBEAR_HPP__


#include "actor.hpp"
class Bugbear : public Actor
{
public:
    Bugbear(void);
    void act(Actor &c);
};

#endif
