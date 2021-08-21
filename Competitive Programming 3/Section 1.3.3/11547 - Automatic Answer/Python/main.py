def main():
    t = int(input())
    for _ in range(0,t):
        n = int(input())
        print(abs((n*63+7492)*5 - 498) // 10 % 10)
main()