def main():
    while True:
        h,m = map(int,input().split(':'))
        if h==0:
            break
        h+=m/60
        h*=30
        m*=6
        h%=360
        m%=360
        if m>h:
            m,h=h,m
        #h>m
        print('{:.3f}'.format(round(min(h-m,360-h+m),3)))
main()