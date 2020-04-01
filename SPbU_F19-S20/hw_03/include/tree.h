#ifndef _TREE_H_
#define _TREE_H_

#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

namespace huffman_tree {
class TreeNode {
    public:
	const size_t weight_;
	const char value_;
	TreeNode *left_children_, *right_children_;

	TreeNode(const char value = ' ', const size_t weight = 0, 
		TreeNode* left_children = nullptr, TreeNode* right_children = nullptr);
	~TreeNode();

	class Compar {
	public:
	    bool operator()(const TreeNode* a, const TreeNode* b);
	};
};

class HuffTree {
    private:
	TreeNode* root;
	std::unordered_map< char, std::string > code_table_;
    public:
	~HuffTree();

	void build(std::vector<int> stat_table);
	void gen_relative_code(TreeNode* head, std::string code="");

	TreeNode* get_root();
	std::unordered_map< char, std::string >* get_code_table();
};
}
#endif
