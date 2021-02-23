#pragma once
#include <iostream>
#include "BSTnode.h"
using namespace huf;

// A structure to represent a stack
class StackNode {
private:
    BstNode* item;
    StackNode* next;
    
private:
    friend class Stack;
    StackNode();
    StackNode(BstNode* data, StackNode* next);
    StackNode(BstNode* data);
    ~StackNode();

};
