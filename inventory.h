#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include "product.h"

class Inventory {
private:
    std::vector<std::shared_ptr<product>> products;

public:
    void add_product(std::shared_ptr<product> product);
    void remove_product(std::shared_ptr<product> product);
    void update_inventory_product(std::shared_ptr<product> product, int quantity);
    std::shared_ptr<product> find_product(const std::string &name);
    void save_inventory(const std::string& filename);
    void load_inventory(const std::string& filename);
    
   
    std::vector<std::shared_ptr<product>> get_all_products() const;
};

#endif // INVENTORY_H


