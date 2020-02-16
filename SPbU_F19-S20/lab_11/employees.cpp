#include "include/employees.h"
#include <cstring>
#include <cassert>
#include <climits>
#include <sstream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    std::string res_str = employee.get_info();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator>>(std::istream& is, Employee& employee) {
    std::cout << "123";

    char *name;
    char c = is.get();
    int i=0;
    int32_t base_salary;
    while (c == ' ') {c = is.get();}
    while (c != ' ') {
	name[i] = c;
	c = is.get();
	i ++;
    }
	std::cout << name << "\n";
	employee._name = name;
    // employee._name = name;
    // employee._base_salary = base_salary;
    // return is;

    // employee.data = 0;
    // for (std::size_t i = 0; i < sizeof(d.data); ++i) {
    // int32_t chunk = 0;
    // is.read((char *)&chunk, sizeof(char));
    // d.data |= chunk << (i * CHAR_BIT);
    // }
    // return is;
}

std::ostream& operator<<(std::ostream& os, Developer& developer) {
    std::string res_str = developer.get_info();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator>>(std::istream& is, const Developer& developer) {
}

std::ostream& operator<<(std::ostream& os, SalesManager& sales_manager) {
    std::stringstream ss;
    std::string res_str = sales_manager.get_info();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator>>(std::istream& is, const SalesManager& sales_manager) {
}

std::ostream& operator<<(std::ostream& os, EmployeesArray& employees_array) {
    std::stringstream ss;
    std::vector <Employee*> emps = employees_array.get_employees();
    for (int i=1; i<=(emps.size()); i++) {
	ss << i << ". " << emps[i-1]->get_info();
    }
    ss << "== Total salary: " << employees_array.total_salary() << "\n\n";
    std::string res_str = ss.str();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator<<(std::istream& is, const EmployeesArray& employees_array) {
}

