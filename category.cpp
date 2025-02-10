#include "category.h"
#include <iostream>
#include <algorithm>  // Required for std::remove

category::category(const std::string &name) : name(name) {}

void category::add_product(std::shared_ptr<product> product) {
    products.push_back(product);
}

void category::remove_product(const std::shared_ptr<product>& product) {
    auto it = std::remove(products.begin(), products.end(), product);
    if (it != products.end()) {  // Ensure the product exists before erasing
        products.erase(it, products.end());
    }
}


void category::add_subcategory(std::shared_ptr<category> subcategory) {
    subcategories.push_back(subcategory);
}
