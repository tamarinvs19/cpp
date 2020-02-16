#ifndef LAB11_EMPLOYEES_H_INCLUDED
#define LAB11_EMPLOYEES_H_INCLUDED

#include <stdint.h>
#include <ostream>
#include <istream>
#include <iostream>
#include <vector>

class Employee {
    public:
	virtual int get_base_salary() const {
	    return _base_salary;
	};
	virtual char * get_name() const {
	    return _name;
	};
	virtual int salary() const {
	    return get_base_salary();
	};
	friend std::ostream& operator<<(std::ostream&, const Employee&);
	friend std::istream& operator>>(std::istream&, const Employee&);
    protected:
	char *_name;
	int32_t _base_salary;
};
class Developer: public Employee {
    public:
	int salary() const {
	    int salary = _base_salary;
	    if (_has_bonus) { salary += 1000; }
	    return salary;
	}
	bool get_has_bonus() {
	    return _has_bonus;
	};
	friend std::ostream& operator<<(std::ostream&, const Developer&);
	friend std::istream& operator>>(std::istream&, const Developer&);
	Developer (char *name, int32_t base_salary, bool has_bonus) {
	    _name = name;
	    _base_salary = base_salary;
	    _has_bonus = has_bonus;
	}
    private:
	bool _has_bonus;
};

class SalesManager: public Employee {
    public:
	int salary() const {
	    return _base_salary + _sold_nm * _price * 0.01;
	}
	int get_sold_nm() {
	    return _sold_nm;
	}
	int get_price() {
	    return _price;
	}
	friend std::ostream& operator<<(std::ostream&, const SalesManager&);
	friend std::istream& operator>>(std::istream&, const SalesManager&);
	SalesManager (char *name, int32_t base_salary, int32_t sold_nm, int32_t price) {
	    _name = name;
	    _base_salary = base_salary;
	    _sold_nm = sold_nm;
	    _price = price;
	}
    private:
	int32_t _sold_nm, _price;
};

class EmployeesArray {
    public:
	void add(Employee* e) {
	    _employees.push_back(e);
	}
	int total_salary() const {
	    int32_t total_salary = 0;
	    for (Employee* e: _employees) {
		total_salary += e->salary();
	    }
	    return total_salary;
	}
	friend std::ostream& operator<<(std::ostream&, const EmployeesArray&);
	friend std::istream& operator>>(std::istream&, const EmployeesArray&);
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
