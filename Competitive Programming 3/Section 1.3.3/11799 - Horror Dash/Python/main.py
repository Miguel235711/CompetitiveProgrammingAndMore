def main():
    t = int(input())
    for cs,_ in enumerate(range(0,t),1):
        numbers = map(int,input().split()[1:])
        maxi = 1
        for num in numbers :
            maxi = max(maxi,num)
        print("Case "+str(cs)+": "+str(maxi))
main()