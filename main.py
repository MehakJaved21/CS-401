from inventory import Inventory
from indoor_sports import Volleyball, TableTennis
from outdoor_sports import Camping, Soccer

def main():
    inventory = Inventory()
    
    while True:
        print("\n1. Add Product")
        print("2. Remove Product")
        print("3. Update Stock")
        print("4. Find Product")
        print("5. Show Inventory")
        print("6. Exit")

        choice = input("Enter your choice: ")
        
        if choice == '1':
            name = input("Enter product name: ")
            price = float(input("Enter price: "))
            quantity = int(input("Enter quantity: "))

            print("Choose product type:")
            print("1. Volleyball")
            print("2. Table Tennis")
            print("3. Camping")
            print("4. Soccer")
            product_type = input("Enter choice: ")

            if product_type == '1':
                material = input("Enter material: ")
                size = input("Enter size: ")
                inventory.add_product(Volleyball(name, price, quantity, material, size))
            elif product_type == '2':
                paddle_style = input("Enter paddle style: ")
                table_material = input("Enter table material: ")
                inventory.add_product(TableTennis(name, price, quantity, paddle_style, table_material))
            elif product_type == '3':
                tent_size = input("Enter tent size: ")
                durability = input("Enter durability: ")
                weather_rating = input("Enter weather rating: ")
                inventory.add_product(Camping(name, price, quantity, tent_size, durability, weather_rating))
            elif product_type == '4':
                ball_material = input("Enter ball material: ")
                goal_net_size = input("Enter goal net size: ")
                inventory.add_product(Soccer(name, price, quantity, ball_material, goal_net_size))
            else:
                print("Invalid choice. Product not added.")

        elif choice == '6':
            print("Exiting...")
            break

main()
