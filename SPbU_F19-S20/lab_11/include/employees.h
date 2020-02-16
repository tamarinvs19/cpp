#ifndef LAB11_EMPLOYEES_H_INCLUDED
#define LAB11_EMPLOYEES_H_INCLUDED

#include <stdint.h>
#include <ostream>
#include <istream>

class Employee {
    public:
	virtual int salary() const {};
	virtual int getBaseSalary() const {
	    return _base_salary;
	};
	virtual char * getName() {
	    return _name;
	};
	friend std::ostream& operator<<(std::ostream&, const Employee&);
	friend std::istream& operator>>(std::istream&, const Employee&);
    protected:
	char *_name;
	int32_t _base_salary;
};
class Developer: public Employee {
    public:
	int salary() const override {
	    int salary = _base_salary;
	    if (_has_bonus) { salary += 1000; }
	    return salary;
	}
	bool getHasBonus() {
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
	int salary() const override {
	    return _base_salary + _sold_nm * _price * 0.01;
	}
	friend std::ostream& operator<<(std::ostream&, const SalesManager&);
	friend std::istream& operator>>(std::istream&, const SalesManager&);
    private:
	int32_t _sold_nm, _price;
};

class EmployeesArray {
    public:
	void add(const Employee *e);
	int total_salary() const;
	friend std::ostream& operator<<(std::ostream&, const EmployeesArray&);
	friend std::istream& operator>>(std::istream&, const EmployeesArray&);
    private:
	Employee **_employees;
};

#endif
