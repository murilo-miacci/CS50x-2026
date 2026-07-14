while True:
    try:
        n = int(input("Height: "))
        if n > 0 and n < 9:
            break
        print("Must be greater than 0 and less than 9")
    except ValueError:
        print("Type an integer.")

for i in range(n):
    print(" " * (n - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1) + " " * (n - i - 1))