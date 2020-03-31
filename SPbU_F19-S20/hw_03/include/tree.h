#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <utility>
#include <string>

class TreeNode {
    public:
	size_t weight_;
	char value_;
	TreeNode *left_children_, *right_children_;

	TreeNode(char value = ' ', size_t weight = 0, TreeNode* left_children = nullptr, TreeNode* right_children = nullptr);
	~TreeNode();

	class Compar {
	public:
	    bool operator()(TreeNode* a, TreeNode* b);
	};
};

class HuffTree {
    private:
	TreeNode* root;
	std::unordered_map< char, std::string > code_table_;
    public:
	HuffTree();
	~HuffTree();

	void build(std::vector<int> stat_table);
	void gen_relative_code(TreeNode* head, std::string code="");

	TreeNode* get_root();
	std::unordered_map< char, std::string >* get_code_table();
};

