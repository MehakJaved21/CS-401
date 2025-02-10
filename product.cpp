#include "product.h"

product::product(const std::string &name, double price, int item_availability)
    : name(name), price(price), item_availability(item_availability) {}

std::string product::get_name() const { return name; }
double product::get_price() const { return price; }
int product::get_item_availability() const { return item_availability; }
void product::update_item_availability(int quantity) { item_availability += quantity; }
