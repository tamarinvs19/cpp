#include "huffman.h"
#include <iostream>

int main()
{
    // std::vector<TreeNode> v = {
    // TreeNode(1, "r"),
    // TreeNode(1, "!"),
    // TreeNode(2, "o"),
    // TreeNode(2, " "),
    // TreeNode(3, "b"),
    // TreeNode(4, "e")
    // };
    // HuffTree ht = HuffTree(v);
    // ht.build();
    HuffmanArchiver ha = HuffmanArchiver("t1", "test_t1");
    ha.archivate();
    ha.unarchivate();
    
    return 0;
}
