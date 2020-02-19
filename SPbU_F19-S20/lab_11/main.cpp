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
	    int32_t n = 100;
	    f << write_c_str(dev.get_name());
	    f.close();
	    std::ifstream f_in(file_name, std::ios::binary); // отрываем файл в бинарном формате
	    // Developer old;
	    std::string old;
	    f_in >> read_c_str(old, sizeof(old));
	    std::cout << old;
	}
    }
    return 0;
}
