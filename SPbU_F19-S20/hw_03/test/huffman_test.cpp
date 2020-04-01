#include <iostream>
#include "huffman_test.h"
#include "tree.h"

namespace huffman_test {

HuffmanTest::HuffmanTest() {}

void HuffmanTest::run_all_tests() {
    test_tree_node_constructor();
}

void test_tree_node_constructor() {
    huffman_tree::TreeNode n1;
    huffman_tree::TreeNode n2 = huffman_tree::TreeNode('a', 100);
    huffman_tree::TreeNode n3 = huffman_tree::TreeNode('a', 100, n1, n2);
    DO_CHECK(n1.value_ == ' ' && n1.weight_ == 0 && );
}
// void test_tree_node_destructor();
// void test_tree_node_compar_operator();
//
// void test_huff_tree_destructor();
// void test_huff_tree_build_1();
// void test_huff_tree_build_2();
// void test_huff_tree_build_3();
// void test_huff_tree_gen_relative_code_1();
// void test_huff_tree_gen_relative_code_2();
// void test_huff_tree_gen_relative_code_3();
// void test_huff_tree_get_root_1();
// void test_huff_tree_get_root_2();
// void test_huff_tree_get_root_3();
// void test_huff_tree_get_code_table_1();
// void test_huff_tree_get_code_table_2();
// void test_huff_tree_get_code_table_3();
//
// void test_arch_constructor();
// void test_arch_destructor();
// void test_arch_read_statistic_1();
// void test_arch_read_statistic_2();
// void test_arch_read_statistic_3();
// void test_arch_save_statistic_1();
// void test_arch_save_statistic_2();
// void test_arch_save_statistic_3();
// void test_arch_calc_statistic_1();
// void test_arch_calc_statistic_2();
// void test_arch_calc_statistic_3();
// void test_arch_archivate_1();
// void test_arch_archivate_2();
// void test_arch_archivate_3();
// void test_arch_unarchivate_1();
// void test_arch_unarchivate_2();
// void test_arch_unarchivate_3();
// void test_arch_get_info_1();
// void test_arch_get_info_2();
// void test_arch_get_info_3();
//
}
