while True:
    try:
        n = int(input("Input: "))
    except ValueError:
        print("Type an integer.")
    else:
        break