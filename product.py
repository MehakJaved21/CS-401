class Product:
    def __init__(self, name, price, item_availability):
        self._name = name
        self._price = price
        self._item_availability = item_availability

    def get_item_name(self):
        return self._name

    def get_price(self):
        return self._price

    def get_item_availability(self):
        return self._item_availability

    def update_item_availability(self, quantity):
        self._item_availability += quantity
