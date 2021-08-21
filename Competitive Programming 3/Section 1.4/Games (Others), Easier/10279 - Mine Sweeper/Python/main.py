movs=[[1,0],[0,1],[-1,0],[0,-1],[1,1],[-1,-1],[-1,1],[1,-1]]
def getAns(c,showMines):
    if c=='*':
        return '*' if showMines else '.'
    return c
def convert(c):
    return 1 if c=='*' else 0 
def main():
    for cs in range(int(input())):
        input()
        n = int(input())
        if cs > 0:
            print()
        grid=[['.' for _ in range(n+2)] for _ in range(n+2)]
        for i in range(1,n+1):
            for j,el in enumerate(input(),1):
                grid[i][j]=el
        showMines=False
        for i in range(1,n+1):
            for j,el in enumerate(input(),1):
                if el=='x': #touched
                    if grid[i][j]=='*': #bomb
                        showMines=True
                    else: #not bomb , sum up adjacents
                        grid[i][j]=ord('0')
                        for mov in movs:
                            grid[i][j]+=convert(grid[i+mov[0]][j+mov[1]])
                        grid[i][j]=chr(grid[i][j])
        for i in range(1,n+1):
            for j in range(1,n+1):
                print(getAns(grid[i][j],showMines),end='')
            print()
main()