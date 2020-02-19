#include "include/employees.h"
#include "bin_manip.cpp"
#include <cstring>
#include <fstream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, Employee& employee) {
    os << employee.get_info();
    return os;
}

// std::ofstream& operator<<(std::ofstream& os, Employee& employee) {
//     os << employee.get_name() << employee.get_base_salary();
//     return os;
// }

std::istream& operator>>(std::istream& is, Employee& employee) {
    is >> employee._name >> employee._base_salary;
    return is;
}

// std::ifstream& operator>>(std::ifstream& is, Employee& employee) {
//     is >> employee._name >> employee._base_salary;
//     return is;
// }

std::ostream& operator<<(std::ostream& os, Developer& developer) {
    os << developer.get_info();
    return os;
}

// std::ofstream& operator<<(std::ofstream& os, Developer& developer) {
//     os << 1 << developer._name << developer._base_salary << developer._has_bonus << '\0';
//     return os;
// }

std::istream& operator>>(std::istream& is, Developer& developer) {
    is >> developer._name >> developer._base_salary >> developer._has_bonus;
    return is;
}

// std::ifstream& operator>>(std::ifstream& is, Developer& developer) {
//     is >> developer._name >> developer._base_salary >> developer._has_bonus;
//     return is;
// }

std::ostream& operator<<(std::ostream& os, SalesManager& sales_manager) {
    os << sales_manager.get_info();
    return os;
}

std::istream& operator>>(std::istream& is, SalesManager& sales_manager) {
    is >> sales_manager._name >> sales_manager._base_salary >> sales_manager._sold_nm >> sales_manager._price;
    return is;
}

std::ostream& operator<<(std::ostream& os, EmployeesArray& employees_array) {
    std::vector <Employee*> emps = employees_array.get_employees();
    for (int i=0; i<emps.size(); i++) {
	os << i + 1 << ". " << emps[i]->get_info();
    }
    os << "== Total salary: " << employees_array.total_salary() << "\n\n";
    return os;
}

