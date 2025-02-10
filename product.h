#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class product {
protected:
    std::string name;
    double price;
    int item_availability;

public:
    product(const std::string &name, double price, int item_availability);
    virtual ~product() = default;

    std::string get_name() const;
    double get_price() const;
    int get_item_availability() const;
    void update_item_availability(int quantity);
};

#endif // PRODUCT_H
