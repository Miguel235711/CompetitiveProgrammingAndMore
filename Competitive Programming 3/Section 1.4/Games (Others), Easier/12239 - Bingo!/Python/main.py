def main():
    while True:
        N,B=map(int,input().split())
        if N==0:
            return
        arr,possible,remain=list(map(int,input().split())),[False]*N,N
        for i in range(B):
            for j in range(i+1,B):
                if not possible[abs(arr[i]-arr[j])-1]:
                    possible[abs(arr[i]-arr[j])-1]=True
                    remain-=1
        print('N'if remain else'Y')
main()