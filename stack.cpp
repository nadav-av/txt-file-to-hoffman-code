#include "stack.h"

class StackNode;


Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	this->make_empty();
}

void Stack::make_empty()
{
	StackNode* temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}
bool Stack::is_empty()
{
	if (top==nullptr) return true;
	else return false;
}
void Stack::Push(BstNode* item)
{
	top = new StackNode(item, top);
}
BstNode* Stack::Pop()
{
	if (this->is_empty())
	{
		BstNode* item = nullptr; //will be nullptr in all arrays for ctrl purposes - but also prints error here (default values)
		std::cout << "No item in stack" << std::endl;
		return item ;
	}
	else
	{
		BstNode* item = top->item;
		top = top->next;
		return item;
	}
}
BstNode* Stack::Top()
{
	if (this->is_empty())
	{
		BstNode* item = nullptr; //will be nullptr in all arrays for ctrl purposes - but also prints error here (default values)
		std::cout << "No item in stack" << std::endl;
		return item;
	}
	else
	{
		BstNode* item = top->item;
		return item;
	}
}
