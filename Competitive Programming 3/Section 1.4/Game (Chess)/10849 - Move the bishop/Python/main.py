def getColor(i,j,n):
    cell = n * i + j
    if (n&1) or not (i&1):
        return cell&1
    return 1 - (cell&1)
def sameCross(i,j,iO,jO):
    return abs(iO-i)==abs(jO-j)
def main():
    for _ in range(int(input())):
        input()
        t,n=int(input()),int(input())
        for _ in range(t):
            i,j,iO,jO = map(int,input().split())
            ans = 'no move'
            if getColor(i,j,n) == getColor(iO,jO,n):
                if i == iO and j == jO:
                    ans = "0"
                elif sameCross(i,j,iO,jO):
                    ans = "1"
                else:
                    ans = "2"
            print(ans)
main()