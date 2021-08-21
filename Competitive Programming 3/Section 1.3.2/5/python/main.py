from sys import stdin

def main():
    for line in stdin:
        sum=0
        for x in line.split()[1:]:
            sum+=int(x)
        print(sum)
main()