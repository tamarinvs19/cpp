#ifndef MY_VECTOR_IMPL_H_
#define MY_VECTOR_IMPL_H_

#include <memory>

int get_min_capacity(std::size_t n) {
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
    uint8_t * buf = new uint8_t [capacity_ * size_of(T)];
    array_ = (T*) buf;
    for (int i = 0; i < size_; i++) {
	array_[i] = T();
    }
}

my_vector<T>::~my_vector() {
    // while (_size > 0) 
	// alloc.destroy(--_size);
}

my_vector<T>::my_vector operator=(my_vector other) {
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
	capacity(n);
    }
    
}

std::size_t my_vector<T>::capacity(std::size_t n) {
}

reference operator [](size_t j) { 
    return array_[j];
}
//
// const_reference operator [](size_t j) const { 
//     return array_[j]; 
// }

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
    for (int i = 0; i < my_vector.size_; i++) {
	os << my_vector.array_[i] << " ";
    }
    return os;
}

#endif  // MY_VECTOR_IMPL_H_
