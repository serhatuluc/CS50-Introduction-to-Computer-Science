import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage:python dna.py CSV_file DNA_sequence")

    # Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    f = open(sys.argv[2], 'r')
    sequence = f.read()

    # Find longest match of each STR in DNA sequence
    # List comprehension is used to get subsequences
    list_of_subsequences = [subsequences for subsequences in database[0]]

    # Since it takes the column for "name" first element of the list is removed
    del list_of_subsequences[0]

    # List of longest match is created
    list_longest_matches = []
    for key in range(len(list_of_subsequences)):
        num_long = longest_match(sequence, list_of_subsequences[key])
        list_longest_matches.append(num_long)

    # Check database for matching profiles
    count = 0

    # Looping through database
    for i in range(len(database)):

        # Looping through list of subsequences
        for j in range(len(list_of_subsequences)):
            # check if each element of the list_of_longest_matches maches to a dictionary of database
            if int(database[i][list_of_subsequences[j]]) == int(list_longest_matches[j]):
                count += 1

                # if all elements matches print the name of the person
                if count == len(list_longest_matches):
                    print(database[i]["name"])
                    return
    # If no match print it
    print("No match")
    return


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

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
