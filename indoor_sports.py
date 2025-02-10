from product import Product

class IndoorSportsProduct(Product):
    def browse_items(self):
        print(f"Searching Indoor Sports Products - Total Available Products: {self.get_item_availability()}")

class Volleyball(IndoorSportsProduct):
    def __init__(self, name, price, item_availability, material, size):
        super().__init__(name, price, item_availability)
        self._material = material
        self._size = size

    def apply_special_offer(self):
        discount = 0.10
        self._price *= (1 - discount)
        print(f"Discount applied to {self.get_item_name()}! New price: ${self._price:.2f}.")
        print(f"Material: {self._material}, Size: {self._size}")

class TableTennis(IndoorSportsProduct):
    def __init__(self, name, price, item_availability, paddle_style, table_material):
        super().__init__(name, price, item_availability)
        self._paddle_style = paddle_style
        self._table_material = table_material

    def available_stock(self):
        if self.get_item_availability() > 0:
            print(f"Stock Available for {self.get_item_name()} : {self.get_item_availability()}.")
            print(f"Paddle Style: {self._paddle_style}, Table Material: {self._table_material}")
        else:
            print(f"Out of Stock! {self.get_item_name()}")
