#include "huffman.h"

TreeNode::TreeNode(int weight, std::string value, TreeNode* left_children, TreeNode* right_children) :
    weight_(weight), 
    value_(value),
    left_children_(left_children),
    right_children_(right_children)
    { code_ = ""; }

TreeNode::~TreeNode() {
    delete left_children_; delete right_children_;
}

int TreeNode::get_weight() {
    return weight_;
}

std::string TreeNode::get_value() {
    return value_;
}

std::string TreeNode::get_code() {
    return code_;
}

TreeNode* TreeNode::get_left_children() {
    return left_children_;
}

TreeNode* TreeNode::get_right_children() {
    return right_children_;
}

void TreeNode::gen_relative_code(std::string code = "") {
    code_ = code;
    if (left_children_ != 0 && right_children_ != 0) {
	left_children_->gen_relative_code("0" + code);
	right_children_->gen_relative_code("1" + code);
    }
}

HuffTree::HuffTree(std::vector<TreeNode*> nodes) :
    nodes_(nodes.begin(), nodes.end()) {}

HuffTree::~HuffTree() {
    if (nodes_.size() > 0)
	delete nodes_.top();
}

TreeNode* HuffTree::join_nodes(TreeNode* left_node, TreeNode* right_node) {
    int new_weight = left_node->get_weight() + right_node->get_weight();
    std::string new_value = left_node->get_value() + right_node->get_value();
    return new TreeNode(new_weight, new_value, left_node, right_node);
}

void HuffTree::build() {
    while (nodes_.size() > 1) {
	TreeNode* a = nodes_.top(); nodes_.pop();
	TreeNode* b = nodes_.top(); nodes_.pop();
	nodes_.push(join_nodes(a, b));
    }
    if (nodes_.size() == 1) {
	TreeNode* root = nodes_.top();
	root->gen_relative_code();
    }
}

std::string HuffTree::get_val_by_code(int code) {
    TreeNode* root = nodes_.top();
    while (root->get_weight() != 0) {
	if (code % 2 == 0)
	    root = root->get_left_children();
	else
	    root = root->get_right_children();
	code /= 2;
    }
    return root->get_value();
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
    int cnt = 0;
    while (!f.eof()) {
	f.get(symbol);
	stat_table_[symbol]++;
	cnt ++;
    }
    if (stat_table_['\n'] >= 2) 
	stat_table_['\n'] -= 2;
    if (stat_table_['\n'] == 0) 
	stat_table_.erase('\n');
    f.close();
}

void HuffmanArchiver::build_tree() {
    std::vector<TreeNode*> nodes;
    calculate_statistic();
    for (std::pair<char, int> p: stat_table_) {
	std::string s(1, p.first);
	TreeNode* new_node = new TreeNode(p.second, s);
	nodes.push_back(new_node);
    }
    if (nodes.size() > 0) {
	huff_tree_ = new HuffTree(nodes);
	huff_tree_->build();
    }
    for (TreeNode* node: nodes) 
	code_table_[node->get_value()] = node->get_code();
}

void write_to_file(std::ofstream& fout, int c) {
    for (std::size_t j=0; j<sizeof(c); ++j) {
	char chunk = (c >> (j * 8)) & 0xFF;
	fout.write(&chunk, sizeof(char));
    }
}

int read_to_int(std::ifstream& fin) {
    int res = 0;
    for (std::size_t j=0; j<sizeof(res); ++j) {
	int chunk = 0;
	fin.read((char*)& chunk, sizeof(char));
	res |= chunk << (j * 8);
    }
    return res;
}

void HuffmanArchiver::save_code_table(std::ofstream& fout) {
    
}

void HuffmanArchiver::archivate() {
    build_tree();
    char symbol;
    std::ifstream fin(file_in_);
    std::ofstream fout(file_out_, std::ios::binary);
    std::cout << code_table_.size() << std::endl;
    int c = 0, cnt = 0;
    int bytes = 0;
    while (!fin.eof()) {
	fin.get(symbol);
	std::string s(1, symbol);
	if (code_table_.find(s) != code_table_.end()) {
	    std::cout << code_table_[s] << " " << s << std::endl;
	for (auto i: code_table_[s]) {
	    cnt++;
	    c = c << 1 | (i == '1' ? 1: 0);
	    if (cnt % 32 == 0) {
		std::cout << c << std::endl;
		write_to_file(fout, c);
		c = 0; cnt = 0;
		bytes ++;
	    }
	}
	}
    }
    if (cnt != 0) { 
	write_to_file(fout, c);
		bytes ++;
    }
    std::cout << bytes << std::endl;
    fin.close();
    fout.close();
}

void HuffmanArchiver::unarchivate() {
    std::ifstream fin("test_t1", std::ios::binary);
    std::ofstream fout("out_t1");
    int c = 0;
    while (!fin.eof()) {
	c = read_to_int(fin);
	std::cout << c << std::endl;
	fout << huff_tree_->get_val_by_code(c);
    }
    fin.close();
    fout.close();
}

