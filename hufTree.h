#include "hufNode.h"
#include "BSTree.h"

namespace huf
{
	class HufTree
	{
		private:
			hufNode* _root;
			int weight; //weight in bits

			void in_print(hufNode* root);
			void release(hufNode* root);
			void update_depths(hufNode* node, int level); //assign depth to nodes- inner use this private
			bool isLeaf(hufNode* node); //check if a node is leaf - no use on the object thus private
		public:
			HufTree();
			HufTree(hufNode* root);
			~HufTree();
			void Huffman(BSTree& bs_tree);
			hufNode* Huffman(hufNode* C[], int size);
			void print_inorder();
			void print_codes(hufNode* node);
			void print_codes_and_size();
	};
}