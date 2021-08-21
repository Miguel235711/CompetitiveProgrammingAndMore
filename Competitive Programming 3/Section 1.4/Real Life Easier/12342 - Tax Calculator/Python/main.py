from sys import maxsize
from math import ceil

taxR=[
    (18E4,0.0),
    (30E4,0.10),
    (40E4,0.15),
    (30E4,0.20),
    (maxsize,0.25)
]

def main():
    for cs in range(1,int(input())+1):
        k = int(input())
        taxSum = 0.0
        for tax in taxR:
            dif = min(k,tax[0])
            taxSum += dif * tax[1]
            k -= dif
            if not k:
                break
        print("Case {}: {}".format(cs,0 if taxSum==0 else max(2000,ceil(taxSum))))
main()