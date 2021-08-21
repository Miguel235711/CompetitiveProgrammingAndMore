from sys import stdin
def main():
    for line in stdin:
        x1,y1,x2,y2=map(int,line.split())
        if x1==0:
            break
        print('0' if x1==x2 and y1==y2 else ('1' if x1==x2 or y1==y2 or abs(x2-x1)==abs(y2-y1) else '2'))
main()