#ifndef MY_VECTOR_IMPL_H_
#define MY_VECTOR_IMPL_H_

#include <memory>

int get_min_capacity(int n) {
    int ln = 0;
    while ((1 << ln) < n)
	ln++;
    return 1 << ln;
}

template <typename T>
my_vector<T>::my_vector() {
    capacity_ = 1;
    size_ = 0;
}

template <typename T>
my_vector<T>::my_vector(std::size_t n) {
    capacity_ = get_min_capacity(n);
    size_ = n;
    array_ = (T*) new uint8_t [capacity_ * size_of(T)];
    for (int i = 0; i < capacity_; i++) {
	new array_+i T();
    }
}

my_vector<T>::~my_vector() {
    for (int i = 0; i < capacity_; i++) {
	array_[i].~T();
    }
    delete array_;
    delete size_;
    delete capacity_;
}

my_vector<T>::my_vector& operator=(my_vector& other) {
    this.resize(other.size());
    for (int i = 0; i < other.size(); i++) {
	this.array_[i] = other.array_[i];
    }
}

std::size_t my_vector<T>::size() {
    return size_;
}

std::size_t my_vector<T>::capacity() {
    return capacity_;
}

bool my_vector<T>::empty() {
    return size_ == 0;
}

std::size_t my_vector<T>::resize(std::size_t n) {
    if (n > capacity_) {
	reserve(n);
    }
    for (int i = size_; i<n; i++) {
	array_[i] = T();
    }
    size_ = n;
}

std::size_t my_vector<T>::reserve(std::size_t n) {
    if (n > capacity_) {
	capacity_ = get_min_capacity(n);
	array_ = (T*) new uint8_t [capacity_ * size_of(T)];
	for (int i = 0; i < capacity_; i++) {
	    new array_+i T();
	}
	size_ = n;
	array_ = new_array_;
    }
}

T operator [](size_t j) { 
    return array_[j];
}

const T operator [](size_t j) const { 
    return array_[j]; 
}

void my_vector<T>::push_back(T t) {
    resize(size_ + 1);
    array_[size_] = new (array_ + size_) T(t);
}

void my_vector<T>::pop_back() {
    if (empty())
	return ;
    array_[--size_].~T();
}

void my_vector<T>::clear() {
    while (size_ > 0) {
	pop_back();
    }
}

std::ostream& operator<<(std::ostream& os, my_vector<T>& vec) {
    for (int i = 0; i < my_vector.size(); i++) {
	os << my_vector.array_[i] << " ";
    }
    return os;
}

#endif  // MY_VECTOR_IMPL_H_
