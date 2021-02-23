#pragma once
#include "BSTnode.h"
#include "hufNode.h"
#include "Tav.h"
#include <iostream>

namespace huf
{
	class BSTree
	{
	private:
		BstNode* _root;
		int num_nodes;

		void make_empty(BstNode* root); //For the use of the distructor only
		void in_print(BstNode* root); //for the use of the print_inorder use only DEBUG purposes only
		void FindMin(BstNode* subroot, BstNode** parent, BstNode** min); //For the use of the Delete only thus private

	public:

		BSTree();
		~BSTree();
		BstNode* Find(char key);
		int get_size() const;
		void Insert(Tav item);
		hufNode** build_hufnode_array();
		void build_from_file(std::string fname);
		void print_inorder();
		void Delete(char key);

       
	};
}