#ifndef MY_ARRAY_IMPL_H_
#define MY_ARRAY_IMPL_H_

template<typename T, std::size_t N>
my_array<T, N>::my_array() {
    array_ = new T[N];
}

template<typename T, std::size_t N>
my_array<T, N>::~my_array() {
    delete [] array_;
}

template<typename T, std::size_t N>
T& my_array<T, N>::at(std::size_t index) {
    assert(N > index);
    return array_[index];
}

template<typename T, std::size_t N>
const T& my_array<T, N>::at(std::size_t index) const {
    assert(N > index);
    return array_[index];
}

template<typename T, std::size_t N>
T& my_array<T, N>::operator[](std::size_t index) {
    return array_[index];
}

template<typename T, std::size_t N>
const T& my_array<T, N>::operator[](std::size_t index) const {
    return array_[index];
}

template<typename T, std::size_t N>
bool my_array<T, N>::empty() const  {
    return size() == 0;
}

template<typename T, std::size_t N>
void my_array<T, N>::fill(T val) {
    for (std::size_t i = 0; i < size(); ++i ) {
	array_[i] = val;
    }
}

template<typename T, std::size_t N>
std::size_t my_array<T, N>::size() const  {
    return N;
}

#endif  // MY_ARRAY_IMPL_H_
