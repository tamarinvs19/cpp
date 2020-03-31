#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <utility>
#include <string>
#include <tuple>

#include "tree.h"

class HuffmanArchiver {
    private:
	static const int DICT_SIZE = 256;

	std::ifstream file_in_;
	std::ofstream file_out_;
	std::vector<int> stat_table_;

	HuffTree* huff_tree_;

	void read_statistic();
	void save_statistic();
	void calculate_statistic();
    public:
	HuffmanArchiver(std::string file_in_name, std::string file_out_name);
	~HuffmanArchiver();

	void archivate();
	void unarchivate();
	std::tuple<int, int, int> get_info();
};

