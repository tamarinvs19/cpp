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
    i = 0;
}

template <typename T>
my_vector<T>::my_vector(std::size_t n) {
    capacity_ = get_min_capacity(n);
    size_ = n;
    i = 0;
    uint8_t * buf = new uint8_t [capacity_ * size_of(T)];
    array_ = (T*) buf;
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
    return i == 0;
}

reference operator [](size_t j) { 
    return array_[j];
}

const_reference operator [](size_t j) const { 
    return array_[j]; 
}

void my_vector<T>::push_back(T t) {
    resize(i + 1);
    array_[i] = new (array_ + i) T(t);
    i++;
}

void my_vector<T>::pop_back() {
    if (empty())
	return ;
    i--;
    // T last_element = array_[i];
    array_[i].~T();

    // return last_element;
}

void my_vector<T>::clear() {
    while (size_ > i) {
	pop_back();
    }
}

#endif  // MY_VECTOR_IMPL_H_
