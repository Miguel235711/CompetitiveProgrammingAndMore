anagrams = {}
def main():
    while True:
        line = input()
        if line[0] == 'X':
            break
        sortedLine = ''.join(sorted(line))
        if sortedLine not in anagrams:
            anagrams[sortedLine] = []
        anagrams[sortedLine].append(line)
    #sort vectors
    for an in anagrams.values():
        an.sort()
    #answer anagram queries
    while True:
        line = input()
        if line[0] == 'X':
            break
        line = ''.join(sorted(line))
        if line in anagrams:
            for element in anagrams[line]:
                print(element)
        else:
            print('NOT A VALID WORD')
        print('******')
main()