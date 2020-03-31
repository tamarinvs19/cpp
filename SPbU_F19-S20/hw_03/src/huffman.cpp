#include "huffman.h"
#include <numeric>
#include <bitset>
#include <climits>


HuffmanArchiver::HuffmanArchiver(std::string file_in_name, std::string file_out_name) {
    file_in_ = std::ifstream(file_in_name, std::istream::binary);
    file_out_ = std::ofstream(file_out_name, std::ostream::binary);
    // if () {}
    stat_table_ = std::vector<int>(HuffmanArchiver::DICT_SIZE, 0); 
    huff_tree_ = new HuffTree();
}

HuffmanArchiver::~HuffmanArchiver() {
    delete huff_tree_;
    file_in_.close();
    file_out_.close();
}

void HuffmanArchiver::calculate_statistic() {
    file_in_.seekg(0);
    unsigned char symbol;
    while (!file_in_.eof()) {
	file_in_.read((char*)&symbol, sizeof(char));
	// add throw
	stat_table_[(int)symbol]++;
    }
}

void HuffmanArchiver::save_statistic() {
    for (int c: stat_table_) {
	file_out_ << c << "\n";
    }
}

void HuffmanArchiver::read_statistic() {
    for (size_t i = 0; i < 256; ++i) { // out 256
	file_in_ >> stat_table_[i];
    }
}

void HuffmanArchiver::archivate() {
    calculate_statistic();
    huff_tree_->build(stat_table_);
    huff_tree_->gen_relative_code(huff_tree_->get_root());
    std::unordered_map< char, std::string > code_table = *huff_tree_->get_code_table();
    save_statistic();
    file_in_.clear();
    file_in_.seekg(0);

    unsigned char symbol, c;
    unsigned int cnt = 0;
    while (!file_in_.eof()) {
	symbol = file_in_.get();
	for (char i: code_table[symbol]) {
	    c = c | (i == '1' ? 1: 0) << (CHAR_BIT - 1 - cnt);
	    cnt++;
	    if (cnt == CHAR_BIT) {
		file_out_.write((char*)&c, sizeof(char));
		// throw 
		c = 0; cnt = 0;
	    }
	}
    }
    if (cnt != 0) 
	file_out_ << c;
}

void HuffmanArchiver::unarchivate() {
    read_statistic();
    huff_tree_->build(stat_table_);
    huff_tree_->gen_relative_code(huff_tree_->get_root());
    TreeNode* node = huff_tree_->get_root();

    int count_symbols = std::accumulate(stat_table_.begin(), stat_table_.end(), 1);
    int cnt = 0;
    char symbol;
    symbol = file_in_.get(); symbol = file_in_.get();
    while (!file_in_.eof() && count_symbols > 2) {
	if (symbol & (1 << (CHAR_BIT - 1 - cnt)))
	    node = node->right_children_;
	else
	    node = node->left_children_;

	if (node->left_children_ == nullptr || node->right_children_ == nullptr) {
	    file_out_ << node->value_;
	    node = huff_tree_->get_root();
	    count_symbols--;
	}

	cnt++;
	if (cnt == CHAR_BIT) {
	    cnt = 0;
	    symbol = file_in_.get();
	}
    }
}

std::tuple<int, int, int> HuffmanArchiver::get_info() {
    file_in_.clear();
    file_in_.seekg(0, std::ifstream::end);
    file_out_.clear();
    file_out_.seekp(0, std::iostream::end);
    return std::make_tuple(file_in_.tellg(), file_out_.tellp(), DICT_SIZE * (sizeof(int) + sizeof(char)));
}

