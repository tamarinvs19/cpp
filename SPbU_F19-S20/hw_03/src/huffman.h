#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <utility>
#include <string>
#include <bitset>
#include <climits>

class TreeNode {
    private:
	int weight_;
	std::string value_, code_;
	TreeNode* left_children_;
	TreeNode* right_children_;
    public:
	TreeNode(int weight = 0, std::string value = "", TreeNode* left_children = 0, TreeNode* right_children = 0);
	~TreeNode();

	int get_weight();
	std::string get_value();
	std::string get_code();
	TreeNode* get_left_children();
	TreeNode* get_right_children();

	void gen_relative_code(std::string code);
};

class HuffTree {
    private:
	struct cmp {
	    bool operator()(TreeNode* a, TreeNode* b) {
		return a->get_weight() > b->get_weight();
	    };
	};
	std::priority_queue<TreeNode*, std::vector<TreeNode*>, cmp> nodes_;
    public:
	HuffTree(std::vector<TreeNode*> nodes);
	~HuffTree();

	TreeNode* join_nodes(TreeNode* left_node, TreeNode* right_node);
	void build();
	TreeNode* get_root();
};

class HuffmanArchiver {
    private:
	std::string file_in_;
	std::string file_out_;
	HuffTree* huff_tree_;
	std::unordered_map<char, int> stat_table_;
	std::unordered_map<std::string, std::string> code_table_;
    public:
	HuffmanArchiver(std::string file_in, std::string file_out);
	~HuffmanArchiver();

	void archivate();
	void unarchivate();
	void build_tree();

	// void load_code_table();
	void save_code_table(std::ofstream& fout);

	void calculate_statistic();
};

