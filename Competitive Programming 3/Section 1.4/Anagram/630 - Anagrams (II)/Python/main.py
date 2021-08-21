def main():
    t = int(input())
    for cs in range(t):
        if cs!=0:
            print()
        anagrams={}
        input()
        #build anagram ds
        for _ in range(int(input())):
            line = input()
            sortedLine = ''.join(sorted(line))
            if sortedLine not in anagrams:
                anagrams[sortedLine]=[]
            anagrams[sortedLine].append(line)
        #anagrams queries
        while True:
            line = input()
            if line == 'END':
                break
            print('Anagrams for:',line)
            sortedLine = ''.join(sorted(line))
            if sortedLine in anagrams:
                listRef = anagrams[sortedLine]
                for i in range(len(listRef)):
                    print('{0:>3}'.format(i+1)+')',listRef[i])
            else:
                print('No anagrams for:',line)
main()