#include <iostream>

#include "autotest.h"

namespace my_autotest {
AutoTest::AutoTest(): total_num(0), failed_num(0) {}

void AutoTest::show_final_results() {
    std::cout << "Total tests: " << total_num << ". Failed: " << failed_num << std::endl;
}

void AutoTest::check(bool expr, const char *func, const char *filename, int line_num) {
    if (!expr) {
	std::cout << "Test failed! Error in file " << filename << ", function " << func << ", line " << line_num << std::endl;
    }
}
}

