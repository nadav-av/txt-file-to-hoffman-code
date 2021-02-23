#pragma once

#include "Tav.h"

namespace huf
{
	class BstNode
	{
	private:
		Tav _data;
		BstNode* _left;
		BstNode* _right;

	public:
		friend class BSTree;
		BstNode(Tav data, BstNode* left = nullptr, BstNode* right = nullptr);
		~BstNode();
	};
}