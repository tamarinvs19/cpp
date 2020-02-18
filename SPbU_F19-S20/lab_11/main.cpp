#include "employees.cpp"
#include <iostream>

int main() {
    // Developer dev("Bob", 1000, true);
    // std::cout << dev;
    //
    // SalesManager sm("Alica", 100, 20, 300);
    // std::cout << sm;
    //
    // std::vector <Employee*> employees = {&dev};
    // EmployeesArray ea;
    // ea.add(&dev);
    // ea.add(&sm);
    //
    // std::cout << ea;

    EmployeesArray employees_array;
    std::string command;
    while (command != "exit") {
	std::cin >> command;
	if (command == "list") {
	    std::cout << employees_array;
	}
	else if (command == "add") {
	    int role;
	    std::cin >> role;
	    if (role == 1) {
		new Developer new_dev; 
		std::cin >> new_dev;
		employees_array.add(&new_dev);
		std::cout << employees_array;
	    }
	    else if (role == 2) {
		new SalesManager new_sm;
		std::cin >> new_sm;
		employees_array.add(&new_sm);
		std::cout << employees_array;
	    }
	}
    }
    return 0;
}
