def main():
    t = int(input())
    for cs in range(1,t+1):
        input()
        times = map(int,input().split())
        mCost,jCost=0,0
        for time in times:
            mCost += (time//30+1)*10
            jCost += (time//60+1)*15
        print("Case "+str(cs)+": ",end='')
        if mCost < jCost:
            print("Mile "+str(mCost))
        elif mCost == jCost:
            print("Mile Juice "+str(mCost))
        else:
            print("Juice "+str(jCost))
main()