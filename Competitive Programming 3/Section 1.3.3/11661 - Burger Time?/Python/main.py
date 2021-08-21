def main():
    while True:
        l=int(input())
        if l == 0:
            break
        r,d,minDist=-1,-1,l
        s = input()
        for i,c in enumerate(s):
            if c == 'R' or c == 'Z':
                r = i
            if c == 'D' or c =='Z':
                d = i
            if r!=-1 and d!=-1:
                minDist = min(minDist,abs(r-d))
        print(minDist)
main()