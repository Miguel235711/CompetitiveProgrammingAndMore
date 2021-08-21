def main():
    t = int(input())
    print("Lumberjacks:")
    for _ in range(0,t):
        numbers = map(int,input().split())
        last = 101
        negativeDif,positiveDif = False,False
        for number in numbers:
            if last != 101:
                if number-last > 0 : 
                    positiveDif = True
                elif number-last < 0:
                    negativeDif = True
            last = number
        print("Ordered" if positiveDif^negativeDif else "Unordered")
main()