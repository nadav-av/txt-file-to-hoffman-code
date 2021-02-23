#include "hufTree.h"
#include "BSTree.h"
#include "minHeap.h"
#include <iostream>
#include <iomanip> //only for aligning text so output will look nice
using namespace std;

namespace huf
{
	HufTree::HufTree()
	{
		_root = nullptr;
		weight = 0;
	}

	HufTree::HufTree(hufNode* root)
	{
		_root = root;
		weight = 0;
	}


	void HufTree::release(hufNode* root)
	{
		if (root)
		{
			release(root->left);
			release(root->right);
			delete root;
		}
	}

	HufTree::~HufTree()
	{
		release(_root);
	}

	//Called from main- bulds a Huffman tree from BS tree of the input file (charachters as keys)
	void HufTree::Huffman(BSTree& bs_tree)
	{
		int size = bs_tree.get_size();

		hufNode** C = new hufNode*[size];
		C= bs_tree.build_hufnode_array();
		_root = Huffman(C, size);
		update_depths(_root, 0); //after tree is formed- assign depths to nodes for later calculation of weight
	}


	/*Builds huffman tree from given C array of huffnodes */
	hufNode* HufTree::Huffman(hufNode* C[], int size)
	{
		minHeap Q(C, size); //Makig Heap from C (by floyd algorithem)

		for (int i = 1; i < size; i++)
		{
			hufNode* node = new hufNode;
			node->SetLeft(Q.DeleteMin()); //set the left child min of heap
			node->left->to_print = '0'; //left chiled assigned as 0 in code path
			node->SetRight(Q.DeleteMin());//set the right child min of heap
			node->right->to_print = '1'; //right chiled assigned as 1 in code path
			int sum = node->Left()->get_frequency() + node->Right()->get_frequency(); //combined frequencey for the node
			node->set_frequency(sum);
			Q.Insert(node); //insert back to heap untill all array has been sorted and huffman tree has formed (except of the root)
		}
		return Q.DeleteMin(); //assign the root to all of the tree
	}


	/*This function prints all paths from root to leaf recursivly using static string as "stack"
	for keeping and printing the right path at the end of every leaf*/
	void HufTree::print_codes(hufNode* node)
	{
		static string path = "";
		if (node == nullptr) //if null nothing to add delete or print - return
			return;

		if (node != _root)
			path.append(1, node->to_print); //if its not the root appends a 1 or 0 to path

		print_codes(node->left); // recursive call for left child

		if (isLeaf(node)) //if leaf- we want to print path and update weight of the tree
		{
			if (node->ch == ' ')
			{
				cout << setw(15) << left << path;
				cout << setw(15) << left << "' '" << endl << endl;
			}

			if (node->ch == '\n')
			{
				cout << setw(15) << left << path;
				cout << setw(15) << left << "\\n" << endl << endl;
			}

			else
			{
				cout << setw(15) << left << path;
				cout << setw(15) << left << node->ch << endl << endl;
			}
			this->weight += (node->depth * node->frequency);

		}

		print_codes(node->right);  // recursive call for left child


		if (node != _root)
			path.erase(path.length() - 1); //removes the last character of the path - because its already been printed and recursivly goes back to parent
	}

	//Called from main - if tree contains only node- prints from here- else calls to print_codes function
	void HufTree::print_codes_and_size()
	{
		cout << "Character encoding: " << endl << endl;
		cout << setw(15) << left << "CODE";
		cout << setw(15) << left << "CHARACTER";
		cout << endl << endl;

		if (isLeaf(_root))
		{
			weight = _root->frequency; //if if only one character - weight is frequency times 1 so =frequency
			cout << setw(15) << left << "1";
			cout << setw(15) << left << _root->ch << endl << endl;
		}
		else
		{
			this->print_codes(_root);
		}
		cout << "================================================" << endl;
		cout << "coded file weight: " << this->weight << " bits." << endl;  //pring wieight of tree
	}



	bool HufTree::isLeaf(hufNode* node)
	{
		if (node->Left() == nullptr && node->Right() == nullptr)
			return true;
		else return false;
	}






	/*goes through huffman treeand assign depth to each of the nodes for later calculations*/
	void HufTree::update_depths(hufNode* node, int level)
	{
		if (node == nullptr)
			return;
		else
		{
			node->depth = level;
			level++;
			update_depths(node->left, level);
			update_depths(node->right, level);
		}
	}


	//Print the BS tree in Inorder- DEBUG purpose
	void HufTree::in_print(hufNode* root)
	{
		if (root)
		{
			in_print(root->left);
			if(HufTree::isLeaf(root))
				std::cout << *root;
			in_print(root->right);
		}
	}

	//Print the BS tree in Inorder- DEBUG purposes 
	void HufTree::print_inorder()
	{
		hufNode* temp = _root;
		in_print(temp);
	}

}