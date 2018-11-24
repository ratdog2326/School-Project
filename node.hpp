#ifndef __NODE_HPP__
#define __NODE_HPP__
#include <iostream>
#include "actor.hpp"
using namespace std;

class Node
{
    int hp;
    int init;
    Node* link;
    Actor actr;
public:
    Node();
    Node(Actor act1);
    void set_link (Node* ptr);
    Node* get_link();
    int get_place();
    int get_hp();
};

#endif
