import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print('The program requires 2 command line arguments.')
        return 1

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)

        for line in reader:
            database.append(line)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        dnaSequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    longestSequences = {
        'AGATC': str(longest_match(dnaSequence, 'AGATC')),
        'TTTTTTCT': str(longest_match(dnaSequence, 'TTTTTTCT')),
        'AATG': str(longest_match(dnaSequence, 'AATG')),
        'TCTAG': str(longest_match(dnaSequence, 'TCTAG')),
        'GATA': str(longest_match(dnaSequence, 'GATA')),
        'TATC': str(longest_match(dnaSequence, 'TATC')),
        'GAAA': str(longest_match(dnaSequence, 'GAAA')),
        'TCTG': str(longest_match(dnaSequence, 'TCTG'))
    }


    # TODO: Check database for matching profiles
    for person in database:
        sequencesMatch = True

        for subsequence in person:
            if subsequence == 'name':
                continue

            if person[subsequence] != longestSequences[subsequence]:
                sequencesMatch = False
                break

        if sequencesMatch:
            print(person['name'])
            return

    print('No match')


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
