#include "BSTnode.h"
#include "BSTree.h"
#include "Tav.h"
#include "minHeap.h"
#include "hufTree.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace huf;

#define DEBUG
	

int main(int argc, char* argv[])
{

	string inputfile;
	BSTree b_s_tree;
	cout << "Please enter file name: ";
	cin >> inputfile;
	cout << endl;
	b_s_tree.build_from_file(inputfile);
	HufTree huftree;
	huftree.Huffman(b_s_tree);
	huftree.print_codes_and_size();

	return 0;
}