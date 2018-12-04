#include <iostream>
using namespace std;
#include "initiative.hpp"

Initiative::Initiative()
{
    first = NULL;
    last = NULL;
    total = 0;
}

//adds an actor to initiative order
void Initiative::insert(Actor actr1)
{
    Node* temp = new Node(actr1);
    if(first == NULL) //if initiative is empty, add 1st combatant
    {
        first = last = temp;
        total++;
        return;
    }
    Node* curr = first;
    Node* prev = NULL;
    //add another if list is not empty
    while ((temp -> get_place() > curr -> get_place()) && curr != NULL)
    {
        prev = curr;
        curr = curr -> get_link();
    }
        prev -> set_link(temp);
        temp -> set_link(curr);
        total++;



}

//remove all actors with health < 0
void Initiative::remove_killed()
{
    int cnt = total;
    Node* curr = first;
    Node* prev = NULL;
    while (cnt > 0 && curr != NULL)
    {
        if(curr-> get_hp() <= 0)
        {
            prev -> set_link(curr->get_link());
            delete curr;
            total--;
            cnt--;
            remove_killed(); //recursively removes dead actors
        }
        prev = curr;
        curr = curr -> get_link();
        cnt--; //exit if all dead actors are removed
    }
}

void Initiative::start_battle()
{
    
}
