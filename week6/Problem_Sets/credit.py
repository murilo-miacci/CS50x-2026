def luhn(num):
    n = num
    length = 0
    while n != 0:
        length += 1
        n //= 10

    b100 = 10;
    total = 0

    for i in range(length // 2):
        ch = (num // b100 - (num // (b100 * 10)) * 10) * 2
        if ch >= 10:
            total += ch - 9
        else:
            total += ch

        och = (num // (b100 // 10) - (num // b100) * 10)
        total += och

        b100 *= 100
    
    if length % 2 != 0:
        total += num // (10 ** (length - 1))

    return total % 10 == 0

def main():
    while True:
        try:
            number = int(input("Card number: "))
            if number > 0:
                break
        except ValueError:
            pass
    
    n_temp = number

    length = 0
    while n_temp != 0:
        length += 1
        n_temp //= 10

    prefix = number // (10 ** (length - 2))
    first = prefix // 10
    second = prefix % 10

    if first == 3 and second in (4, 7) and length == 15 and luhn(number):
        print("AMEX")
    elif first == 5 and second in (1, 2, 3, 4, 5) and length == 16 and luhn(number):
        print("MASTERCARD")
    elif first == 4 and length in (13, 16) and luhn(number):
        print("VISA")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
