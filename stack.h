#pragma once
#include <iostream>
#include "stacknode.h"
#include "BSTnode.h"

class Stack {
private:
	StackNode* top;

public:

	friend class StackNode;
	Stack();
	~Stack();
	void make_empty();
	bool is_empty();
	void Push(BstNode* item);
	BstNode* Pop();
	BstNode* Top();
};