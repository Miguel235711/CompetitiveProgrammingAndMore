from sys import stdin

sortedLowerStrings = {}
anagramOriginal = []

def main():
    for line in stdin:
        line = line.rstrip()
        if line[0]=='#':
            break
        for word in line.split(' '):
            if word:
                anagramOriginal.append([word,False])
                sortedLowerWord = list(word.lower())
                sortedLowerWord.sort()
                sortedLowerWord = ''.join(sortedLowerWord)
                if sortedLowerWord in sortedLowerStrings :
                    #visit both
                    anagramOriginal[sortedLowerStrings[sortedLowerWord]][1]=anagramOriginal[len(anagramOriginal)-1][1]=True
                else:
                    sortedLowerStrings[sortedLowerWord]=len(anagramOriginal)-1
    anagramOriginal.sort()
    for originalP in anagramOriginal:
        if not originalP[1]:
            print(originalP[0])
main()