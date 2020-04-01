#ifndef _HUFFMAN_TEST_H_
#define _HUFFMAN_TEST_H_

#include "autotest.h"

namespace huffman_test {
class HuffmanTest : public my_autotest::AutoTest {
    public:
	HuffmanTest();
	void run_all_tests() override;
    private:
	//tests
};
}


#endif
