def main():
    t = int(input())
    for cs in range(0,t):
        nums = list(map(int,input().split()))
        nums.sort()
        print("Case "+str(cs+1)+": "+str(nums[1]))
main()