#include "hufNode.h"
#include "Tav.h"

namespace huf
{
	hufNode::hufNode()
	{
		ch = -1; //there is no negative ASCII value- ctrl purposes when building a new node
		frequency = -1;
		depth = 0;
		to_print = '3';
		left = nullptr;
		right = nullptr;
	}
	hufNode::hufNode(Tav& tav)
	{
		ch = tav.get_char();
		frequency = tav.get_freq();
		depth = 0;
		to_print = '3';
		left = nullptr;
		right = nullptr;
	}

	hufNode::~hufNode() {}

	hufNode* hufNode::Left()
	{
		return left;
	}
	hufNode* hufNode::Right()
	{
		return right;
	}
	void hufNode::SetLeft(hufNode* node)
	{
		left = node;
	}
	void hufNode::SetRight(hufNode* node)
	{
		right = node;
	}
	int hufNode::get_frequency()
	{
		return frequency;
	}
	void hufNode::set_frequency(int num)
	{
		frequency = num;
	}



	const hufNode& hufNode::operator=(const Tav& tav)
	{
		ch = tav.get_char();
		frequency = tav.get_freq();
		return *this;
	}



	 std::ostream& operator<<(std::ostream& os, const hufNode& tav)
	{
		 return os << "ch: " << tav.ch << " freq: " << tav.frequency << " depth: " << tav.depth  << std::endl;

	}

}