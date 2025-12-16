# product.py

class Product:
    def __init__(self, name, price, stock):
        self.name = name
        self.price = price
        self.stock = stock

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name

    def get_price(self):
        return self.price

    def set_price(self, price):
        self.price = price

    def get_stock(self):
        return self.stock

    def set_stock(self, stock):
        self.stock = stock

    def update_stock(self, quantity):
        if quantity > self.stock:
            print("Not enough in stock..")
        else:
            self.stock -= quantity

    def display(self):
        print(f"Product: {self.name}\nPrice: ${self.price}\nStock: {self.stock}\n")


class Volleyball(Product):
    def __init__(self, name, price, stock, material, size):
        super().__init__(name, price, stock)
        self.material = material
        self.size = size

    def display(self):
        super().display()
        print(f"Material: {self.material}\nSize: {self.size} inches\n")


class VolleyballNet(Product):
    def __init__(self, name, price, stock, net_type):
        super().__init__(name, price, stock)
        self.type = net_type

    def display(self):
        super().display()
        print(f"Type: {self.type}\n")


class Paddle(Product):
    def __init__(self, name, price, stock, style):
        super().__init__(name, price, stock)
        self.style = style

    def display(self):
        super().display()
        print(f"Style: {self.style}\n")


class Table(Product):
    def __init__(self, name, price, stock, material):
        super().__init__(name, price, stock)
        self.material = material

    def display(self):
        super().display()
        print(f"Material: {self.material}\n")


class Ball(Product):
    pass  # Inherits everything from Product


class Tent(Product):
    def __init__(self, name, price, stock, size, durability, weather_rating):
        super().__init__(name, price, stock)
        self.size = size
        self.durability = durability
        self.weather_rating = weather_rating

    def display(self):
        super().display()
        print(f"Size: {self.size}\nDurability: {self.durability}\nWeather Rating: {self.weather_rating}\n")


class SleepingBag(Product):
    def __init__(self, name, price, stock, size):
        super().__init__(name, price, stock)
        self.size = size

    def display(self):
        super().display()
        print(f"Size: {self.size}\n")


class SoccerBall(Product):
    def __init__(self, name, price, stock, material):
        super().__init__(name, price, stock)
        self.material = material

    def display(self):
        super().display()
        print(f"Material: {self.material}\n")


class GoalNet(Product):
    def __init__(self, name, price, stock, size):
        super().__init__(name, price, stock)
        self.size = size

    def display(self):
        super().display()
        print(f"Size: {self.size}\n")


def display_product_details(product):
    if product is None:
        print("Invalid Product.")
        return
    product.display()


def handle_purchase(product, quantity):
    if product.get_stock() >= quantity:
        total_price = product.get_price() * quantity
        print(f"\nTotal Price: ${total_price}")
        product.update_stock(quantity)
        print(f"Updated Stock: {product.get_stock()} remaining")
        return True
    else:
        print("Sorry, not enough stock available..")
        return False


def product_choice(section, products):
    prod_choice = int(input("\nWhich would you like to buy? (type 1 or 2): ")) - 1
    qty = int(input("\nHow many would you like to buy? "))

    if 0 <= prod_choice < len(products):
        handle_purchase(products[prod_choice], qty)
    else:
        print("Invalid Choice, please enter a valid number..")