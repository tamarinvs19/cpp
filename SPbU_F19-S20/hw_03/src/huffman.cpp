#include "huffman.h"

TreeNode::TreeNode(int weight, std::string value, TreeNode* left_children, TreeNode* right_children) :
    weight_(weight), 
    value_(value),
    left_children_(left_children),
    right_children_(right_children)
    { code_ = 0; }

TreeNode::~TreeNode() {}

int TreeNode::get_weight() {
    return weight_;
}

std::string TreeNode::get_value() {
    return value_;
}

std::string TreeNode::get_code() {
    return code_;
}

void gen_relative_code(std::string code) {
    code_ = code;
    if (left_children != 0) {
	left_children->gen_relative_code(code + "0");
	right_children->gen_relative_code(code + "1");
    }
}

HuffTree::HuffTree(std::vector<TreeNode> nodes) :
    nodes_(nodes.begin(), nodes.end()) {}

HuffTree::~HuffTree() {}

TreeNode HuffTree::join_nodes(TreeNode left_node, TreeNode right_node) {
    int new_weight = left_node.get_weight() + right_node.get_weight();
    std::string new_value = left_node.get_value() + right_node.get_value();
    return TreeNode(new_weight, new_value, &left_node, &right_node);
}

void HuffTree::build() {
    while (nodes_.size() > 1) {
	TreeNode a = TreeNode(nodes_.top()); nodes_.pop();
	TreeNode b = TreeNode(nodes_.top()); nodes_.pop();
	nodes_.push(join_nodes(a, b));
    }
}


HuffmanArchiver::HuffmanArchiver(std::string file_in, std::string file_out) :
    file_in_(file_in), file_out_(file_out) {}

HuffmanArchiver::~HuffmanArchiver() {}


std::unordered_map<char, int>& calculate_statistic() {
    std::ofstream f(file_in);

}
std::unordered_map<char, std::string>& generate_code_table() {
    std::unordered_map<char, std::string> table;
    return &table;
}
