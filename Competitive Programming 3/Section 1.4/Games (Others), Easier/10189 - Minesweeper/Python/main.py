movs=[[1,0],[0,1],[-1,0],[0,-1],[1,1],[-1,-1],[-1,1],[1,-1]]
def main():
    cs=1
    while True:
        n,m=map(int,input().split())
        if n==0:
            break
        if cs > 1:
            print()
        print('Field #'+str(cs)+':')
        field = [['\0' for _ in range(m+2)] for _ in range(n+2)]
        for i in range(1,n+1):
            for j,el in enumerate(input(),1):
                field[i][j]='0' if el=='.' else '1'
        for i in range(1,n+1):
            for j in range(1,m+1):
                ans = ord('*')
                if field[i][j]!='1':
                    ans=ord('0')
                    for mov in movs:
                        if field[i+mov[0]][j+mov[1]]!='\0':
                            ans+=ord(field[i+mov[0]][j+mov[1]])-ord('0')
                print(chr(ans),end='')
            print()
        cs+=1
main()