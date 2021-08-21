aux,mapMov=[0]*4,{"south":(0,-1),"north":(0,1),"east":(1,-1),"west":(1,1)}
def minusOne(i):
    if i==0:
        return 3
    return i-1
def plusOne(i):
    return (i+1)%4
def One(i,dif):
    if dif==1:
        return plusOne(i)
    return minusOne(i)
def main():
    while True:
        n=int(input())
        if n==0:
            break
        groups=[[6,2,1,5],[6,3,1,4]]
        for _ in range(n):
            com = mapMov[input()]
            for i in range(4):
                aux[i]=groups[com[0]][One(i,com[1])]
            groups[com[0]]=aux.copy()
            groups[1-com[0]][0]=groups[com[0]][0]
            groups[1-com[0]][2]=groups[com[0]][2]
        print(groups[0][2])
main()