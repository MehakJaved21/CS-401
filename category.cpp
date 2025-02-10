#include "category.h"
#include <iostream>
#include <algorithm>  // Required for std::remove_if

category::category(const std::string &name) : name(name) {}

void category::add_product(std::shared_ptr<product> product) {
    products.push_back(product);
}

void category::remove_product(const std::string &product_name) {
    auto it = std::remove_if(products.begin(), products.end(),
        [&product_name](const std::shared_ptr<product>& p) { return p->get_name() == product_name; });

    if (it != products.end()) {
        products.erase(it, products.end());
    }
}

void category::add_subcategory(std::shared_ptr<category> subcategory) {
    subcategories.push_back(subcategory);
}

std::vector<std::shared_ptr<product>> category::get_products() const {
    return products;
}

std::vector<std::shared_ptr<category>> category::get_subcategories() const {
    return subcategories;
}
