def main():
    while True:
        B,N = map(int,input().split())
        if B == 0 and N == 0 :
            return
        reserve = list(map(int,input().split()))
        for _ in range(0,N):
            a,b,c = map(int,input().split())
            reserve[a-1]-=c
            reserve[b-1]+=c
        ans = 'S'
        for r in reserve :
            if r < 0 :
                ans = 'N'
                break
        print(ans)
main()