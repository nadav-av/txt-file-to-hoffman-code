#include "BSTnode.h"
#include "BSTree.h"
#include "Tav.h"
#include "stack.h"
#include "hufNode.h"
#include <iostream>
#include <fstream>

#define DEBUG

using namespace std;

namespace huf
{
	BSTree::BSTree() : _root(nullptr), num_nodes(0) {}

	/*For Dtor use, recursivly free all the tree*/
	void BSTree::make_empty(BstNode* root)
	{
		if (root)
		{
			make_empty(root->_left);
			make_empty(root->_right);
			delete root;
		}
	}
	BSTree::~BSTree()
	{
		make_empty(_root);
	}


	/*This function reads charachter by character from given file and insert it to the tree.
	This is the way the BStree is built accuratly from my given file*/
	void BSTree::build_from_file(string fname)
	{
		ifstream myfile(fname);
		char* ch= new char;
		Tav to_insert;
		int count = 1;

		while (myfile.read(ch, 1)) //When Eof -> returns null;
		{
			to_insert.set_char(*ch);
			to_insert.set_freq(1); //if it is the first will say 1, if not it will be added to the excisting so add one.
			this->Insert(to_insert);
		}
		delete ch;
	}

	/*Find and returns a node of the BStree if exists - if not returns null*/
	BstNode* BSTree::Find(char key)
	{
		BstNode* temp = _root;
		while (temp)
		{
			if (key == temp->_data.get_char())
				return temp;
			else if (key < temp->_data.get_char())
				temp = temp->_left;
			else temp = temp->_right;
		}

		return nullptr;
	}

	/*Insert a node to the rgiht place in binary search tree - if key already found-> add 1 to data*/
	void BSTree::Insert(Tav item)
	{
		BstNode* check = Find(item.get_char());
		if (check)
		{
			check->_data.add_to_freq(); //adds 1 to frequency of `key` (character appearances)
		}
		else
		{
			num_nodes++;
			char ch = item.get_char();
			BstNode* temp = _root;
			BstNode* parent = nullptr;
			BstNode* newnode;

			while (temp != nullptr)
			{
				parent = temp;
				if (ch < temp->_data.get_char())
					temp = temp->_left;
				else temp = temp->_right;
			}

			newnode = new BstNode(item);
			if (parent == nullptr) //means its first node to be inserted
				_root = newnode;

			else if (ch < parent->_data.get_char())
				parent->_left = newnode;
			else parent->_right = newnode;
		}
	}



	/*this function usuing a stack to build an array- inporder iterative traversal. 
	this array will be the C array which will be send to heap ctor later to build from it hoffman tree.*/
	hufNode** BSTree::build_hufnode_array()
	{
		hufNode** arr = new hufNode*[num_nodes];
		Stack s;
		int i = 0;
		BstNode* curr = _root;

		while (curr != NULL || s.is_empty() == false)
		{

			while (curr != NULL)
			{
				s.Push(curr);
				curr = curr->_left;
			}
			curr = s.Top();
			s.Pop();
			hufNode* item = new hufNode(curr->_data);
			arr[i] = item;
			i++;

			curr = curr->_right;
		}

		return arr;
	}

	/*Returns the number of the nodes in the tree.
	used for building the C array, in Huffman tree builder for the heap*/
	int BSTree::get_size() const
	{
		return num_nodes;
	}

	void BSTree::Delete(char key)
	{
		BstNode* temp = Find(key);
		BstNode* parent= temp;
		bool find = false;
		while (!find)
		{
			parent = temp;
			if (key < temp->_data.get_char())
				temp = temp->_left;
			else if (key > temp->_data.get_char())
				temp = temp->_left;
			else find == true;
		}
		if (temp->_left == nullptr && temp->_right == nullptr) //if the node to be deleted is leaf
		{
			if (parent->_left == temp)
			{
				parent->_left = nullptr;
				delete temp;
			}
			else
			{
				parent->_right = nullptr;
				delete temp;
			}
		}

		if (temp->_left == nullptr) //if the node to be deleted has only right child
		{
			parent->_right == temp->_right;
			delete temp; 
		}
		else if (temp->_right == nullptr) //if the node to be deleted has only left child
		{
			parent->_right == temp->_right;
			delete temp;
		}
		else //if the node to be deleted have two children we need to find the minimum node in this sub tree
		{
			BstNode* minInRight;
			FindMin(temp->_right, &parent, &minInRight); //finding the min of right sub tree and save it parent so min can be deleted
			temp->_data = minInRight->_data; //put the min data of right sub-tree in top
			parent->_left = minInRight->_right; //if min had right child will be put to its parent left - can be nullptr also
			delete minInRight; //delete the min which its data went to top- so can delete this one

		}

	}

	//finding the min of given subtree and saves it parent also so it could be deleted - used in delete function only thus private
	void BSTree::FindMin(BstNode* subroot, BstNode** parent, BstNode** min)
	{	
		BstNode* res = subroot;
		*parent = res;
		while (res->_left != nullptr)
		{
			*parent = res;
			res = res->_left;
		}
		*min = res;
	}



	//Rcursive function inorder tracersal print nodes - DEBUG purposes
	void BSTree::in_print(BstNode* root)
	{
		if (root)
		{
			in_print(root->_left);
			std::cout << root->_data;
			in_print(root->_right);
		}
	}

	//Print the BS tree in Inorder- DEBUG purposes 
	void BSTree::print_inorder()
	{
		BstNode* temp = _root;
		in_print(temp);
	}


}