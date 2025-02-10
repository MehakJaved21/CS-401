from product import Product

class OutdoorSportsProduct(Product):
    def browse_items(self):
        print(f"Searching Outdoor Sports Products - Total Available Products: {self.get_item_availability()}")

class Camping(OutdoorSportsProduct):
    def __init__(self, name, price, item_availability, tent_size, durability, weather_rating):
        super().__init__(name, price, item_availability)
        self._tent_size = tent_size
        self._durability = durability
        self._weather_rating = weather_rating

    def add_product(self):
        print(f"Adding camping item: {self.get_item_name()}. Tent Size: {self._tent_size}, Durability: {self._durability}, Weather Rating: {self._weather_rating}")

class Soccer(OutdoorSportsProduct):
    def __init__(self, name, price, item_availability, ball_material, goal_net_size):
        super().__init__(name, price, item_availability)
        self._ball_material = ball_material
        self._goal_net_size = goal_net_size

    def cal_product_discount(self):
        discount = 0.05
        self._price *= (1 - discount)
        print(f"Discount applied to {self.get_item_name()}! New price: ${self._price:.2f}.")
        print(f"Ball Material: {self._ball_material}, Goal Net Size: {self._goal_net_size}")
