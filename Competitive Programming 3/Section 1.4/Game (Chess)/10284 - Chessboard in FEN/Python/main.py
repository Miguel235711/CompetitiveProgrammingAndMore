movs=[
    [[1,-1],[1,1]],#black pawn (1)
    [[-1,-1],[-1,1]],#white pawn (1)
    [[2,1],[-2,1],[2,-1],[-2,-1],[1,2],[-1,2],[1,-2],[-1,-2]],#knight (1)
    [[1,1],[-1,-1],[-1,1],[1,-1]],#bishop (1..n)
    [[1,0],[-1,0],[0,1],[0,-1]], # rook (1..n)
    [[1,1],[-1,-1],[-1,1],[1,-1],[1,0],[-1,0],[0,1],[0,-1]]#queen or king (special case [1..n and 1])
]
class Config:
    def __init__(self,movIndex,isN):
        self.movIndex=movIndex
        self.isN=isN
getMovRow = {
    'p':Config(0,False),
    'P':Config(1,False),
    'n':Config(2,False),
    'b':Config(3,True),
    'r':Config(4,True),
    'q':Config(5,True),
    'k':Config(5,False)
}
grid,used,numberUsed=[['\0' for _ in range(12)] for _ in range(12)],[],0
def initialize():
    global used,numberUsed
    used = [[False for _ in range(12)] for _ in range(12)]
    numberUsed = 0
def visitCell(i,j):
    global numberUsed
    if not used[i][j]:
        used[i][j]=True
        numberUsed+=1
def visAttacked(i,j,movRow):
    for mov in movs[movRow.movIndex]:
        iN,jN=i+mov[0],j+mov[1]
        while grid[iN][jN] == '.' :
            visitCell(iN,jN)
            if not movRow.isN:
                break
            iN+=mov[0]
            jN+=mov[1]
def main():
    while True:
        try:
            i,j=2,2
            for c in input():
                if c == '/':
                    j=2
                    i+=1
                elif str.isdigit(c):
                    for _ in range(ord(c)-ord('0')):
                        grid[i][j]='.'
                        j+=1
                else:
                    grid[i][j]=c
                    j+=1
        except:
            break
        initialize()
        for i in range(2,10):
            for j in range(2,10):
                if grid[i][j]!='.':
                    visitCell(i,j)
                    visAttacked(i,j,getMovRow[grid[i][j] if grid[i][j]=='p' or grid[i][j]=='P' else str.lower(grid[i][j])])
        print(8*8-numberUsed)
main()