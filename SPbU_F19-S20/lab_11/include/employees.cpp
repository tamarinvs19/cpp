#include "employees.h"
#include <cstring>
#include <sstream>
#include <iostream>


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

int main() {
    Developer dev("Bob", 1000, true);
    std::cout << dev;

    SalesManager sm("Alica", 100, 20, 300);
    std::cout << sm;

    std::vector <Employee*> employees = {&dev};
    EmployeesArray ea;
    ea.add(&dev);
    ea.add(&sm);

    std::cout << ea;

    return 0;
}
