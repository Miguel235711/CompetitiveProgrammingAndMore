from sys import stdin

def main():
    for line in stdin:
        a,b = map(int,line.split(' '))
        print(a+b)
main()