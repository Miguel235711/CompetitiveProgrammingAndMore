from enum import Enum
movs=[1,-1,8,-8]
def colMov(a,b):
    return a//8==b//8
def getInc(Q,newQ):
    inc=0
    if (newQ-Q) %8 == 0:
        inc = 8
    elif colMov(Q,newQ):
        inc = 1
    return inc
def validMov(Q,newQ,K):
    if Q > newQ:
        Q,newQ=newQ,Q
    inc = getInc(Q,newQ)
    if inc == 0:
        return False
    while Q<=newQ:
        if Q==K:
            return False
        Q+=inc
    return True
def reachesPlaceOfOther(newQ,K):
    return newQ==K-8 or newQ == K+8 or (colMov(K,K+1)and newQ==K+1) or (colMov(K,K-1)and newQ==K-1)
def insideMap(p):
    return -1<p and p < 64
def validKing(K,Qpositions):
    for mov in movs:
        if insideMap(K+mov):
            possible = True
            for Qposition in Qpositions:
                if K+mov == Qposition:
                    possible=False
                    break
            if possible:
                return True
    return False
mapToAns=["Illegal state","Illegal move","Move not allowed","Continue","Stop"]
def getQPositions(p):
    ans=[p]
    for mov in movs:
        newP = p + mov
        while (abs(mov)==8 and insideMap(newP)) or (abs(mov)==1 and colMov(newP,p)):
            ans.append(newP)
            newP+=mov
    return ans
def main():
    while(True):
        try:
            K,Q,newQ = map(int,input().split())
        except:
            break
        ans = 4
        if K == Q:
            ans = 0
        elif Q==newQ or not validMov(Q,newQ,K):
            ans = 1
        elif reachesPlaceOfOther(newQ,K):
            ans = 2
        elif validKing(K,getQPositions(newQ)):
            ans = 3
        print(mapToAns[ans])
main()