def multispaceLine():
    return map(int,filter(lambda num : num!='',input().split(' ')))
def main():
    thrS,last=[],1
    lose,extra=101,102
    while last:
        for x in map(int,input().split(' ')):
            thrS.append(x)
            last=x
    while True:
        n=int(input())
        if not n:
            break
        #init game set
        special = [ i for i in range(101)]
        #read game set
        while True:
            a,b=multispaceLine()
            if not a:
                break
            special[a]=b
        while True:
            x=int(input())
            if not x:
                break
            absX=abs(x)
            special[absX] = lose if x<0 else extra
        #simulate
        loseTurn,cell=[False]*n,[0]*n
        throwI,player=0,0
        while True:
            if loseTurn[player]:
                loseTurn[player]=False
            else:
                dieNewCell = cell[player] + thrS[throwI]
                if dieNewCell < 101:
                    if special[dieNewCell]<101:
                        cell[player]=special[dieNewCell]
                    if special[cell[player]]==lose:
                        loseTurn[player]=True
                    elif special[cell[player]]==extra:
                        player = player-1 if player else n-1
                    if cell[player]==100:
                        print(player+1)
                        break
            throwI+=1
            player=(player+1)%n
main()