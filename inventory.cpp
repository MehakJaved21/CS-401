#include "inventory.h"
#include <iostream>
#include <algorithm>
#include <fstream>

Inventory::~Inventory() {
    products.clear();  // Explicit cleanup (though shared_ptr handles it)
}

void Inventory::add_product(std::shared_ptr<product> product) {
    products.push_back(product);
}

void Inventory::remove_product(const std::string &name) {
    auto it = std::remove_if(products.begin(), products.end(), 
        [&name](const std::shared_ptr<product>& p) { return p->get_name() == name; });

    if (it != products.end()) {
        products.erase(it, products.end());
    }
}

void Inventory::update_inventory_product(const std::shared_ptr<product>& product, int quantity) {
    product->update_item_availability(quantity);
}

std::shared_ptr<product> Inventory::find_product(const std::string &name) const {
    for (const auto &product : products) {
        if (product->get_name() == name) {
            return product;
        }
    }
    return nullptr;
}

void Inventory::save_inventory(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& product : products) {
        file << product->get_name() << " " << product->get_price() << " " << product->get_item_availability() << "\n";
    }
    file.close();
}

void Inventory::load_inventory(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;
    products.clear();

    std::string name;
    double price;
    int availability;
    
    while (std::getline(file, name, ' ') && file >> price >> availability) {
        file.ignore();  // Ignore newline
        products.push_back(std::make_shared<product>(name, price, availability));
    }
    file.close();
}

std::vector<std::shared_ptr<product>> Inventory::get_all_products() const {
    return products;
}


