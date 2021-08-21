from sys import stdin

def main():
    input()
    for line in stdin:
        if len(line)==6:
            print(3)
        elif ((line[0]=='o' or line[1]=='n') and line[2]=='e')or(line[0]=='o'and line[1]=='n'):
            print(1)
        else:
            print(2)
main()