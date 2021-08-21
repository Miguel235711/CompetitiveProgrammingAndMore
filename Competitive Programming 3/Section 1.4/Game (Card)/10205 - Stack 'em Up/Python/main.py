toSuit,toValue=["Clubs","Diamonds","Hearts","Spades"],["Jack","Queen","King","Ace"]
shuffles,cards=[],[]
def initialize(n):
    global shuffles,cards
    shuffles,cards=[],[]
    for _ in range(2):
        cards.append([])
    for _ in range(n):
        shuffles.append([])
    for i in range(52):
        cards[0].append(i)
        cards[1].append(0)
def getValue(card):
    card %= 13
    if card < 9:
        return str(card+2)
    return toValue[card-9]
def main():
    global shuffles,cards
    t = int(input())
    input()
    for cs in range(t):
        if cs > 0 :
            print()
        n = int(input())
        initialize(n)
        i,processedFromI=0,0
        while i < n:
            line = input().split()
            for tk in line:
                shuffles[i].append(int(tk)-1)
                processedFromI+=1
                if processedFromI == 52:
                    processedFromI=0
                    i+=1
        shuf = 1
        while True:
            try:
                line = input()
            except:
                break
            if line == '':
                break
            k = int(line)-1
            #shuffle
            for j in range(len(shuffles[k])):
                cards[shuf][j]=cards[1-shuf][shuffles[k][j]]
            shuf = 1 - shuf
        #! shuf has the answer
        for card in cards[1-shuf]:
            print(getValue(card)+" of "+toSuit[card//13])
main()