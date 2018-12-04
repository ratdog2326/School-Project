#include <iostream>
using namespace std;
#include "node.hpp"


//default constructor
Node::Node()
{
    hp = 0;
    actr = Actor();
    init = 0;
    link = NULL;
}

//overloaded constructor
Node::Node(Actor act1)
{
    hp = act1.check_hp();
    actr = act1;
    is_plyr = act1.check_plr();
    init = act1.roll_dex();
    link = NULL;
}

void Node::set_link(Node *ptr)
{
    link = ptr;
}

Node *Node::get_link()
{
    return link;
}

int Node::get_place()
{
    return init;
}

int Node::get_hp()
{
    return hp;
}

Actor Node::get_actor()
{
    return actr;
}

void Node::check_plyr()
{
    return is_plyr;
}

void Node::take_turn()
{
    act1.act();
}
/*
reference
class Node
{
    int init;
    Node* link;
public:
    Node();
    Node(int order);
    void set_link (Node* ptr);
    Node* get_link();
    int get_place();
};
*/
