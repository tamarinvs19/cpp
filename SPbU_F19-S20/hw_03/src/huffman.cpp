#include "huffman.h"

TreeNode::TreeNode(int weight, std::string value, TreeNode* left_children, TreeNode* right_children) :
    weight_(weight), 
    value_(value),
    left_children_(left_children),
    right_children_(right_children)
    { code_ = ""; std::cout << left_children_ << "\n" << right_children_ << std::endl;}

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

void TreeNode::gen_relative_code(std::string code = "") {
    code_ = code;
    this->get_childrens();
    if (left_children_ != 0 && right_children_ != 0) {
	left_children_->gen_relative_code(code + "0");
	right_children_->gen_relative_code(code + "1");
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
	TreeNode a = nodes_.top(); nodes_.pop();
	TreeNode b = nodes_.top(); nodes_.pop();
	std::cout << a.get_value() << " + " << b.get_value() << std::endl;
	nodes_.push(join_nodes(a, b));
    }
    if (nodes_.size() == 1) {
	TreeNode root(nodes_.top());
	// root.gen_relative_code();
    }
}


HuffmanArchiver::HuffmanArchiver(std::string file_in, std::string file_out) :
    file_in_(file_in), file_out_(file_out) {
    }

HuffmanArchiver::~HuffmanArchiver() { 
    delete huff_tree_;
}

void HuffmanArchiver::calculate_statistic() {
    char symbol;
    std::ifstream f(file_in_);
    while (!f.eof()) {
	f.get(symbol);
	stat_table_[symbol]++;
    }
    if (stat_table_['\n'] >= 2) 
	stat_table_['\n'] -= 2;
    if (stat_table_['\n'] == 0) 
	stat_table_.erase('\n');
    f.close();
}

void HuffmanArchiver::build_tree() {
    std::vector<TreeNode> nodes;
    calculate_statistic();
    for (std::pair<char, int> p: stat_table_) {
	std::string s(1, p.first);
	nodes.push_back(TreeNode(p.second, s));
    }
    if (nodes.size() > 0) {
	huff_tree_ = new HuffTree(nodes);
	huff_tree_->build();
    }
}

void HuffmanArchiver::generate_code_table() {
    build_tree();
}
