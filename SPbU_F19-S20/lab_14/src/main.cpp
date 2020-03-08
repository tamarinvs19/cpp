#include <iostream>
#include "matrix.h"

void interface() {
    std::vector<matrix::Matrix> regs(10, matrix::Matrix());
    std::string command = "";
    size_t num, num2, nr, nc;
    char dollar;
    while (command != "exit") {
	std::cin >> command;
	if (command == "load") {
	    std::string file_name;
	    std::cin >> dollar >> num >> file_name;
	    regs[num].load(file_name);
	}
	if (command == "print") {
	    std::cin >> dollar >> num;
	    std::cout << regs[num];
	}
	if (command == "add") {
	    std::cin >> dollar >> num >> dollar >> num2;
	    regs[num].add(regs[num2]);
	}
	if (command == "mul") {
	    std::cin >> dollar >> num >> dollar >> num2;
	    regs[num].mul(regs[num2]);
	}
	if (command == "elem") {
	    std::cin >> dollar >> num >> nr >> nc;
	    std::cout << regs[num].elem(nr, nc) << std::endl;
	}
    }
}

int main()
{
    interface();
    return 0;
}
