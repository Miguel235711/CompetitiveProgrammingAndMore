def main():
    t = int(input())
    for cs in range(0,t):
        input()
        if(cs>0):
            print()
        n = int(input())
        y1,y2 = map(int,input().split())
        dif = y1-y2
        ans = "yes"
        for _ in range(1,n):
            y1,y2=map(int,input().split())
            if(y1-y2!=dif):
                ans="no"
        print(ans)
main()