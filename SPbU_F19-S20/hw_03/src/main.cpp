#include "huffman.h"
#include <iostream>

int main()
{
    std::vector<TreeNode> v = {
	TreeNode(1, "r"),
	TreeNode(1, "!"),
	TreeNode(2, "o"),
	TreeNode(2, " "),
	TreeNode(3, "b"),
	TreeNode(4, "e")
    };
    HuffTree ht = HuffTree(v);
    ht.build();
    return 0;
}
