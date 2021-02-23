#include <iostream>
#include "stacknode.h"
#include "BSTnode.h"


StackNode::StackNode()
{
	BstNode* data= nullptr;
	this->item = data;
	this->next = nullptr;
}

StackNode::StackNode(BstNode* data, StackNode* next)
{	
	this->item = data;
	this->next = next;
}

StackNode::StackNode(BstNode* data)
{
	this->item = data;
	this->next = nullptr;
}


StackNode::~StackNode()
{

}

