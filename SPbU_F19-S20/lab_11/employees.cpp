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
    std::stringstream ss;
    char *name;
    char c;
    int32_t base_salary = 0;
    is.get(c);
    while (c == ' ') {is.get(c);}
    while (c != ' ') {
	ss << c;
	is.get(c);
    }
    std::string s = ss.str();
    name = new char[s.length() + 1];
    strcpy(name, s.c_str());
    employee._name = name;

    while (c == ' ') {is.get(c);}
    while (c != '\n') {
	base_salary = (base_salary * 10) + (int)c - (int)'0';
	is.get(c);
    }
    employee._base_salary = base_salary;
    return is;
}

std::ostream& operator<<(std::ostream& os, Developer& developer) {
    std::string res_str = developer.get_info();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator>>(std::istream& is, Developer& developer) {
    std::stringstream ss;
    char *name;
    char c;
    int32_t base_salary = 0;
    is.get(c);
    while (c == ' ') {is.get(c);}
    while (c != ' ') {
	ss << c;
	is.get(c);
    }
    std::string s = ss.str();
    name = new char[s.length() + 1];
    strcpy(name, s.c_str());
    developer._name = name;

    while (c == ' ') {is.get(c);}
    while (c != ' ') {
	base_salary = (base_salary * 10) + (int)c - (int)'0';
	is.get(c);
    }
    developer._base_salary = base_salary;
    while (c == ' ') {is.get(c);}
    developer._has_bonus = (c == '1' ? true : false);
    return is;
}

std::ostream& operator<<(std::ostream& os, SalesManager& sales_manager) {
    std::stringstream ss;
    std::string res_str = sales_manager.get_info();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator>>(std::istream& is, SalesManager& sales_manager) {
    std::stringstream ss;
    char *name;
    char c;
    int32_t base_salary = 0, sold_nm = 0, price = 0;
    is.get(c);
    while (c == ' ') {is.get(c);}
    while (c != ' ') {
	ss << c;
	is.get(c);
    }
    std::string s = ss.str();
    name = new char[s.length() + 1];
    strcpy(name, s.c_str());
    sales_manager._name = name;

    while (c == ' ') {is.get(c);}
    while (c != ' ') {
	base_salary = (base_salary * 10) + (int)c - (int)'0';
	is.get(c);
    }
    sales_manager._base_salary = base_salary;
    while (c == ' ') {is.get(c);}
    while (c != ' ') {
	sold_nm = (sold_nm * 10) + (int)c - (int)'0';
	is.get(c);
    }
    sales_manager._sold_nm = sold_nm;
    while (c == ' ') {is.get(c);}
    while (c != '\n') {
	price = (price * 10) + (int)c - (int)'0';
	is.get(c);
    }
    sales_manager._price = price;

    return is;
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

