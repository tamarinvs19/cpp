#include "employees.h"
#include <cstring>
#include <sstream>
#include <iostream>


std::ostream& operator<<(std::ostream& os, Developer& developer) {
    std::stringstream ss;
    ss << "Developer\n" << 
	"Name: " << developer.get_name() << "\n" <<
	"Base Salary: " << developer.get_base_salary() << "\n"
	"Has bonus: " << (developer.get_has_bonus() ? "+" : "-") << "\n";
    std::string res_str = ss.str();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator>>(std::istream& is, const Developer& developer) {
}

std::ostream& operator<<(std::ostream& os, SalesManager& sales_manager) {
    std::stringstream ss;
    ss << "Sales Manager\n" << 
	"Name: " << sales_manager.get_name() << "\n" <<
	"Base Salary: " << sales_manager.get_base_salary() << "\n"
	"Sold items: " << sales_manager.get_sold_nm() << "\n"
	"Item price: " << sales_manager.get_price() << "\n";
    std::string res_str = ss.str();
    const char * res = res_str.c_str();
    os.write(res, std::strlen(res)+1);
    return os;
}

std::istream& operator<<(std::istream& is, const SalesManager& sales_manager) {
}

std::ostream& operator>>(std::ostream& os, const EmployeesArray& employees_array) {
}

std::istream& operator<<(std::istream& is, const EmployeesArray& employees_array) {
}

int main() {
    Developer dev("Bob", 1000, true);
    std::cout << dev;

    SalesManager sm("Alica", 100, 20, 300);
    std::cout << sm;

    std::vector <Employee*> employees = {&dev};
    EmployeesArray ea(employees);
    ea.add(&dev);
    ea.add(&sm);
    std::cout << ea.total_salary();

    return 0;
}
