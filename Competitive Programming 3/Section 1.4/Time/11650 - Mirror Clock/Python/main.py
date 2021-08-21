def main():
    for _ in range(int(input())):
        h,m=map(int,input().split(':'))
        newH = 12 - h
        if m:
            newH-=1
        print('{:-02}:{:-02}'.format(12 if newH == 0 else 11 if newH == -1 else newH,(60-m)%60))
main()