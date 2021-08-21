from sys import stdin
mapToValue = {
    'A':4,
    'K':3,
    'Q':2,
    'J':1
}
def cardValue(x):
    c = x[0]
    if str.isdigit(c)or c=='T':
        return 0
    return mapToValue[c]
def main():
    mapToIndex = {
        'S':0,
        'H':1,
        'D':2,
        'C':3
    }
    for line in stdin:
        amount,stopped=[0]*4,[False]*4
        ans,pointsSuitBid,stoppedSuits,maxAmountOfCards,suitWithMoreCards=0,0,0,0,'S'
        cards = line.split(' ')
        for card in cards:
            suitIndex = mapToIndex[card[1]]
            pointsSuitBid += cardValue(card)
            amount[suitIndex]+=1
            if maxAmountOfCards<amount[suitIndex]or(maxAmountOfCards==amount[suitIndex] and suitIndex<mapToIndex[suitWithMoreCards]):
                suitWithMoreCards = card[1]
                maxAmountOfCards = amount[suitIndex]
        for card in cards:
            suitIndex = mapToIndex[card[1]]
            suitAmount = amount[suitIndex]
            if (card[0]=='K' and suitAmount<2)or(card[0]=='Q' and suitAmount<3)or(card[0]=='J' and suitAmount<4):
                pointsSuitBid-=1
            if not stopped[suitIndex]and((card[0]=='A')or(card[0]=='K' and suitAmount>1)or(card[0]=='Q'and suitAmount>2)):
                stopped[suitIndex]=True
                stoppedSuits+=1
        if stoppedSuits==4 and pointsSuitBid>15:
            ans=1
        else:
            for i in range(4):
                if amount[i]==2:
                    pointsSuitBid+=1
                elif amount[i]<2:
                    pointsSuitBid+=2
            if pointsSuitBid>13:
                ans=2
        print("PASS"if ans==0 else ("BID " + ("NO-TRUMP" if ans==1 else suitWithMoreCards)))
main()