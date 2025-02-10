#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include "product.h"

class Inventory {
private:
    std::vector<std::shared_ptr<product>> products;

public:
    ~Inventory();  // Added destructor

    void add_product(std::shared_ptr<product> product);
    void remove_product(const std::string &name);  // Now removes by name
    void update_inventory_product(const std::shared_ptr<product>& product, int quantity);
    
    std::shared_ptr<product> find_product(const std::string &name) const;  // Added const
    void save_inventory(const std::string& filename) const;  // Added const
    void load_inventory(const std::string& filename);

    std::vector<std::shared_ptr<product>> get_all_products() const;
};

#endif // INVENTORY_H



