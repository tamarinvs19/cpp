#include <iostream>
#include "autotest.cpp"
#include "huffman_test.cpp"

int main()
{
    huffman_test::HuffmanTest test;
    test.run_all_tests();
    test.show_final_results();
    return 0;
}
