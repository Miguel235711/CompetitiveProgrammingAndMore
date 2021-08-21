from sys import stdin

def main():
    cs = 1
    for line in stdin:
        a,b = map(int,line.split(' '))
        if(cs!=1):
            print()
        print("Case "+str(cs)+":",a+b)
        cs+=1
main()