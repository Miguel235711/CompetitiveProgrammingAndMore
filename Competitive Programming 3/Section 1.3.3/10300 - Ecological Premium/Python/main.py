def main():
    n = int(input())
    for _ in range(0,n):
        ans = 0
        farmers = int(input())
        for _ in range(0,farmers):
            sz,animals,friendliness = map(int,input().split())
            ans += sz * friendliness
        print(ans)
main()