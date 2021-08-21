def printAns(players):
    for i,p in enumerate(players,1):
        print('Position of player '+str(i)+' is '+str(p+1)+'.')
def main():
    t=int(input())
    for _ in range(t):
        a,b,c=map(int,input().split())
        players,goto=[0]*a,[-1]*100 #0 to 99
        for _ in range(b):
            origin,dest=map(int,input().split())
            goto[origin-1]=dest-1
        won=False
        for player,_ in enumerate(range(c)):
            val=input()
            if not won:
                player%=a 
                players[player]=min(players[player]+int(val),99)
                if goto[players[player]]!=-1:
                    players[player]=goto[players[player]]
                if players[player] == 99:#print answer
                    won=True
                    printAns(players)
        if not won:
            printAns(players)
main()