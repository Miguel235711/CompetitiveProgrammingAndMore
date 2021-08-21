movs=[[1,0],[0,1],[-1,0],[0,-1],[1,1],[-1,-1],[-1,1],[1,-1]]
def inLimit(i,j):
    return i>-1 and j>-1 and i < 8 and j < 8
def calcDif(i1,i2,j1,j2):
    return max(abs(j2-j1),abs(i2-i1))
def possibleLimitCoordinate(grid,mov,i,j,currentPlayer):# we are sure that i,j is empty when calling this function
    iN,jN=i+mov[0],j+mov[1]
    nextP=nextPlayer(currentPlayer)
    while inLimit(iN,jN) and grid[iN][jN]==nextP:
        iN+=mov[0]
        jN+=mov[1]
    if inLimit(iN,jN) and grid[iN][jN]==currentPlayer and calcDif(i,iN,j,jN)>1:
        return (iN,jN)
    return None
def listPossibleMoves(currentPlayer,grid):
    atLeastOne=False
    for i in range(8):
        for j in range(8):
            if grid[i][j]=='-':
                for mov in movs:
                    if possibleLimitCoordinate(grid,mov,i,j,currentPlayer):
                        print((' ' if atLeastOne else '')+('('+str(i+1)+','+str(j+1)+')'),end='')
                        atLeastOne=True
                        break
    print('' if atLeastOne else 'No legal move.')
class brack:
    def __init__(self,mov,times):
        self.mov=mov
        self.times=times
def getBracketed(currentPlayer,grid,i,j):
    bracketed=[]
    for mov in movs:
        limitCoord=possibleLimitCoordinate(grid,mov,i,j,currentPlayer)
        if limitCoord!=None:
            dif=calcDif(i,limitCoord[0],j,limitCoord[1])-1
            bracketed.append(brack(mov,dif))
    return bracketed
def nextPlayer(currentPlayer):
    return 'W' if currentPlayer=='B' else 'B'
def makeMoveAndPrintPieceNumbers(i,j,currentPlayer,grid,bracketed):
    grid[i][j]=currentPlayer
    #bracket required
    for bracket in bracketed:
        subI,subJ=i,j
        for _ in range(bracket.times):
            subI+=bracket.mov[0]
            subJ+=bracket.mov[1]
            grid[subI][subJ]=currentPlayer
    #count
    black,white=0,0
    for row in grid:
        for val in row:
            if val=='W':
                white+=1
            elif val=='B':
                black+=1
    print('Black - '+(' ' if black<10 else '')+str(black)+' White - '+(' ' if white<10 else '')+str(white))
def main():
    t = int(input())
    for cs in range(t):
        if cs>0:
            print()
        grid=[]
        for i in range(8):
            grid.append(list(input()))
        currentPlayer = input()
        while True:
            command=input()
            if command[0]=='L':
                listPossibleMoves(currentPlayer,grid)
            elif command[0]=='M':
                i,j=ord(command[1])-ord('0')-1,ord(command[2])-ord('0')-1
                bracketed=getBracketed(currentPlayer,grid,i,j)
                if bracketed==[]:
                    currentPlayer=nextPlayer(currentPlayer)
                    bracketed=getBracketed(currentPlayer,grid,i,j)
                makeMoveAndPrintPieceNumbers(i,j,currentPlayer,grid,bracketed)
                currentPlayer=nextPlayer(currentPlayer)
            else:#printgrid
                for row in grid:
                    for val in row:
                        print(val,end='')
                    print()
                break           
main()