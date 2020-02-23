#ifndef LAB11_EMPLOYEES_H_INCLUDED
#define LAB11_EMPLOYEES_H_INCLUDED

#include "bin_manip.h"
#include <stdint.h>
#include <ostream>
#include <istream>
#include <sstream>
#include <cstring>
#include <vector>
#include <iostream>

class Employee {
    public:
	virtual int get_base_salary() const {
	    return _base_salary;
	};
	virtual std::string get_name() const {
	    return _name;
	};
	virtual int salary() const {
	    return get_base_salary();
	};
	virtual std::string get_info() const {
	    std::stringstream ss;
	    ss << "Name: " << get_name() << "\n" <<
		"Base Salary: " << get_base_salary() << "\n";
	    std::string res_str = ss.str();
	    return res_str;
	};
	virtual std::ofstream& get_bin_info(std::ofstream& os)  {};
	friend std::ostream& operator<<(std::ostream&, Employee&);
	friend std::istream& operator>>(std::istream&, Employee&);
	friend std::ofstream& operator>>(std::ofstream&, Employee&);
	friend std::ifstream& operator>>(std::ifstream&, Employee&);
    protected:
	std::string _name;
	int32_t _base_salary;
};
class Developer: public Employee {
    public:
	int salary() const {
	    int salary = _base_salary;
	    if (_has_bonus) { salary += 1000; }
	    return salary;
	}
	bool get_has_bonus() const {
	    return _has_bonus;
	};
	std::string get_info() const {
	    std::stringstream ss;
	    ss << "Developer\n" <<
		"Name: " << get_name() << "\n" <<
		"Base Salary: " << get_base_salary() << "\n"
		"Has bonus: " << (get_has_bonus() ? "+" : "-") << "\n";
	    std::string res_str = ss.str();
	    return res_str;
	};
	std::ofstream& get_bin_info(std::ofstream& os) {
	    char * name = new char[_name.size() + 1];
	    std::copy(_name.begin(), _name.end(), name);
	    name[_name.size()] = '\0';
	    os << write_le_int32(1) <<
		write_c_str(name) <<
		write_le_int32(_base_salary) <<
		write_bool(_has_bonus);
	    return os;
	};
	std::ifstream& set_bin_info(std::ifstream& is) {
	    char * name;
	    int32_t t = 1;
	    is >> read_le_int32(t) >>
		read_c_str(name, std::strlen(name)) >>
		read_le_int32(_base_salary) >>
		read_bool(_has_bonus);
	    std::string sname(name);
	    _name = sname;
	    return is;
	};

	friend std::ostream& operator<<(std::ostream&, Developer&);
	friend std::istream& operator>>(std::istream&, Developer&);
	friend std::ofstream& operator<<(std::ofstream&, Developer&);
	friend std::ifstream& operator>>(std::ifstream&, Developer&);
	Developer (std::string name, int32_t base_salary, bool has_bonus) {
	    _name = name;
	    _base_salary = base_salary;
	    _has_bonus = has_bonus;
	}
	Developer () {}
    private:
	bool _has_bonus;
};

class SalesManager: public Employee {
    public:
	int salary() const {
	    return _base_salary + _sold_nm * _price * 0.01;
	}
	int get_sold_nm() const {
	    return _sold_nm;
	}
	int get_price() const {
	    return _price;
	}
	void sold_nm(int32_t sold_nm) { _sold_nm = sold_nm; }
	void price(int32_t price) { _price = price; }
	std::string get_info() const {
	    std::stringstream ss;
	    ss << "Sales Manager\n" <<
		"Name: " << get_name() << "\n" <<
		"Base Salary: " << get_base_salary() << "\n"
		"Sold items: " << get_sold_nm() << "\n"
		"Item price: " << get_price() << "\n";
	    std::string res_str = ss.str();
	    return res_str;
	};
	std::ofstream& get_bin_info(std::ofstream& os) {
	    char * name = new char[_name.size() + 1];
	    std::copy(_name.begin(), _name.end(), name);
	    name[_name.size()] = '\0';
	    os << write_le_int32(2) <<
		write_c_str(name) <<
		write_le_int32(_base_salary) <<
		write_le_int32(_sold_nm) <<
		write_le_int32(_price);
	    return os;
	};
	std::ifstream& set_bin_info(std::ifstream& is) {
	    char * name;
	    int32_t t = 2;
	    is >> read_le_int32(t) >>
		read_c_str(name, std::strlen(name)) >>
		read_le_int32(_base_salary) >>
		read_le_int32(_sold_nm) >>
		read_le_int32(_price);
	    std::string sname(name);
	    _name = sname;
	    return is;
	};

	friend std::ostream& operator<<(std::ostream&, SalesManager&);
	friend std::istream& operator>>(std::istream&, SalesManager&);
	friend std::ofstream& operator<<(std::ofstream&, SalesManager&);
	friend std::ifstream& operator>>(std::ifstream&, SalesManager&);
	SalesManager (std::string name, int32_t base_salary, int32_t sold_nm, int32_t price) {
	    _name = name;
	    _base_salary = base_salary;
	    _sold_nm = sold_nm;
	    _price = price;
	}
	SalesManager () {}
    private:
	int32_t _sold_nm, _price;
};

class EmployeesArray {
    public:
	void add(Employee* e) {
	    _employees.push_back(e);
	}
	std::vector <Employee*> get_employees() {
	    return _employees;
	}
	int get_count_emplyees() {
	    return _employees.size();
	}
	int total_salary() const {
	    int32_t total_salary = 0;
	    for (Employee* e: _employees) {
		total_salary += e->salary();
	    }
	    return total_salary;
	}
	friend std::ostream& operator<<(std::ostream&, EmployeesArray&);
	friend std::ofstream& operator<<(std::ofstream&, EmployeesArray&);
	friend std::ifstream& operator>>(std::ifstream&, EmployeesArray&);
	EmployeesArray (std::vector<Employee*> employees) {
	    for (Employee* e: employees) {
		add(e);
	    }
	}
	EmployeesArray () {}
    private:
	std::vector <Employee*> _employees;
	// Employee **_employees;
};

#endif
