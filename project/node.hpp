#ifndef __NODE_HPP__
#define __NODE_HPP__
#include <iostream>
#include "actor.hpp"
using namespace std;

class Node
{
    bool is_plyr;
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
    Actor get_actor();
    void take_turn();
    bool check_plyr();
    void take_turn();
};

#endif
