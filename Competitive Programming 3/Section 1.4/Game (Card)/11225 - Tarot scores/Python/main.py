mapToPoints={
    "king":9,
    "queen":7,
    "knight":5,
    "jack":3
}
mapToPointsOudlers={
    "fool",
    "one of trumps",
    "twenty-one of trumps"
}
pointsToWin=[112,102,82,72]
def main():
    t = int(input())+1
    for cs in range(1,t):
        if cs > 1:
            print()
        print("Hand #"+str(cs))
        points,oudlers=0,0
        n = int(input())
        for _ in range(0,n):
            card=input()
            begCard = card.split()[0]
            #check if it is oudler
            if card in mapToPointsOudlers:
                points+=9
                oudlers+=1
            else:
                #sum points
                if begCard in mapToPoints:
                    points+=mapToPoints[begCard]
                else:
                    points+=1
        dif = abs(pointsToWin[oudlers]-points)
        print("Game "+("lost" if points<pointsToWin[oudlers] else "won")+" by "+str(int(dif/2) if dif%2==0 else str(dif/2))+" point(s).")
main()