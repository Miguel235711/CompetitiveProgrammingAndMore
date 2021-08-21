def main():
    for _ in range(int(input())):
        s,d=map(int,input().split())
        s2 = int((d-s)/-2)
        s1 = s-s2
        print('impossible' if (d-s)&1 or s1<0 or s2 <0 else '{} {}'.format(s1,s2))
main()