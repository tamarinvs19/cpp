#include "employees.h"
#include <cstring>
#include <sstream>
#include <iostream>


std::ostream& operator<<(std::ostream& os, Developer& developer) {
    std::stringstream ss;
    ss << "Developer\n" << 
	"Name: " << developer.getName() << "\n" <<
	"Base Salary: " << developer.getBaseSalary() << "\n"
	"Has bonus: " << (developer.getHasBonus() ? "+" : "-") << "\n";
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
	"Name: " << sales_manager.getName() << "\n" <<
	"Base Salary: " << sales_manager.getBaseSalary() << "\n"
	"Sold items: " << sales_manager.getSoldNm() << "\n"
	"Item price: " << sales_manager.getPrice() << "\n";
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
    Developer dev("Bob", 239, false);
    std::cout << dev;

    SalesManager sm("Alica", 150, 20, 200);
    std::cout << sm;
    return 0;
}
