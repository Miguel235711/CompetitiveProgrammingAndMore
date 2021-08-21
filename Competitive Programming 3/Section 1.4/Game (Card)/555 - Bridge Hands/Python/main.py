mapFromDirToInt = {
    'S':0,
    'W':1,
    'N':2,
    'E':3
}
mapFromSuitToInt = {
    'C':0,
    'D':1,
    'S':2,
    'H':3
}
rankToInt = {
    'T':8,
    'J':9,
    'Q':10,
    'K':11,
    'A':12
}
mapFromIntToSuit = ['S','W','N','E']
def offsetChar(x):
    if str.isdigit(x):
        return ord(x) - ord('2')
    return rankToInt[x]
def toIndex(card):
    return mapFromSuitToInt[card[0]]*13 + offsetChar(card[1])
def main():
    while True:
        personCards = [[],[],[],[]]
        directionDealer = input()
        if directionDealer == '#':
            break
        person = (mapFromDirToInt[directionDealer]+1)%4
        for _ in range(2):
            line = input()
            for card in [line[i:i+2] for i in range(0,len(line),2)]:
                personCards[person].append(card)
                person = (person+1) % 4
        for i,cards in enumerate(personCards):
            cards.sort(key=lambda card:toIndex(card))
            print(mapFromIntToSuit[i]+':',end='')
            for card in cards:
                print(' '+card,end='')
            print()
main()