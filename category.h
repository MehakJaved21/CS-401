#ifndef CATEGORY_H
#define CATEGORY_H


#include <string>
#include <vector>
#include <memory>
#include "product.h"

class category {
private:
    std::string name;
    std::vector<std::shared_ptr<category>> subcategories;
    std::vector<std::shared_ptr<product>> products;

public:
    category(const std::string &name);
    void add_product(std::shared_ptr<product> product);
    void remove_product(const std::shared_ptr<product>& product);
    void add_subcategory(std::shared_ptr<category> subcategory);
};

#endif // CATEGORY_H
