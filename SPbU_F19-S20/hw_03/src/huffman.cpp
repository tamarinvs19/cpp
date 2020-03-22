#include "huffman.h"
#include <bitset>
#include <climits>

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

void TreeNode::set_left_children() {
    left_children_ = new TreeNode();
}

void TreeNode::set_right_children() {
    right_children_ = new TreeNode();
}

void TreeNode::set_value(std::string val) {
    this->value_ = val;
}
void TreeNode::gen_relative_code(std::string code = "") {
    code_ = code;
    if (left_children_ != 0 && right_children_ != 0) {
	left_children_->gen_relative_code(code + "0");
	right_children_->gen_relative_code(code + "1");
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

TreeNode* HuffTree::get_root() {
    return nodes_.top();
}

void HuffTree::add_node_by_code(std::string c, std::string code) {
    TreeNode* root = this->get_root();
    for (size_t i = 0; i < code.length(); ++i) {
	if (code[i] == 0) {
	    if (root->get_left_children() == 0) 
		root->set_left_children();
	    root = root->get_left_children();
	}
	else {
	    if (root->get_right_children() == 0) 
		root->set_right_children();
	    root = root->get_right_children();
	}
    }
    root->set_value(c);
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

void write_to_file_int(std::ofstream& fout, int32_t c) {
    for (std::size_t j=sizeof(c); j>0; --j) {
	char chunk = (c >> ((int)(j-1) * CHAR_BIT)) & 0xFF;
	fout.write(&chunk, sizeof(char));
    }
}

int32_t read_from_file_int(std::ifstream& fin) {
    int32_t res = 0;
    for (std::size_t j=sizeof(res); j>0; --j) {
	int32_t chunk = 0;
	fin.read((char *)&chunk, sizeof(res));
	res |= chunk << (j * CHAR_BIT);
    }
    return res;
}

int32_t bin_str_to_int(std::string s) {
    int32_t res = 0;
    for (size_t i=0; i<s.length(); i++)
	res = (res << 1) | (s[i] == '1' ? 1 : 0);
    return res;
}

void HuffmanArchiver::save_code_table(std::ofstream& fout) {
    // write_to_file_int(fout, code_table_.size());
    fout << code_table_.size() << std::endl;
    for (auto p: code_table_) {
	fout << p.first << p.second << "\n";
    }
}

void HuffmanArchiver::load_code_table(std::ifstream& fin) {
    int size;
    char c;
    std::string s, val;
    fin >> size;
    for (int i=0; i<size; ++i) {
	fin.get(c);
	fin.get(c);
	fin >> s;
	val = c;
	huff_tree_->add_node_by_code(val, s);
    }
}

void HuffmanArchiver::archivate() {
    build_tree();
    char symbol;
    std::ifstream fin(file_in_);
    std::ofstream fout(file_out_, std::ios::binary);
    this->save_code_table(fout);
    int32_t c = 0, cnt = 0;
    while (!fin.eof()) {
	fin.get(symbol);
	std::string s(1, symbol);
	if (code_table_.find(s) != code_table_.end()) {
	    for (auto i: code_table_[s]) {
		cnt++;
		c = c << 1 | (i == '1' ? 1: 0);
		if (cnt == 32) {
		    write_to_file_int(fout, c);
		    c = 0; cnt = 0;
		}
	    }
	}
    }
    if (cnt != 0) {
	c <<= (32 - cnt);
	write_to_file_int(fout, c);
    }
    fin.close();
    fout.close();
}

void HuffmanArchiver::unarchivate() {
    std::ifstream fin(file_in_, std::ios::binary);
    std::ofstream fout(file_out_);
    char symbol;
    TreeNode* main_root = new TreeNode(1, "root");
    std::vector<TreeNode*> nodes = { main_root };
    huff_tree_ = new HuffTree(nodes);
    this->load_code_table(fin);
    TreeNode* node = main_root;

	symbol = fin.get();
    while (!fin.eof()) {
	symbol = fin.get();
	for (int i=7; i>=0; --i) {
	    if (node->get_value().length() == 1) {
		fout << node->get_value();
		node = main_root;
	    }
	    if (symbol & 1 << i)
		node = node->get_right_children();
	    else
		node = node->get_left_children();
	}
    }
    fin.close();
    fout.close();
}

