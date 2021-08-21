def main():
    t = int(input())
    for cs in range(0,t):
        ans = "good"
        for num in map(int,input().split()):
            if(num>20):
                ans = "bad"
                break
        print("Case "+str(cs+1)+": "+str(ans))
main()