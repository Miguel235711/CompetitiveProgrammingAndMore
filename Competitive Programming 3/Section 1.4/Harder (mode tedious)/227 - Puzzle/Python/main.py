grid,iE,jE=[['\0' for _ in range(5)] for _ in range(5)],int(),int()
getAdjacent={
    'L':[0,-1],
    'R':[0,1],
    'B':[1,0],
    'A':[-1,0]
}
def valid(i,j):
    return i>-1 and j>-1 and i<5 and j<5
def successfull(command):
    global iE,jE
    adjMov=getAdjacent.get(command)
    if not adjMov:
        return False
    newIE,newJE=iE+adjMov[0],jE+adjMov[1]
    if not valid(newIE,newJE):
        return False
    #make move
    grid[iE][jE]=grid[newIE][newJE]
    grid[newIE][newJE]=' '
    iE,jE=newIE,newJE
    return True
def main():
    global iE,jE
    cs=1
    while(True):
        for i in range(5):
            line=input()
            if line[0]=='Z':
                return
            for j in range(5):
                grid[i][j]=line[j]
                if grid[i][j]==' ':
                    iE,jE=i,j
        print(('\n' if cs>1 else '')+'Puzzle #'+str(cs)+':')
        possible,moreCommands=True,True
        while(moreCommands):
            for command in input():
                if command=='0':
                    moreCommands=False
                    break
                elif possible and not successfull(command):
                    possible=False
                    print("This puzzle has no final configuration.")
        if possible:
            for row in grid:
                for i,el in enumerate(row):
                    print((' ' if i>0 else '')+el,end='')
                print()
        cs+=1
main()