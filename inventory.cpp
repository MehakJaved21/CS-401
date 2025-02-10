#include "inventory.h"
#include <iostream>
#include <algorithm>
#include <fstream>

void Inventory::add_product(std::shared_ptr<product> product) {
    products.push_back(product);
}

void Inventory::remove_product(std::shared_ptr<product> product) {
    auto it = std::remove(products.begin(), products.end(), product);
    if (it != products.end()) {
        products.erase(it, products.end());
    }
}

void Inventory::update_inventory_product(std::shared_ptr<product> product, int quantity) {
    product->update_item_availability(quantity);
}

std::shared_ptr<product> Inventory::find_product(const std::string &name) {
    for (auto &product : products) {
        if (product->get_name() == name) {
            return product;
        }
    }
    return nullptr;
}

void Inventory::save_inventory(const std::string& filename) {
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
    while (file >> name >> price >> availability) {
        products.push_back(std::make_shared<product>(name, price, availability));
    }
    file.close();
}

std::vector<std::shared_ptr<product>> Inventory::get_all_products() const {
    return products;
}

