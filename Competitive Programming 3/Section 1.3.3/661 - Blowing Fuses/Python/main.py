def main():
    cs = 1 
    while True:
        n,m,c=map(int,input().split())
        if n == 0 and m==0 and c ==0:
            break
        print("Sequence "+str(cs))
        cs+=1
        isTurnedOn,consumption = [False] * 22,[0] * 22
        for i in range(1,n+1):
            consumption[i]=int(input())
        consumed,maxConsumed=0,0
        for i in range(0,m):
            toggleI = int(input())
            if isTurnedOn[toggleI] == True:
                consumed-=consumption[toggleI]
            else:
                consumed+=consumption[toggleI]
            isTurnedOn[toggleI]= not isTurnedOn[toggleI]
            maxConsumed = max(maxConsumed,consumed)
        print("Fuse was "+("blown" if maxConsumed > c else "not blown")+".")
        if maxConsumed <= c:
            print("Maximal power consumption was "+str(maxConsumed)+" amperes.")
        print()
main()