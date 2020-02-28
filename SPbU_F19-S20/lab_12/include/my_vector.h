#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include <cstddef>
#include <iostream>

namespace my_vector {

template<typename T>
class my_vector {
public:
    my_vector();
    my_vector(std::size_t n);
    my_vector(my_vector<T>& other);
    my_vector<T>& operator=(my_vector<T>&);
    ~my_vector();

    std::size_t size();
    std::size_t capacity();
    bool empty();

    void resize(std::size_t n);
    void reserve(std::size_t n);

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    void push_back(T t);
    void pop_back();
    void clear();

    std::ostream& operator<<(std::ostream&, my_vector<T>&);

private:
    size_t capacity_;
    size_t size_;
    T* array_;
};

}

#include "my_vector_impl.h"

#endif  // MY_VECTOR_H_
