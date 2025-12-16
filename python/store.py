# store.py

from product import *

def show_indoor_section():
    print("\nIndoor Section:")
    print("1. Volleyball")
    print("2. Table Tennis")

    sub_choice = input("\nWould you like to see the Volleyball or Table Tennis section? (type 'Volleyball' or 'Table Tennis'): ").strip().lower()

    if sub_choice == "volleyball":
        show_volleyball_section()
    elif sub_choice == "table tennis":
        show_table_tennis_section()
    else:
        print("Invalid input. Please enter Volleyball or Table Tennis.")

def show_outdoor_section():
    print("\nOutdoor Section:")
    print("1. Camping")
    print("2. Soccer")

    sub_choice = input("Would you like to view the Camping or Soccer section? (type 'Camping' or 'Soccer'): ").strip().lower()

    if sub_choice == "camping":
        show_camping_section()
    elif sub_choice == "soccer":
        show_soccer_section()
    else:
        print("Invalid input. Please enter Camping or Soccer.")

def show_volleyball_section():
    print("\nVolleyball Section:")
    print("1. Volleyballs")
    print("2. Nets")

    item_choice = input("\nWhich Section Would You Like To View? (type 'Volleyballs' or 'Nets'): ").strip().lower()

    if item_choice == "volleyballs":
        volleyballs = [
            Volleyball("Volleyball", 29.99, 30, "Leather", 18),
            Volleyball("Volleyball", 24.99, 20, "Synthetic Leather", 20)
        ]
        for p in volleyballs:
            display_product_details(p)
        product_choice("volleyballs", volleyballs)

    elif item_choice == "nets":
        nets = [
            VolleyballNet("Volleyball Net", 59.99, 25, "Professional"),
            VolleyballNet("Volleyball Net", 49.99, 35, "Training")
        ]
        for p in nets:
            display_product_details(p)
        product_choice("nets", nets)

    else:
        print("Invalid input. Please enter 'volleyballs' or 'nets'.")

def show_table_tennis_section():
    print("\nTable Tennis Section:")
    print("1. Paddles")
    print("2. Tables")
    print("3. Balls")

    item_choice = input("\nWhich Section would you like to view? (Type 'Paddles', 'Tables', or 'Balls'): ").strip().lower()

    if item_choice == "paddles":
        paddles = [
            Paddle("Table Tennis Paddle", 39.99, 10, "Professional"),
            Paddle("Table Tennis Paddle", 19.99, 15, "Standard")
        ]
        for p in paddles:
            display_product_details(p)
        product_choice("paddles", paddles)

    elif item_choice == "tables":
        tables = [
            Table("Table Tennis Table", 199.99, 3, "Plywood"),
            Table("Table Tennis Table", 149.99, 5, "Laminate")
        ]
        for p in tables:
            display_product_details(p)
        product_choice("tables", tables)

    elif item_choice == "balls":
        balls = [
            Ball("Table Tennis Balls", 9.99, 30),
            Ball("Pro Table Tennis Balls", 19.99, 15)
        ]
        for p in balls:
            display_product_details(p)
        product_choice("balls", balls)

    else:
        print("Invalid Input, Please Enter 'Paddles', 'Tables', or 'Balls'.")

def show_camping_section():
    print("\nCamping Section:")
    print("1. Tents")
    print("2. Sleeping Bags")

    item_choice = input("Which section would you like to view? (type 'Tents' or 'Sleeping Bags'): ").strip().lower()

    if item_choice == "tents":
        tents = [
            Tent("Camping Tent", 149.99, 10, "Large", "Standard", "Rain-Proof"),
            Tent("Explorer Tent", 199.99, 8, "Extra Large", "Strong", "All Weather-Proof")
        ]
        for p in tents:
            display_product_details(p)
        product_choice("tents", tents)

    elif item_choice == "sleeping bags":
        sleep_bags = [
            SleepingBag("Sleeping Bag", 49.99, 12, "Large"),
            SleepingBag("Sleeping Bag", 29.99, 16, "Medium")
        ]
        for p in sleep_bags:
            display_product_details(p)
        product_choice("sleeping bags", sleep_bags)

    else:
        print("Invalid input. Please enter 'tents' or 'sleeping bags'.")

def show_soccer_section():
    print("\nSoccer Section:")
    print("1. Balls")
    print("2. Nets")

    item_choice = input("Which section would you like to view? (type 'Balls' or 'Nets'): ").strip().lower()

    if item_choice == "balls":
        soc_balls = [
            SoccerBall("Soccer Ball", 44.99, 14, "Leather"),
            SoccerBall("Soccer Ball", 39.99, 12, "Polyurethane")
        ]
        for p in soc_balls:
            display_product_details(p)
        product_choice("balls", soc_balls)

    elif item_choice == "nets":
        soc_nets = [
            GoalNet("Soccer Net", 99.99, 5, "Standard"),
            GoalNet("Soccer Net", 59.99, 8, "Little League")
        ]
        for p in soc_nets:
            display_product_details(p)
        product_choice("nets", soc_nets)

    else:
        print("Invalid input. Please enter 'balls' or 'nets'.")

def main():
    while True:
        print("Welcome to the Sporting Goods Store")
        choice = input("\nWould you like to view the indoor or outdoor section? (type 'exit' to quit): ").strip().lower()

        if choice == "exit":
            break
        elif choice == "indoor":
            show_indoor_section()
        elif choice == "outdoor":
            show_outdoor_section()
        else:
            print("Invalid input. Please enter indoor, outdoor, or exit.")

if __name__ == "__main__":
    main()