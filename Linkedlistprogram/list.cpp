//list.cpp
//William Fraser 30158991

#include <stdlib.h>
#include <iostream>
using namespace std;
#include "list.h"

FlowList::FlowList()
: headM(0) {}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

FlowList& FlowList::operator = (const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this; 
}

FlowList::~FlowList()
{
    destroy();
}

void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item.year = itemA.year;
    new_node->item.flow = itemA.flow;
    
    if (headM == 0 || itemA.year <= headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
    }

    else {
        Node *before = headM;
        Node *after = headM->next; 
        while(after != 0 && itemA.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void FlowList::remove(const int& itemA) //FIX
{
    if (headM == 0 || itemA < headM->item.year)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (maybe_doomed->item.year == itemA){
            before->next = maybe_doomed->next;
            doomed_node = maybe_doomed;
        }
    }
    if (doomed_node != 0)
       delete doomed_node;
}

void FlowList::destroy(){
    Node *remover = headM;
    Node *after;
    while (headM != 0){
        after = remover->next;
        delete remover;
        remover = after;
        headM = after;
    }
}

void FlowList::copy(const FlowList& source){
    if (source.headM != 0){
        Node *copy_pointer = source.headM;
        Node *copied_node = new Node;
        headM = copied_node;
        while (copy_pointer != 0){
            copied_node->item.year = copy_pointer->item.year;
            copied_node->item.flow = copy_pointer->item.flow;
            if(copy_pointer->next != 0){
                copied_node->next = new Node;
                copied_node = copied_node->next;
            }
            copy_pointer = copy_pointer->next;
        }
        copied_node->next = 0;
    }
    else
        headM = 0;
}

void FlowList::print() const{
    if (headM != 0) {
        cout << headM->item.year << "\t" << headM->item.flow << endl;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << p->item.year << "\t" << p->item.flow << endl;
    }
}

Node * FlowList::get_first(){
    return headM;
}
