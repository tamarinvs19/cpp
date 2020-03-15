#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_

#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>

template<typename T, std::size_t N>
class my_array {
    public:
	my_array();
	~my_array();
	T& at(std::size_t index);
	const T& at(std::size_t index) const;
	T& operator[](std::size_t index);
	const T& operator[](std::size_t index) const;

	bool empty() const ;
	std::size_t size() const ;

	void fill(T val);
    private:
	T* array_;
};

#include "my_array_impl.h"

#endif  // MY_ARRAY_H_
