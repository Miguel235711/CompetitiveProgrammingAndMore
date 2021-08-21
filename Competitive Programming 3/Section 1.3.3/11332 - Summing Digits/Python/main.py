def sumDigits(x):
    ans = 0 
    while x>0:
        ans+=x%10
        x//=10
    return ans
def main():
    while True:
        n = int(input())
        if n==0:
            break
        while n > 9 :
            n = sumDigits(n)
        print(n)
main()