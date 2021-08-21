import sys

def main():
    cs = 1
    while True:
        minimumCost,mostReq,bestAns=sys.maxsize,0,""
        n,p = map(int,input().split())
        if n==0 and p==0:
            break
        if cs>1:
            print()
        for _ in range(0,n):
            input()
        for _ in range(0,p):
            name = input()
            ipt = input().split()
            d,r=float(ipt[0]),int(ipt[1])
            if r > mostReq or (r == mostReq and minimumCost > d) :
                mostReq = r
                minimumCost = d
                bestAns = name
            for _ in range(0,r):
                input()
        print("RFP #"+str(cs)+"\n"+bestAns)
        cs+=1
            
            
main()