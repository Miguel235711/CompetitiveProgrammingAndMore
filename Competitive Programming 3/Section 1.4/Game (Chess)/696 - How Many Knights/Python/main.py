def main():
    while True:
        n,m = map(int,input().split())
        maxAns = 0
        if n == 0 and m == 0:
            break
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
        print(str(maxAns)+' knights may be placed on a '+str(n)+' row '+str(m)+' column board.')
main()