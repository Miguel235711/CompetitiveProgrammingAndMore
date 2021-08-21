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
grid=[['\0' for i in range(12)] for j in range(12)]
def attacks(i,j,conf,objective):
    for mov in movs[conf.movIndex]:
        iN,jN = i + mov[0],j+mov[1]
        while grid[iN][jN] == '.':
            if not conf.isN:
                break
            iN+= mov[0]
            jN+= mov[1]
        if grid[iN][jN] == objective:
            return True 
    return False
def solve():
    for i in range(2,10):
        for j in range(2,10):
            if grid[i][j]!='.':
                objective = 'K' if str.islower(grid[i][j]) else 'k'
                piece = str.lower(grid[i][j]) if grid[i][j]!='p' and grid[i][j] != 'P' else grid[i][j]
                if attacks(i,j,getMovRow[piece],objective):
                    return ("white" if objective=='K' else "black") + " king is in check."
    return "no king is in check."
def main():
    cs=1
    while True:
        differentFromPoint = False
        for i in range(2,10):
            line = input()
            for j in range(2,10):
                grid[i][j] = line[j-2]
                if grid[i][j]!='.':
                    differentFromPoint=True
        if not differentFromPoint:
            break
        print("Game #"+str(cs)+": "+solve())
        input()              
        cs+=1
main()