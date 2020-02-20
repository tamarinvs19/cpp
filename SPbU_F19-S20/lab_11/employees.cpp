#include "include/employees.h"
#include "bin_manip.cpp"
#include <cstring>
#include <fstream>
#include <iostream>

// std::ostream& operator<<(std::ostream& os, Employee& employee) {
//     os << employee.get_info();
//     return os;
// }
//
// std::ofstream& operator<<(std::ofstream& os, Employee& employee) {
//     os << employee.get_bin_info();
//     return os;
// }
//
// std::istream& operator>>(std::istream& is, Employee& employee) {
//     is >> employee._name >> employee._base_salary;
//     return is;
// }
//
// std::ifstream& operator>>(std::ifstream& is, Employee& employee) {
//     char * name;
//     is >> read_c_str(name, std::strlen(name)) >> read_le_int32(employee._base_salary);
//     std::string sname(name);
//     employee._name = sname;
//     return is;
// }
//
std::ostream& operator<<(std::ostream& os, Developer& developer) {
    os << developer.get_info();
    return os;
}

std::ofstream& operator<<(std::ofstream& os, Developer& developer) {
    char * name = new char[developer._name.size() + 1];
    std::copy(developer._name.begin(), developer._name.end(), name);
    name[developer._name.size()] = '\0';
    os << write_c_str(name) << write_le_int32(developer._base_salary) << write_bool(developer._has_bonus);
    delete [] name;
    return os;
}

std::istream& operator>>(std::istream& is, Developer& developer) {
    is >> developer._name >> developer._base_salary >> developer._has_bonus;
    return is;
}

std::ifstream& operator>>(std::ifstream& is, Developer& developer) {
    char * name;
    is >> read_c_str(name, std::strlen(name)) >> read_le_int32(developer._base_salary) >> read_bool(developer._has_bonus);
    std::string sname(name);
    developer._name = sname;
    return is;
}

std::ostream& operator<<(std::ostream& os, SalesManager& sales_manager) {
    os << sales_manager.get_info();
    return os;
}
std::ofstream& operator<<(std::ofstream& os, SalesManager& sales_manager) {
    char * name = new char[sales_manager._name.size() + 1];
    std::copy(sales_manager._name.begin(), sales_manager._name.end(), name);
    name[sales_manager._name.size()] = '\0';
    os << write_le_int32(2) << write_c_str(name) << write_le_int32(sales_manager._base_salary) << write_le_int32(sales_manager._sold_nm) << write_le_int32(sales_manager._price);
    delete [] name;
    return os;
}

std::istream& operator>>(std::istream& is, SalesManager& sales_manager) {
    is >> sales_manager._name >> sales_manager._base_salary >> sales_manager._sold_nm >> sales_manager._price;
    return is;
}

std::ifstream& operator>>(std::ifstream& is, SalesManager& sales_manager) {
    char * name;
    is >> read_c_str(name, std::strlen(name)) >> read_le_int32(sales_manager._base_salary) >> read_le_int32(sales_manager._sold_nm) >> read_le_int32(sales_manager._price);
    std::string sname(name);
    sales_manager._name = sname;
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
std::ofstream& operator<<(std::ofstream& os, EmployeesArray& employees_array) {
    std::vector <Employee*> emps = employees_array.get_employees();
    for (int i=0; i<emps.size(); i++) {
	std::cout << emps[i]->get_info();
	emps[i]->get_bin_info(os);
    }
    return os;
}

