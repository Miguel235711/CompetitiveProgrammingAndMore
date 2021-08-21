def main():
    t = int(input())
    for _ in range(0,t):
        _ = int(input())
        numbers = map(int,input().split())
        minimum,maximum = 99,0
        for number in numbers:
            minimum = min(number,minimum)
            maximum = max(number,maximum)
        print(maximum - minimum + maximum - minimum)
main()