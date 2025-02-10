from product import Product

class Inventory:
    def __init__(self):
        self._products = []

    def add_product(self, product):
        self._products.append(product)
        print(f"Added to Inventory - {product.get_item_name()}")

    def remove_product(self, product):
        self._products.remove(product)
        print(f"Removed from Inventory - {product.get_item_name()}")

    def update_inventory_product(self, product, quantity):
        product.update_item_availability(quantity)
        print(f"Product availability updated: {product.get_item_name()} - New Availability {product.get_item_availability()}")

    def find_product(self, name):
        for prod in self._products:
            if prod.get_item_name() == name:
                print(f"Product Matched {prod.get_item_name()}")
                return prod
        print(f"Not Matched")
        return None

    def show_inventory(self):
        if not self._products:
            print("Inventory is empty.")
        else:
            print("\nCurrent Inventory:")
            for prod in self._products:
                print(f"{prod.get_item_name()} - ${prod.get_price()} - Stock: {prod.get_item_availability()}")
