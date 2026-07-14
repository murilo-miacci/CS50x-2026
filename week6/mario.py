while True:
    try:
        n = int(input("Height: "))
        if n > 0:
            break
        print("Must be greater than 0.")
    except ValueError:
        print("Type an integer.")

for i in range(n):
    print(f"#" * (i + 1))
