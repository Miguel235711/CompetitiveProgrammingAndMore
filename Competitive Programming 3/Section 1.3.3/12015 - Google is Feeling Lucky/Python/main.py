def main():
    t = int(input())
    for cs in range(1,t+1):
        pages,maximum = [],0
        for _ in range(0,10):
            line = input().split()
            vi = int(line[1])
            if maximum < vi:
                maximum = vi
                pages = []
            if maximum == vi:
                pages.append(line[0])
        print("Case #"+str(cs)+":")
        for page in pages:
            print(page)
main()