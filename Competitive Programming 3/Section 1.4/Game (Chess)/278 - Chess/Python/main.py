import math

def main():
    t = int(input())
    for _ in range(t):
        typ,n,m = [int(c) if i > 0 else c for i,c in enumerate(input().split())]
        maxAns=0
        if typ == 'r':
            maxAns = min(m,n)
        elif typ == 'k':
            if n == 1 or m == 1:
                maxAns = max(n,m)
            elif n==2 or m == 2:
                l = max(n,m)
                localAns = 0
                localAns = (l+1)//4
                localAns*=2
                if l%4 == 1 or l%4 == 2:
                    localAns += l%4
                maxAns = localAns * 2
            else:
                maxAns = (n*m+1)//2
        elif typ == 'Q':
            maxAns = n-1 if m == n and (n==2 or m == 3) else min(m,n)
        else:
            maxAns = math.ceil(m/2)*math.ceil(n/2)
        print(maxAns)
main()