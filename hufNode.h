#pragma once
#include "Tav.h"

namespace huf
{
	class hufNode
	{
		private:
			char ch;
			int frequency; // number of appearances in the txt file
			int depth; //specifed the depth of the node in the huffman tree- for calculating the tree weight
			char to_print; // if its a left child =0 else =1;
			hufNode* left;
			hufNode* right;

		public:
			friend class HufTree;
			friend std::ostream& operator<<(std::ostream& os, const hufNode& tav);
			hufNode();
			hufNode(Tav& tav);
			~hufNode();

			hufNode* Left();
			hufNode* Right();
			void SetLeft(hufNode* node);
			void SetRight(hufNode* node);
			int get_frequency();
			void set_frequency(int num);
			const hufNode& operator=(const Tav& tav);
	};
}
