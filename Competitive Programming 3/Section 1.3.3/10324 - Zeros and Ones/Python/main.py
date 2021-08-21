acum = [0]*1000002
def same(i,j):
    if i>j:
        i,j=j,i 
    #i<=j
    rangeSum = acum[j+1] - acum[i]
    return rangeSum==0 or rangeSum == j-i+1
def main():
    cs = 1
    while True:
        try:
            for i,c in enumerate(input()):
                acum[i+1]=acum[i]+ord(c)-ord('0')
        except:
            break
        print("Case "+str(cs)+":")
        cs+=1
        n = int(input())
        for _ in range(0,n):
            i,j = map(int,input().split())
            print('Yes' if same(i,j) else 'No')
main()