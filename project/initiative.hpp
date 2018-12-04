#ifndef __INITIATIVE_HPP__
#define __INITIATIVE_HPP__
#include "node.hpp"
#include <iostream>
using namespace std;

class Initiative
{
    Node* first;
    Node* last;
    int total;
public:
    Initiative();
    void insert(Actor actr1); //move trough initiative and place actor in correct place
    void remove_killed(); //after every turn, go through list and remove dead actors
    void start_battle();
};

#endif
