#include "BSTnode.h"
#include "Tav.h"

namespace huf
{
	BstNode::BstNode(Tav data, BstNode* left, BstNode* right) : _data(data), _left(left), _right(right) {}
	BstNode::~BstNode() {}
}
