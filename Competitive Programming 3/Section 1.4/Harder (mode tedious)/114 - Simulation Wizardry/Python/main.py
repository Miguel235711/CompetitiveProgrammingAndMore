class bumper:
    def __init__(self,val,cost):
        self.val,self.cost=val,cost
movs=[[0,1],[1,0],[0,-1],[-1,0]]
n,m,costWall=int(),int(),int()
def turnRight(dire):
    return 3 if dire==0 else dire-1
def isWall(x,y):
    return x==0 or y==0 or x==m-1 or y==n-1
def simulation(x,y,dire,life,grid):
    ans=0
    life-=1
    while life > 0:
        #move
        y+=movs[dire][0]
        x+=movs[dire][1]
        isW = isWall(x,y)
        if isW or grid[y][x]:
            if isW:
                life-=costWall
            else:
                ans+=grid[y][x].val
                life-=grid[y][x].cost
            y-=movs[dire][0]
            x-=movs[dire][1]
            dire=turnRight(dire)
        life-=1
    return ans
def main():
    global m,n,costWall
    m,n=map(int,input().split())
    costWall,ans=int(input()),0
    p=int(input())
    grid = [[None for _ in range(m)] for _ in range(n)]
    for _ in range(p):
        x,y,val,cost=map(int,input().split())
        grid[y-1][x-1]=bumper(val,cost)
    while True:
        try:
            x,y,dire,life=map(int,input().split())
            subAns=simulation(x-1,y-1,dire,life,grid)
            ans+=subAns
            print(subAns)
        except:
            break
    print(ans)
main()