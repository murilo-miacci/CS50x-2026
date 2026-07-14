while True:
    try:
        change = round(float(input("Change: ")) * 100)
        if change >= 0:
            break
    except ValueError:
        pass
    
count = 0

for coin in [25, 10, 5, 1]:
    count += change // 25
    change %= coin

print(count)