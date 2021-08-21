import sys

def main():
    while True:
        try:
            inpt = input()
        except:
            break
        n,b,h,w = map(int,inpt.split())
        minAns = sys.maxsize
        for _ in range(0,h):
            pi = int(input())
            weekCaps = map(int,input().split())
            if pi * n <= b and pi*n < minAns :
                for weekC in weekCaps:
                    if weekC >= n :
                        minAns = pi*n
                        break
        print("stay home" if minAns==sys.maxsize else minAns)
main()