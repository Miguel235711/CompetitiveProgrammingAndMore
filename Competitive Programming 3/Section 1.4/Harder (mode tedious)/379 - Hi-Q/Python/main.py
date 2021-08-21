from sys import stdin
grid=[
    [0,0,1,2,3,0,0],
    [0,0,4,5,6,0,0],
    [7,8,9,10,11,12,13],
    [14,15,16,17,18,19,20],
    [21,22,23,24,25,26,27],
    [0,0,28,29,30,0,0],
    [0,0,31,32,33,0,0]
]
movs=[[1,0],[0,1],[-1,0],[0,-1]]
class coord:
    def __init__(self,i,j):
        self.i=i
        self.j=j
def getCoord(x):
    i,j=(x-28)//3+5,(x-1)%3+2
    if 7<=x and x<=27:
        i,j=x//7+1,x%7
    elif 1<=x and x <=6:
        i,j=(x-1)//3,(x-1)%3+2
    return coord(i,j)
def inside(i,j):
    return i>-1 and j>-1 and i<7 and j<7 and grid[i][j]
def visited(i,j,vis):
    return inside(i,j)and vis[i][j]
def free(i,j,vis):
    return inside(i,j)and not vis[i][j]
def main():
    print("HI Q OUTPUT")
    vis = [[False]*7 for _ in range(7)]
    x,sum=0,0
    input()
    for line in stdin:
        for i,x in enumerate(map(int,line.split())):
            if x==0:#end of case
                #try to make k movements
                origX,intermediary=0,0
                while 1:
                    maxTarget=-1
                    for i in range(7):
                        for j in range(7):
                            if vis[i][j]:
                                for mov in movs:
                                    if visited(i+mov[0],j+mov[1],vis) and free(i+mov[0]*2,j+mov[1]*2,vis):
                                        target = grid[i+mov[0]*2][j+mov[1]*2]
                                        if target > maxTarget or (target==maxTarget and grid[i][j]>origX):
                                            origX=grid[i][j]
                                            maxTarget=target
                                            intermediary=grid[i+mov[0]][j+mov[1]]
                    if maxTarget!=-1:
                        targetC,origC,interC=getCoord(maxTarget),getCoord(origX),getCoord(intermediary)
                        vis[targetC.i][targetC.j]=True
                        vis[origC.i][origC.j]=vis[interC.i][interC.j]=False
                        sum+=-origX-intermediary+maxTarget
                    else:
                        break
                print(sum)
                sum=0
                vis = [[False]*7 for _ in range(7)]
            else:
                sum+=x
                c = getCoord(x)
                vis[c.i][c.j]=True
    print('END OF OUTPUT')
main()