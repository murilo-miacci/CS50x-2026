text = input("Text: ")

words = text.count(" ") + 1
s = ((text.count(".") + text.count("!") + text.count("?")) / words) * 100
l = (sum(1 for ch in text if ch.isalpha()) / words) * 100

i = 0.0588 * l - 0.296 * s - 15.8

if i < 1:
    print("Before Grade 1")
elif i >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(i)}")
