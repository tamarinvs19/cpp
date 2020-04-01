#ifndef _AUTOTEST_H_
#define _AUTOTEST_H_

// #define DO_CHECK(EXPR) my_autotest::AutoTest::check(EXPR, __FUNC__, __FILE__, __LINE__);

namespace my_autotest {
class AutoTest {
    public:
	AutoTest();
	virtual void run_all_tests()=0;
	void show_final_results();
    protected:
	int failed_num;
	int total_num;

	void check(bool expr, const char *func, const char *filename, int line_num);
};
}


#endif
