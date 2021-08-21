def main():
    while True:
        try:
            A,C=map(int,input().split())
        except:
            return
        if A==0 and C == 0:
            return
        last,ans=A,0
        for current in map(int,input().split()):
            if current > last:
                ans += current - last
            last = current
        print(ans+A-last)
main()