from copy import deepcopy

difOutside,difInside,begOutside,begInside=[1,1,-1,-1],[1,-1,1,-1],[],[]
visitedGrids=[] #0 empty and 1 used
def toggle(i,j,N):
    #copy last
    if visitedGrids:
        visitedGrids.append(deepcopy(visitedGrids[-1]))
    else:
        visitedGrids.append([[0 for _ in range(N)] for _ in range(N)])
    #invert
    visitedGrids[-1][i][j]=1 - visitedGrids[-1][i][j]
def enumerate2(xs, start=0, step=1):
    for x in xs:
        yield (start, x)
        start += step
def areEqual(gridNormal,gridEspecial,N,mov):
    for outside,i in enumerate2(range(N),begOutside[mov],difOutside[mov]):
        for inside,j in enumerate2(range(N),begInside[mov],difInside[mov]):
            one,two=outside,inside
            if mov==1 or mov==2:
                one,two=two,one
            if gridNormal[i][j]!=gridEspecial[one][two]:
                return False
    return True
def loses(N):
    for i in range(len(visitedGrids)-1):
        for mov in range(4):
            if areEqual(visitedGrids[i],visitedGrids[-1],N,mov):
                return True
    return False
def main():
    while True:
        N=int(input())
        if N==0:
            return
        global begOutside,begInside,visitedGrids
        begOutside,begInside,visitedGrids=[0,0,N-1,N-1],[0,N-1,0,N-1],[]
        draw=True
        for t in range(N*2):
            i,j=[int(x)-1 for i,x in enumerate(input().split()) if i!=2 ]
            if draw:
                toggle(i,j,N)
                if loses(N):
                    print('Player '+str(2-(t&1))+' wins on move '+str(t+1))
                    draw=False
        if draw:
            print('Draw')
main()