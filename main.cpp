#include <iostream>
#include <memory>
#include "inventory.h"
#include "category.h"
#include "product.h"


void display_menu() {
    std::cout << "\nInventory Management System\n";
    std::cout << "1. View Products\n";
    std::cout << "2. Add a Product\n";
    std::cout << "3. Remove a Product\n";
    std::cout << "4. Update Product Stock\n";
    std::cout << "5. Find a Product\n";
    std::cout << "6. Save & Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    inventory.load_inventory("inventory_data.txt");

    char choice;
    do {
        display_menu();
        std::cin >> choice;
        
        if (choice == '1') {
            std::cout << "Current Inventory:\n";
            for (const auto& product : inventory.get_all_products()) {
                std::cout << product->get_name() << " - Price: $" 
                          << product->get_price() << " - Stock: " 
                          << product->get_item_availability() << "\n";
            }
        } 
        else if (choice == '3') {
            std::string name;
            std::cout << "Enter product name to remove: ";
            std::cin >> name;
            inventory.remove_product(name);
        } 

    } while (choice != '6');

    inventory.save_inventory("inventory_data.txt");
    std::cout << "Inventory saved. Exiting...\n";
    return 0;
}


