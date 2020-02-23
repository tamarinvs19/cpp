#include "../include/employees.h"
#include "../include/bin_manip.h"
#include <cstring>
#include <fstream>
#include <iostream>

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
    char *name = (char *)std::malloc(sizeof(char) * (developer.MAX_LEN + 1));
    is >> read_c_str(name, sizeof(name)) >> read_le_int32(developer._base_salary) >> read_bool(developer._has_bonus);
    std::string sname(name);
    developer._name = sname;
    delete [] name;
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
    char *name = (char *)std::malloc(sizeof(char) * (sales_manager.MAX_LEN + 1));
    is >> read_c_str(name, sizeof(name)) >> read_le_int32(sales_manager._base_salary) >> read_le_int32(sales_manager._sold_nm) >> read_le_int32(sales_manager._price);
    std::string sname(name);
    sales_manager._name = sname;
    delete [] name;
    return is;
}

std::ostream& operator<<(std::ostream& os, EmployeesArray& employees_array) {
    std::vector <Employee*> emps = employees_array.get_employees();
    for (int32_t i=0; i<(int32_t)emps.size(); i++) {
	os << i + 1 << ". " << emps[i]->get_info();
    }
    os << "== Total salary: " << employees_array.total_salary() << "\n\n";
    return os;
}
std::ofstream& operator<<(std::ofstream& os, EmployeesArray& employees_array) {
    std::vector <Employee*> emps = employees_array.get_employees();
    os << write_le_int32(emps.size());
    for (int32_t i=0; i<(int32_t)emps.size(); i++) {
	emps[i]->get_bin_info(os);
    }
    return os;
}
std::ifstream& operator>>(std::ifstream& is, EmployeesArray& employees_array) {
    int32_t cnt;
    is >> read_le_int32(cnt);
    for (int i=0; i<cnt; i++) {
	int32_t role;
	is >> read_le_int32(role);
	if (role == 1) {
	    Developer* new_dev = new Developer; 
	    is >> *new_dev;
	    employees_array.add(new_dev);
	}
	else if (role == 2) {
	    SalesManager* new_sm = new SalesManager;
	    is >> *new_sm;
	    employees_array.add(new_sm);
	}
    }
    return is;
}

