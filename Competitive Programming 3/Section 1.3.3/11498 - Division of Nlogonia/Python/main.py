def main():
    while True:
        k = int(input())
        if k==0:
            break
        n,m=map(int,input().split())
        for _ in range(0,k):
            x,y = map(int,input().split())
            if x==n or y==m:
                print("divisa")
            elif y>m:
                if x < n:
                    print("NO")
                else:
                    print("NE")
            else:
                if x < n:
                    print("SO")
                else:
                    print("SE")
main()