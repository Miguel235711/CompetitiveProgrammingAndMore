def operation(a):
    a-=2
    return -(-a // 3) # -2 / 3 = +1.00 
def main():
    t = int(input())
    for _ in range(0,t):
        n,m=map(int,input().split())
        print(operation(n)*operation(m))
main()