movs,names,grid=[[0,1],[1,0]],['Across','Down'],[]
def printAns(i,j,mov,number):
    print(' '+(' 'if number<10 else '')+str(number)+'.',end='')
    while grid[i][j]!='*':
        print(grid[i][j],end='')
        i+=mov[0]
        j+=mov[1]
    print()
def main():
    cs=1
    while True:
        try:
            r,c=map(int,input().split())
        except:
            return
        num=0
        print(('\n'if cs>1 else '')+'puzzle #'+str(cs)+':')
        global grid
        grid,numbers=[['*' for _ in range(c+2)] for _ in range(r+2)],[[0 for _ in range(c+1)] for _ in range(r+1)]
        for i in range(1,r+1):
            for j,el in enumerate(input(),1):
                grid[i][j]=el
                if grid[i][j]!='*'and(grid[i-1][j]=='*' or grid[i][j-1]=='*'):
                    num+=1
                    numbers[i][j]=num
        for mov in range(2):
            print(names[mov])
            for i in range(1,r+1):
                for j in range(1,c+1):
                    if grid[i][j]!='*' and grid[i-movs[mov][0]][j-movs[mov][1]]=='*':
                        printAns(i,j,movs[mov],numbers[i][j])
        cs+=1
main()