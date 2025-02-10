class Category:
    def __init__(self, name):
        self._name = name
        self._subcategories = []
        self._products = []

    def add_product(self, product):
        self._products.append(product)
        print(f"Product added to the category {self._name}: {product.get_item_name()}")

    def remove_product(self, product):
        self._products.remove(product)
        print(f"Product removed from the category {self._name}: {product.get_item_name()}")

    def add_subcategory(self, category):
        self._subcategories.append(category)
        print(f"Subcategory added to {self._name}: {category._name}")
