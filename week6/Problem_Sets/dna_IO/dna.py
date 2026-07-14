import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py databases/[small ot large].csv sequences/[1 to 20].txt")
        return

    with open(sys.argv[1]) as database:
        reader = csv.DictReader(database)
        strs = reader.fieldnames[1:]
        people = list(reader)

    with open(sys.argv[2]) as sequence:
        dna = sequence.read()

    results = {}
    for str_name in strs:
        results[str_name] = longest_match(dna, str_name)

    for person in people:
        match = True
        for str_name in strs:
            if int(person[str_name]) != results[str_name]:
                match = False
                break
        if match:
            print(person["name"])
            return
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
