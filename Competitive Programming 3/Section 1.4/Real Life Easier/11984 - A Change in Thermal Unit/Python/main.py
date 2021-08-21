
def main():
    for cs in range(1,int(input())+1):
        C,d=map(int,input().split())
        print('Case ',cs,': ','{:.2f}'.format(round(C+5*d/9,2)),sep='')
main()