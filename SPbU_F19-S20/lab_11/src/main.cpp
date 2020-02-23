#include "../include/employees.h"
#include <fstream>
#include <iostream>

int main() {
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
	    Employee* employee = (Employee *)malloc(sizeof(Employee));
	    if (role == 1) {
		employee = new Developer;
	    }
	    if (role == 2) {
		employee = new SalesManager;
	    }
	    std::cin >> *employee;
	    employees_array.add(employee);
	}
	else if (command == "save") {
	    std::string file_name;
	    std::cin >> file_name;
	    std::ofstream f(file_name, std::ios::binary);
	    f << employees_array;
	    f.close();
	}
	else if (command == "load") {
	    std::string file_name;
	    std::cin >> file_name;
	    std::ifstream f(file_name, std::ios::binary);
	    f >> employees_array;
	    f.close();
	}
    }
    return 0;
}
