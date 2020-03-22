#include <exception>

class MyExceptions: public std::logic_error {
    public:
	MyExceptions(std::string s) : std::logic_error(s) {}
};

