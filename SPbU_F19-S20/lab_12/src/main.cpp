#include <iostream>

#include "my_vector.h"

namespace product {

class Product {
public:
    Product(const char* name, int quantity, double price);
    friend std::ostream& operator<<(std::ostream&, Product&) p;

private:
    char *name_;  // Указатель владеет C-style строкой, на которую указывает.
    int quantity_;
    double price_;
};

std::ostream& operator<<(std::ostream& os, Product& p) {
    os << p.name_ << " " << p.quantity_ << " " << p.price_;
}

void print(const my_vector::my_vector<Product>& v) {
    std::cout << v << std::endl;
}

}  // namespace product

int main() {
    //test_my_vector<int>(5, 10);
    //test_my_vector<Product>(Product("asdf", 4, 12.0), Product("qwe", -1, 7.5));

    return 0;
}
