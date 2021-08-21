def main():
    while True:
        try:
            k,m = map(int,input().split())
        except:
            break
        taken = [False] * 10000
        while k:
            numbers = list(map(int,input().split()))
            k -= len(numbers)
            for num in numbers:
                taken[num]=True
        isYes=True
        for _ in range(0,m):
            tk = input().split()
            c,r = int(tk[0]),int(tk[1])
            for i in range(0,c):
                if taken[int(tk[i+2])]:
                    r-=1
            if r > 0:
                isYes = False
        print("yes" if isYes else "no")
main()