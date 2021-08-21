def main():
    t = int(input())
    dif=[0] * 100
    for _ in range(0,t):
        n,ans = int(input()),0 
        for i in range(0,n):
            line = input()
            if line[0]=='L':
                dif[i]=-1
            elif line[0]=='R':
                dif[i]=1
            else:
                dif[i]=dif[int(line.split()[2])-1]
            ans +=dif[i]
        print(ans)
main()