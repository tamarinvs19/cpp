#include "employees.cpp"
#include <iostream>

int main() {
    EmployeesArray employees_array;
    Developer dev("Bob", 1000, true);
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
		Developer* new_dev = new Developer; 
		std::cin >> *new_dev;
		employees_array.add(new_dev);
	    }
	    else if (role == 2) {
		SalesManager* new_sm = new SalesManager;
		std::cin >> *new_sm;
		employees_array.add(new_sm);
	    }
	}
	else if (command == "save") {
	    std::string file_name;
	    std::cin >> file_name;
	    std::ofstream f(file_name, std::ios::binary);
	    f << write_le_int32(employees_array.get_count_emplyees());
	    f << employees_array;
	    f.close();
	}
	else if (command == "load") {
	    std::string file_name;
	    std::cin >> file_name;
	    std::ifstream f(file_name, std::ios::binary);
	    int32_t c;
	    f >> read_le_int32(c);
	    std::cout << c;
	    for (int32_t i=0; i<c; i++) {
		int32_t role;
		f >> read_le_int32(role);
		std::cout << role;
		if (role == 1) {
		    Developer* new_dev = new Developer; 
		    f >> *new_dev;
		    employees_array.add(new_dev);
		}
		else if (role == 2) {
		    SalesManager* new_sm = new SalesManager;
		    f >> *new_sm;
		    employees_array.add(new_sm);
		}
	    }
	    f.close();
	}
    }
    return 0;
}
